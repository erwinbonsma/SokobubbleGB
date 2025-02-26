#include "Game.h"

#undef min
#undef max
#include <algorithm>

#include "Animations.h"
#include "Images.h"
#include "ProgressTracker.h"
#include "SoundFx.h"

Game game;
int maxCpuLoad = 0;

const Vector2D dirVectors[4] = {
  Vector2D(0, -1), Vector2D(1, 0), Vector2D(0, 1), Vector2D(-1, 0)
};

const std::pair<Button, Direction> buttonMap[] = {
  { BUTTON_UP, Direction::Up },
  { BUTTON_RIGHT, Direction::Right },
  { BUTTON_DOWN, Direction::Down },
  { BUTTON_LEFT, Direction::Left },
};

void Move::init(Direction dir) {
  _dir = dir;

  // Set to "uninitialized" values
  _srcPos = GridPos(-1, -1);
  _dstPos = GridPos(-1, -1);
  _dstBub = ObjectColor::Any;
  _blocked = 0;
  _pushedBox = nullptr;
}

bool MoveAnimation::tryRotate(Player& player, Move& move) {
  int tgtRotation = rotationAngle(move.dir());
  if (player.rotation() == tgtRotation) {
    return false;
  }

  player.rotateTowards(tgtRotation);

  return true;
}

bool PlainMoveAnimation::step(Player& player, Move& move) {
  if (tryRotate(player, move)) {
    return false;
  }

  player.moveForward(move.dir());

  return player.isAtGridPos();
}

bool BlockedMoveAnimation::step(Player& player, Move& move) {
  if (tryRotate(player, move)) {
    return false;
  }

  _step++;
  if (_step <= move.blockedDistance()) {
    player.moveForward(move.dir());

    if (_step == move.blockedDistance()) {
      gb.sound.fx(noCanDoSfx);
    }

    return false;
  }

  player.moveBackward(move.dir());
  return _step == 2 * move.blockedDistance();
}

bool PushMoveAnimation::step(Player& player, Move& move) {
  if (tryRotate(player, move)) {
    return false;
  }

  _step++;

  if (_step == 1 && !player.isAtGridPos()) {
    // Continue ongoing push
    _step = 3;
  }

  if (_step <= 2) {
    player.moveForward(move.dir());

    if (_step == 2) {
      gb.sound.fx(pushStartSfx);
    }

    return false;
  }

  if (_step <= 10) {
    player.moveForward(move.dir());
    move.pushedBox()->moveStep(move.dir());

    if (_step == 10 && player.pushContinues()) {
      player.startNextMove();
    }

    return false;
  }

  player.moveBackward(move.dir());
  return _step == 12;
}

void Player::init(GridPos pos, ObjectColor bubble) {
  Moveable::init(pos);

  _bubble = bubble;
  _rotation = 0;

  _trackOffset = 0;
  _move = nullptr;
  _moveNext = nullptr;

  // Ignore button A being pressed until it is first released.
  _retryCount = -1;

  _frozen = false;
}

Move* Player::getMove(Direction dir) {
  // Pick item from pool that is not currently used
  Move* mov = (_move == _movePool) ? _movePool + 1 : _movePool;

  mov->init(dir);

  return mov;
}

int Player::checkBlocked(Move* move) {
  if (_level.isWall(move->_dstPos)) {
    return 1;
  }

  Box* box = _level.boxAt(move->_dstPos);
  if (!box && _move && _move->_dir == move->_dir) {
    // Pushed box is not (always) found by boxAt
    box = _move->_pushedBox;
  }

  if (!box) {
    return 0;
  }

  if (box->color() != move->_srcBub) {
    return 2;
  }

  GridPos nxtPos = move->_dstPos + dirVectors[static_cast<int>(move->_dir)];
  if (_level.isWall(nxtPos) || _level.boxAt(nxtPos)) {
    return 2;
  }

  move->_pushedBox = box;
  return 0;
}

Move* Player::checkMove(Move* move) {
  if (_move) {
    move->_srcPos = _move->_dstPos;
    move->_srcBub = _move->_dstBub;
  } else {
    move->_srcPos = Vector2D(_pos.x / 8, _pos.y / 8);
    move->_srcBub = _bubble;
  }

  move->_dstPos = move->_srcPos + dirVectors[static_cast<int>(move->_dir)];
  move->_dstBub = _level.bubbleAt(move->_dstPos);

  move->_blocked = checkBlocked(move);
  if (move->_blocked) {
    move->_dstPos = move->_srcPos;
    move->_dstBub = move->_srcBub;
  } else {
    if (move->_dstBub == ObjectColor::None) {
      move->_dstBub = move->_srcBub;
    }
  }

  return move;
}

void Player::startNextMove() {
  _move = _moveNext;
  _moveNext = nullptr;

  if (_move->_blocked) {
    _moveAnim = &_blockedMoveAnim;
  } else if (_move->_pushedBox) {
    _moveAnim = &_pushMoveAnim;
  } else {
    _moveAnim = &_plainMoveAnim;
  }

  _moveAnim->init();

  if (!_move->_blocked) {
    _level.incMoveCount();
  }

  int targetRotation = rotationAngle(_move->_dir);
  if (
    _rotation != targetRotation &&
    targetRotation % 180 == _rotation % 180
  ) {
    // Do not animate 180 degree turn
    _rotation = targetRotation;
  }
}

void Player::rotateTowards(int rotation) {
  int deltaRot = rotation - _rotation;
  if (deltaRot > 180) {
    deltaRot -= 360;
  } else if (deltaRot <= -180) {
    deltaRot += 360;
  }
  assertTrue(deltaRot <= 180);
  assertTrue(deltaRot > -180);

  deltaRot = std::min(std::max(deltaRot, -10), 10);

  _rotation = (_rotation + deltaRot + 360) % 360;
}

void Player::moveForward(Direction dir) {
  auto v = dirVectors[static_cast<int>(dir)];

  _pos.add(v);
  _trackOffset = (_trackOffset + v.x + v.y + 3) % 3;
}

void Player::moveBackward(Direction dir) {
  auto v = dirVectors[static_cast<int>(dir)];

  _pos.sub(v);
  _trackOffset = (_trackOffset - v.x - v.y + 3) % 3;
}


bool Player::pushContinues() {
  assertTrue(_move && _move->_pushedBox);

  // Use fact that "pushedBox" is only set when move is not blocked
  return (_moveNext && _moveNext->_pushedBox == _move->_pushedBox);
}

void Player::freeze() {
  _frozen = true;
  _moveNext = nullptr;
}

bool Player::handleMoveInput() {
  for (auto& pair : buttonMap) {
    if (
      gb.buttons.pressed(pair.first)
      || (
        gb.buttons.repeat(pair.first, 0)
        && (!_moveNext || _moveNextExpiry <= 2)
      )
    ) {
      _moveNext = checkMove(getMove(pair.second));

      // Button held schedules a short-lived move request.
      // This allows a continuous move, but should prevent that a
      // move goes on one step too many.
      _moveNextExpiry = gb.buttons.pressed(pair.first) ? 99 : 2;
    }
  }

  if (gb.buttons.repeat(BUTTON_A, 0)) {
    if (_retryCount != -1 && ++_retryCount > 30) {
      _retryCount = 0; // Disable retry-drawing mode
      return false;
    }
  } else {
    _retryCount = 0;
  }

  if (_moveNext) {
    if (!_move) {
      startNextMove();
    } else {
      if (--_moveNextExpiry == 0) {
        // Remove short-lived move request
        _moveNext = nullptr;
      }
    }
  }

  return true;
}

bool Player::update() {
  if (!_frozen && !handleMoveInput()) {
    return false;
  }

  if (_move) {
    if (_moveAnim->step(*this, *_move)) {
      if (_move->_dstBub != _bubble) {
        _bubble = _move->_dstBub;

        gb.sound.fx(bubbleChangeSfx);
        _level.lights().changeColor(_bubble);
      }

      _move = nullptr;
      _moveAnim = nullptr;
    }
  }

  return true;
}

void Player::draw(int x0, int y0) {
  int sector = (_rotation % 90 + 15) / 30;
  int orientation = (_rotation % 180) / 90;

  if (sector == 0 || sector == 3) {
    // Sprite is horizontal or vertical
    playerImage.setFrame(((orientation + sector / 3) % 2) * 5 + _trackOffset);
  } else {
    playerImage.setFrame(orientation * 5 + sector + 2);
  }
  gb.display.drawImage(x0 + _pos.x, y0 + _pos.y, playerImage);

  int palIdx;
  if (_retryCount > 0) {
    palIdx = 1 + (_retryCount / 2) % 4;
  } else {
    palIdx = static_cast<int>(_bubble);
  }

  cockpitImage.setFrame(palIdx);
  gb.display.drawImage(x0 + _pos.x + 3, y0 + _pos.y + 3, cockpitImage);
}

void Box::init(GridPos pos, ObjectColor color) {
  Moveable::init(pos);

  _color = color;
}

void Box::moveStep(Direction dir) {
  _pos.add(dirVectors[static_cast<int>(dir)]);
}

void Box::draw(int x0, int y0, ObjectColor bubbleColor) {
  boxImage.setFrame(static_cast<int>(_color) * 2 + (bubbleColor != _color) - 2);
  gb.display.drawImage(x0 + _pos.x + 1, y0 + _pos.y + 1, boxImage);
}

void Level::init(int levelIndex) {
  _levelIndex = levelIndex;
  _spec = &levels[levelIndex];
  _bestMoveCount = progressTracker.getLevelMinMoves(levelIndex);

  drawFixed(_fixedImage);

  start();
}

void Level::start() {
  _player.init(_spec->player.pos, _spec->player.color);

  for (int i = 0; i < _spec->numBoxes; i++) {
    _boxes[i].init(_spec->boxes[i].pos, _spec->boxes[i].color);
  }

  _moveCount = 0;
  _boxCount = 0;
}

Box* Level::boxAt(GridPos pos) {
  for (int i = 0; i < _spec->numBoxes; ++i ) {
    if (_boxes[i].gridPos() == pos) {
      return &_boxes[i];
    }
  }

  return nullptr;
}

ObjectColor Level::bubbleAt(GridPos pos) const {
  auto& bubbles = _spec->bubbles;

  for (int i = 0; i < _spec->numBubbles; ++i ) {
    if (bubbles[i].pos == pos) {
      return bubbles[i].color;
    }
  }

  return ObjectColor::None;
}

ObjectColor Level::targetAt(GridPos pos) const {
  // Quickly look if there's a target
  auto& grid = _spec->grid;
  if (grid.tiles[pos.x + pos.y * grid.w] != -1) {
    return ObjectColor::None;
  }

  // If so, find its color (TODO: also store in grid)
  auto& targets = _spec->targets;
  for (int i = 0; i < _spec->numTargets; ++i ) {
    if (targets[i].pos == pos) {
      return targets[i].color;
    }
  }

  assertTrue(false);
}

bool Level::isWall(GridPos pos) const {
  auto& grid = _spec->grid;

  return grid.tiles[pos.x + pos.y * grid.w] > 0;
}

bool Level::isDone() {
  int boxCount = 0;

  for (int i = 0; i < _spec->numBoxes; ++i ) {
    auto& box = _boxes[i];

    if (box.isAtGridPos()) {
      ObjectColor targetColor = targetAt(box.gridPos());

      if (targetColor == box.color() || targetColor == ObjectColor::Any) {
        boxCount++;
      }
    }
  }

  if (boxCount != _boxCount) {
    _boxCount = boxCount;
    gb.sound.fx(boxPlacedSfx);
  }

  return _boxCount == _spec->numBoxes;
}

Animation* Level::update() {
  _lights.update();

  if (!_player.update()) {
    retryAnim.init();
    return &retryAnim;
  }

  if (isDone()) {
    _player.freeze();

    if (!_player.isMoving()) {
      levelDoneAnim.init(&_lights);
      return &levelDoneAnim;
    } else {
      // Wait for ongoing move to finish
    }
  }

  return nullptr;
}

void Level::drawName(int xOffset, int yOffset) {
  char buf[12];
  snprintf(buf, sizeof(buf), "%d.%s", _levelIndex + 1, _spec->name);

  int w = strlen(buf);
  int x = 32 - w * 2 + xOffset;
  int y = 2 + yOffset;

  gb.display.setColor(BLUE);
  gb.display.fillRoundRect(x - 2, y, w * 4 + 4, 7, 1);

  gb.display.setTextWrap(false);
  gb.display.setCursor(x, y + 1);
  gb.display.setColor(DARKBLUE);
  gb.display.print(buf);
}

void Level::drawInfoPanelText() {
  int x0 = 67;
  gb.display.setColor(GRAY);

  gb.display.setCursor(x0, 8);
  gb.display.printf("%3d", _levelIndex + 1);

  gb.display.setCursor(x0, 22);
  gb.display.printf("%3d", _moveCount);

  gb.display.setCursor(x0, 36);
  if (_bestMoveCount != 0) {
    gb.display.printf("%3d", _bestMoveCount);
  } else {
    gb.display.print("  -");
  }

  int cpuLoad = gb.getCpuLoad();
  gb.display.setCursor(x0, 50);
  gb.display.printf("%3d", cpuLoad);
  maxCpuLoad = std::max(cpuLoad, maxCpuLoad);
  gb.display.setCursor(x0, 56);
  gb.display.printf("%3d", maxCpuLoad);

  gb.display.setColor(DARKGRAY);
  gb.display.setCursor(x0, 2);
  gb.display.print("Lev");

  gb.display.setCursor(x0, 16);
  gb.display.print("Mov");

  gb.display.setCursor(x0, 30);
  gb.display.print("Min");

  gb.display.setCursor(x0, 44);
  gb.display.print("Cpu");
}

void Level::drawFixed(Gamebuino_Meta::Graphics& g) {
  int x0 = 32 - _spec->grid.w * 4;
  int y0 = 32 - _spec->grid.h * 4;

  g.clear(BLACK);

  g.setColor(DARKGRAY);
  for (int y = 0; y < _spec->grid.h; ++y) {
    int rowOffset = y * _spec->grid.w;
    int sy = y0 + y * 8;
    for (int x = 0; x < _spec->grid.w; ++x) {
      int tileIndex = _spec->grid.tiles[x + rowOffset];
      int sx = x0 + x * 8;
      if (tileIndex > 0) {
        wallsImage.setFrame(tileIndex - 1);
        g.drawImage(sx, sy, wallsImage);
      } else if (tileIndex == 0) {
        g.fillRect(sx, sy, 8, 8);
      }
    }
  }
}

void Level::draw(int xOffset) {
  int x0 = 32 - _spec->grid.w * 4 + xOffset;
  int y0 = 32 - _spec->grid.h * 4;

  gb.display.drawImage(xOffset, 0, _fixedImage);

  for (int i = 0; i < _spec->numTargets; ++i) {
    auto& obj = _spec->targets[i];
    targetImage.setFrame(static_cast<int>(obj.color) - 1);
    gb.display.drawImage(x0 + obj.pos.x * 8, y0 + obj.pos.y * 8, targetImage);
  }

  for (int i = 0; i < _spec->numBoxes; ++i) {
    _boxes[i].draw(x0, y0, _player.bubbleColor());
  }

  _player.draw(x0, y0);

  // Clear info panel background
  gb.display.setColor(BLACK);
  fillFastVRect(64 + xOffset, 16);

  for (int i = 0; i < _spec->numBubbles; ++i) {
    auto& obj = _spec->bubbles[i];
    bubbleImage.setFrame(static_cast<int>(obj.color) - 1);
    gb.display.drawImage(x0 + obj.pos.x * 8 + 2, y0 + obj.pos.y * 8 + 2, bubbleImage);
  }

  _lights.draw();
}

void Game::initLevel(int levelIndex) {
  _levelToggle = !_levelToggle;
  level().init(levelIndex);
}

void Game::initNextLevel() {
  int nxtIndex = (level().levelIndex() + 1) % numLevels;
  initLevel(nxtIndex);
}

void Game::update() {
  if (_animation) {
    _animation = _animation->update();
  } else {
    _animation = level().update();
  }
}

void Game::draw() {
  if (_animation) {
    _animation->draw();
  } else {
    level().draw();
    level().drawInfoPanelText();
  }
}
