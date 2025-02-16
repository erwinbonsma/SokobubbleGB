#pragma once

#include "Levels.h"
#include "Utils.h"

enum class Direction : uint8_t {
  Up = 0,
  Right = 1,
  Down = 2,
  Left = 3,
};

inline int rotationAngle(Direction dir) { return static_cast<int>(dir) * 90; }

class Box;
class Player;

class Move {
  friend class Player;

  Direction _dir;
  GridPos _srcPos;
  GridPos _dstPos;

  // Is the move blocked and if so, by how much?
  // Zero when unblocked. Otherwise indicates how much pixels the
  // player can move (always at least one, as there's room around
  // the player sprite).
  int _blocked;
  Box* _pushedBox;

  ObjectColor _srcBub;
  ObjectColor _dstBub;
public:
  int blockedDistance() const { return _blocked; }
  Direction dir() const { return _dir; }
  Box* pushedBox() const { return _pushedBox; }

  void init(Direction dir);
};

class MoveAnimation {

protected:
  // Tries to rotate the player in the given direction. Return "false" when
  // no rotation was necessary.
  bool tryRotate(Player& player, Move& move);

public:
  virtual void init() {};

  // Returns "true" when the move completed
  virtual bool step(Player& player, Move& move) = 0;
};

class PlainMoveAnimation : public MoveAnimation {
public:
  bool step(Player& player, Move& move) override;
};

class BlockedMoveAnimation : public MoveAnimation {
  uint8_t _step;
public:
  void init() override { _step = 0; }
  bool step(Player& player, Move& move) override;
};

class PushMoveAnimation : public MoveAnimation {
  uint8_t _step;
public:
  void init() override { _step = 0; }
  bool step(Player& player, Move& move) override;
};

class Level;

class Moveable {
protected:
  // Position in pixels wrt to top-left corner of level
  Vector2D _pos;

public:
  void init(GridPos pos) { _pos = Vector2D(pos.x * 8, pos.y * 8); }

  bool isAtGridPos() const { return (_pos.x % 8 + _pos.y % 8) == 0; };
  GridPos gridPos() const {
    return GridPos((_pos.x + 4) / 8, (_pos.y + 4) / 8);
  }
};

class Player : public Moveable {
  friend class MoveAnimation;
  friend class BlockedMoveAnimation;
  friend class PlainMoveAnimation;
  friend class PushMoveAnimation;

  Level& _level;

  // Rotation angle, range [0, 360>
  int _rotation;

  ObjectColor _bubble;

  // Frame offset to animate caterpillar track
  int _trackOffset;

  Move* _move;
  Move* _moveNext;
  MoveAnimation* _moveAnim;

  int _moveNextExpiry;
  int _retryCount;

  // Object pools
  PlainMoveAnimation _plainMoveAnim;
  PushMoveAnimation _pushMoveAnim;
  BlockedMoveAnimation _blockedMoveAnim;

  Move _movePool[2];

  int checkBlocked(Move* move);

  // Returns pointer to Move for desired direction
  Move* getMove(Direction dir);

  // Checks what happens when trying to move in the desired direction.
  // Can be blocked (bump into wall or non-pushable box), push or plain move.
  Move* checkMove(Move* move);

  // Starts the given move.
  void startNextMove();

  void rotateTowards(int rotation);
  void moveForward(Direction dir);
  void moveBackward(Direction dir);

  bool pushContinues();

public:
  Player(Level& level) : _level(level) {}

  int rotation() const { return _rotation; }

  void init(GridPos pos, ObjectColor bubble = ObjectColor::None);
  void update();

  void draw(int x0, int y0);
};

class Box : public Moveable {
  ObjectColor _color;

public:
  void init(GridPos pos, ObjectColor color);

  ObjectColor color() const { return _color; }
  void moveStep(Direction dir);

  void draw(int x0, int y0);
};

class Level {
  int _levelIndex;
  const LevelSpec* _spec;

  Player _player;
  Box _boxes[maxBoxes];
  int _moveCount;

  // The number of correctly placed boxes
  int _boxCount;

public:
  Level() : _player(*this) {}

  void init(int levelIndex);

  int levelIndex() const { return _levelIndex; }
  Box* boxAt(GridPos pos);
  ObjectColor bubbleAt(GridPos pos) const;
  ObjectColor targetAt(GridPos pos) const;
  bool isWall(GridPos pos) const;

  void start();
  void incMoveCount() { _moveCount++; }
  bool isDone();

  void update();
  void draw();
};
