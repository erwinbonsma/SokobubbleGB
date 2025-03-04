#pragma once

#include "Game.h"

class Lights;

class Animation {
public:
  // Executions an animation step. Returns the active animation.
  // This can be the current one, a new one, or none.
  virtual Animation* update() = 0;

  virtual void draw() {}
};

class LevelDoneAnimation : public Animation {
  Lights* _lights;
  uint16_t _step;
  uint16_t _updateHiDelay;
  uint16_t _nextUpdateHi;

public:
  void init(Lights* lights);

  Animation* update() override;
  void draw() override;
};

class LevelSlideAnimation : public Animation {
  Level* _levelL;
  Level* _levelR;
  bool _leftToRight;
  bool _centerLevel;

  int _step;
  int _offset;

  // TODO: Switch to std::optional once supported
  int _yOffsetName;

  int addDirection(int offset) const { return _leftToRight ? offset : 80 - offset; }
  int addCentering(int offset) const { return offset + _centerLevel * 8; }

public:
  void init(Level* levelL, Level* levelR);

  void setRightToLeft() { _leftToRight = false; }
  void setCenterLevel() { _centerLevel = true; }
  void showFromName() { _yOffsetName = 0; }

  int offsetLeft() const { return addCentering(-addDirection(_offset)); }
  int offsetRight() const { return addCentering(80 - addDirection(_offset)); }

  Animation* update() override;
  void draw() override;
};

// Animates transition to next level.
//
// It is a thin wrapper around LevelSlideAnimation to transition into
// StartLevelAnimation
class NextLevelAnimation : public Animation {
  int _step;

public:
  void init();

  Animation* update() override;
  void draw() override;
};

// Start a level. Animates removal of name
class StartLevelAnimation : public Animation {
  int _yOffsetName;

public:
  void init();

  Animation* update() override;
  void draw() override;
};

class RetryAnimation : public Animation {
  int _step;
  int _xOffset;

public:
  void init();

  Animation* update() override;
  void draw() override;
};

extern LevelDoneAnimation levelDoneAnim;
extern NextLevelAnimation nextLevelAnim;
extern StartLevelAnimation startLevelAnim;
extern LevelSlideAnimation levelSlideAnim;
extern RetryAnimation retryAnim;
