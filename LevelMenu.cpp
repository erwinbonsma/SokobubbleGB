#include "LevelMenu.h"

#include "Game.h"

Scene* LevelMenu::update() {
  if (_slideAnim) {
    _slideAnim = static_cast<LevelSlideAnimation *>(_slideAnim->update());
  } else if (gb.buttons.pressed(BUTTON_LEFT)) {
    Level* oldLevel = &game.level();
    game.initLevel((oldLevel->levelIndex() + numLevels - 1) % numLevels);
    levelSlideAnim.init(&game.level(), oldLevel);
    levelSlideAnim.setRightToLeft();
    levelSlideAnim.setCenterLevel();
    _slideAnim = &levelSlideAnim;
  } else if (gb.buttons.pressed(BUTTON_RIGHT)) {
    Level* oldLevel = &game.level();
    game.initLevel((oldLevel->levelIndex() + 1) % numLevels);
    levelSlideAnim.init(oldLevel, &game.level());
    levelSlideAnim.setCenterLevel();
    _slideAnim = &levelSlideAnim;
  } else if (gb.buttons.pressed(BUTTON_A)) {
    return &game;
  }

  return this;
}

void LevelMenu::draw() {
  if (_slideAnim) {
    _slideAnim->draw();
  } else {
    game.level().draw(8);
  }
}

LevelMenu levelMenu;