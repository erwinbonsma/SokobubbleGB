#pragma once

#include "Game.h"

class Lights;

class Animation {
public:
  // Executions an animation step. Returns the active animation.
  // This can be the current one, a new one, or none.
  virtual Animation* update() = 0;

  virtual bool implementsDraw() { return false; }
  virtual void draw() {}
};

class LevelDoneAnimation : public Animation {
  Lights* _lights;
  int _step;

public:
  void init(Lights* lights);

  Animation* update() override;
};

class LevelSlideAnimation : public Animation {
  Level* _levelL;
  Level* _levelR;
  bool _leftToRight;

  int _step;
  int _offset;

  // TODO: Switch to std::optional once supported
  int _nameY;

public:
  void init(Level* levelL, Level* levelR, bool leftToRight = true);

  int offsetLeft() const { return -_offset; }
  int offsetRight() const { return 80 - _offset; }

  Animation* update() override;

  bool implementsDraw() override { return true; }
  void draw() override;
};

class LevelStartAnimation : public Animation {
  LevelSlideAnimation* _slideAnim;
  int _nameY;

public:
  void init();

  bool implementsDraw() override { return true; }
  Animation* update() override;
  void draw() override;
};

extern LevelDoneAnimation levelDoneAnim;
extern LevelStartAnimation levelStartAnim;
extern LevelSlideAnimation levelSlideAnim;
