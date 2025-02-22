#pragma once

#include "Game.h"

class Animation {
public:
  // Executions an animation step. Returns the active animation.
  // This can be the current one, a new one, or none.
  virtual Animation* update() = 0;

  virtual bool implementsDraw() { return false; }
  virtual void draw() {}
};

class LevelDoneAnimation : public Animation {
  int _step;

public:
  void init() { _step = 0; }

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

  Animation* update() override;

  bool implementsDraw() override { return true; }
  void draw() override;
};

extern LevelDoneAnimation levelDoneAnim;
extern LevelSlideAnimation levelSlideAnim;
