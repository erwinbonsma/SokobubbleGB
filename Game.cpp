#include "Game.h"

#undef min
#undef max
#include <algorithm>

const Vector2D dirVectors[4] = {
  Vector2D(0, -1), Vector2D(1, 0), Vector2D(0, 1), Vector2D(-1, 0)
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

  if (_step <= 2) {
    player.moveForward(move.dir());
    return false;
  }

  if (_step <= 10) {
    player.moveForward(move.dir());
    move.pushedBox()->moveStep(move.dir());
    return false;
  }

  player.moveBackward(move.dir());
  return _step == 12;
}

void Player::init(GridPos pos, ObjectColor bubble) {
  _pos = Vector2D(pos.x * 8, pos.y * 8);
  _bubble = bubble;
}

Move* Player::getMove(Direction dir) {
  // Pick item from pool that is not currently used
  Move* mov = (_move == _movePool) ? _movePool + 1 : _movePool;
  assertTrue(mov != _move);
  assertTrue(mov != _moveNext);

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

  move->_blocked = checkBlocked(move);
  if (move->_blocked) {
    move->_dstPos = move->_srcPos;
    move->_dstBub = move->_srcBub;
  } else {
    move->_dstPos = move->_srcPos + dirVectors[static_cast<int>(move->_dir)];
    move->_dstBub = _level.bubbleAt(move->_dstPos);
    if (move->_dstBub == ObjectColor::None) {
      move->_dstBub = move->_srcBub;
    }
  }

  return move;
}

MoveAnimation* Player::startMove(Move* move) {
  _move = move;

  MoveAnimation* anim = nullptr;
  if (move->_blocked) {
    anim = &_blockedMoveAnim;
  } else if (move->_pushedBox) {
    anim = &_pushMoveAnim;
  } else {
    anim = &_plainMoveAnim;
  }

  anim->init();

  if (!move->_blocked) {
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

  return anim;
}

void Player::update() {
  Move* nextMove = nullptr;
  if (gb.buttons.pressed(BUTTON_UP)) {
    nextMove = getMove(Direction::Up);
  } else if (gb.buttons.pressed(BUTTON_RIGHT)) {
    nextMove = getMove(Direction::Right);
  } else if (gb.buttons.pressed(BUTTON_DOWN)) {
    nextMove = getMove(Direction::Down);
  } else if (gb.buttons.pressed(BUTTON_LEFT)) {
    nextMove = getMove(Direction::Left);
  }

  if (nextMove) {
    _moveNext = checkMove(nextMove);
  }

  if (_moveNext) {
    if (!_move) {
      _moveAnim = startMove(_moveNext);
      _moveNext = nullptr;
    }
  }

  if (_move) {
    if (_moveAnim->step(*this, *_move)) {
      _move = nullptr;
      _moveAnim = nullptr;
    }
  }
}

void Player::rotateTowards(int rotation) {
  int deltaRot = rotation - _rotation;
  if (deltaRot > 180) {
    deltaRot -= 360;
  } else if (deltaRot <= -180) {
    deltaRot += 360;
  }

  deltaRot = std::min(std::max(deltaRot, -10), 10);

  _rotation += deltaRot;
}

void Player::moveForward(Direction dir) {
  auto v = dirVectors[static_cast<int>(dir)];

  _pos.add(v);
  _frameIndex = (_frameIndex + v.x + v.y + 3) % 3;
}

void Player::moveBackward(Direction dir) {
  auto v = dirVectors[static_cast<int>(dir)];

  _pos.sub(v);
  _frameIndex = (_frameIndex - v.x - v.y + 3) % 3;
}

void Box::init(GridPos pos, ObjectColor color) {
  _pos = Vector2D(pos.x * 8, pos.y * 8);
  _color = color;
}

Level::Level(LevelSpec& spec)
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

ObjectColor Level::bubbleAt(GridPos pos) {
  auto& bubbles = _spec.bubbles;

  for (int i = 0; i < _spec.numBubbles; ++i ) {
    if (bubbles[i].pos == pos) {
      return bubbles[i].color;
    }
  }

  return ObjectColor::None;
}

bool Level::isWall(GridPos pos) {
  auto& grid = _spec.grid;

  return grid.tiles[pos.x + pos.y * grid.w] != 0;
}
