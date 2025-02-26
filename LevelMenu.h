#pragma once

#include "Animations.h"
#include "Utils.h"

class LevelMenu : public Scene {
  LevelSlideAnimation* _slideAnim;
  int _xOffset;

public:
  void init();

  Scene* update() override;
  void draw() override;
};

extern LevelMenu levelMenu;