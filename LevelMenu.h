#pragma once

#include "Animations.h"
#include "Utils.h"

class LevelMenu : public Scene {
  LevelSlideAnimation* _slideAnim;
  int _xOffset;

  void startSlideTransition();

public:
  void init();

  void update() override;
  void draw() override;
};

extern LevelMenu levelMenu;