#include "LevelMenu.h"

#include "Game.h"

void LevelMenu::init() {
  _xOffset = 8;
}

Scene* LevelMenu::update() {
  if (_xOffset == 0) {
    return &game;
  } else if (_xOffset != 8) {
    _xOffset--;
  } else if (_slideAnim) {
    _slideAnim = static_cast<LevelSlideAnimation *>(_slideAnim->update());
  } else if (gb.buttons.pressed(BUTTON_LEFT)) {
    Level* oldLevel = &game.level();
    game.initLevel((oldLevel->levelIndex() + numLevels - 1) % numLevels);
    levelSlideAnim.init(&game.level(), oldLevel);
    levelSlideAnim.setCenterLevel();
    levelSlideAnim.setRightToLeft();
    _slideAnim = &levelSlideAnim;
  } else if (gb.buttons.pressed(BUTTON_RIGHT)) {
    Level* oldLevel = &game.level();
    game.initLevel((oldLevel->levelIndex() + 1) % numLevels);
    levelSlideAnim.init(oldLevel, &game.level());
    levelSlideAnim.setCenterLevel();
    _slideAnim = &levelSlideAnim;
  } else if (gb.buttons.pressed(BUTTON_A)) {
    _xOffset--;
  }

  return this;
}

void LevelMenu::draw() {
  if (_slideAnim) {
    _slideAnim->draw();
  } else {
    gb.display.setColor(BLACK);
    fillFastVRect(0, _xOffset);

    game.level().draw(_xOffset);
    game.level().drawName(_xOffset);
  }
}

LevelMenu levelMenu;