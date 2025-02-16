#include "Game.h"

#undef min
#undef max
#include <algorithm>

#include "Images.h"
#include "Palettes.h"

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
  _pos = Vector2D(pos.x * 8, pos.y * 8);
  _bubble = bubble;

  _trackOffset = 0;
  _move = nullptr;
  _moveNext = nullptr;
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

void Player::update() {
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

  if (_move) {
    if (_moveAnim->step(*this, *_move)) {
      if (_move->_dstBub != _bubble) {
        _bubble = _move->_dstBub;
      }

      _move = nullptr;
      _moveAnim = nullptr;
    }
  }
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

  int palIdx = _bubble == ObjectColor::None ? 5 : static_cast<int>(_bubble);
  gb.display.colorIndex = const_cast<Color *>(palettes[palIdx]);
  gb.display.drawImage(x0 + _pos.x, y0 + _pos.y, playerImage);
  gb.display.colorIndex = PALETTE_DEFAULT;

//  gb.display.setCursor(0, 0);
//  if (_move) {
//    gb.display.printf("%d (%d,%d)", _move->_blocked, _move->_dstPos.x, _move->_dstPos.y);
//  }
}

void Box::init(GridPos pos, ObjectColor color) {
  _pos = Vector2D(pos.x * 8, pos.y * 8);
  _color = color;
}

void Box::moveStep(Direction dir) {
  _pos.add(dirVectors[static_cast<int>(dir)]);
}

void Box::draw(int x0, int y0) {
  boxImage.setFrame(0);

  gb.display.colorIndex = const_cast<Color *>(palettes[static_cast<int>(_color)]);
  gb.display.drawImage(x0 + _pos.x, y0 + _pos.y, boxImage);
  gb.display.colorIndex = PALETTE_DEFAULT;
}

Level::Level(const LevelSpec& spec)
: _spec(spec)
, _player(*this)
{
  _player.init(spec.startPos);

  for (int i = 0; i < spec.numBoxes; i++) {
    _boxes[i].init(spec.boxes[i].pos, spec.boxes[i].color);
  }
}

Box* Level::boxAt(GridPos pos) {
  for (int i = 0; i < _spec.numBoxes; ++i ) {
    if (_boxes[i].gridPos() == pos) {
      return &_boxes[i];
    }
  }

  return nullptr;
}

ObjectColor Level::bubbleAt(GridPos pos) const {
  auto& bubbles = _spec.bubbles;

  for (int i = 0; i < _spec.numBubbles; ++i ) {
    if (bubbles[i].pos == pos) {
      return bubbles[i].color;
    }
  }

  return ObjectColor::None;
}

bool Level::isWall(GridPos pos) const {
  auto& grid = _spec.grid;

  return grid.tiles[pos.x + pos.y * grid.w] != 0;
}

void Level::update() {
  _player.update();
}

void Level::draw() {
  int x0 = 40 - _spec.grid.w * 4;
  int y0 = 32 - _spec.grid.h * 4;

  for (int y = 0; y < _spec.grid.h; ++y) {
    int rowOffset = y * _spec.grid.w;
    for (int x = 0; x < _spec.grid.w; ++x) {
      int tileIndex = _spec.grid.tiles[x + rowOffset];
      if (tileIndex > 0) {
        wallsImage.setFrame(tileIndex - 1);
        gb.display.drawImage(x0 + x * 8, y0 + y * 8, wallsImage);
      }
    }
  }

  for (int i = 0; i < _spec.numTargets; ++i) {
    auto& obj = _spec.targets[i];
    gb.display.colorIndex = const_cast<Color *>(palettes[static_cast<int>(obj.color)]);
    gb.display.drawImage(x0 + obj.pos.x * 8, y0 + obj.pos.y * 8, targetImage);
  }

  for (int i = 0; i < _spec.numBoxes; ++i) {
    _boxes[i].draw(x0, y0);
  }

  _player.draw(x0, y0);

//  if (_player.isAtGridPos()) {
//    GridPos p = _player.gridPos();
//    gb.display.printf("(%d,%d) = %d", p.x, p.y, _spec.grid.tiles[p.x + p.y * _spec.grid.w]);
//  }

  for (int i = 0; i < _spec.numBubbles; ++i) {
    auto& obj = _spec.bubbles[i];
    gb.display.colorIndex = const_cast<Color *>(palettes[static_cast<int>(obj.color)]);
    gb.display.drawImage(x0 + obj.pos.x * 8, y0 + obj.pos.y * 8, bubbleImage);
  }
  gb.display.colorIndex = PALETTE_DEFAULT;
}
