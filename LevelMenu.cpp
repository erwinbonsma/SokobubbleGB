#include "LevelMenu.h"

#include "Game.h"
#include "SoundFx.h"

void LevelMenu::init() {
  _xOffset = 8;
}

void LevelMenu::startSlideTransition() {
  levelSlideAnim.setCenterLevel();
  levelSlideAnim.showFromName();

  _slideAnim = &levelSlideAnim;

  gb.sound.fx(pushStartSfx);
}

Scene* LevelMenu::update() {
  if (_xOffset == 0) {
    startLevelAnim.init();
    game.setAnimation(&startLevelAnim);
    return &game;
  } else if (_xOffset != 8) {
    _xOffset--;
  } else if (_slideAnim) {
    _slideAnim = static_cast<LevelSlideAnimation *>(_slideAnim->update());
  } else if (gb.buttons.pressed(BUTTON_LEFT)) {
    Level* oldLevel = &game.level();
    game.initLevel((oldLevel->levelIndex() + numLevels - 1) % numLevels);
    levelSlideAnim.init(&game.level(), oldLevel);
    levelSlideAnim.setRightToLeft();

    startSlideTransition();
  } else if (gb.buttons.pressed(BUTTON_RIGHT)) {
    Level* oldLevel = &game.level();
    game.initLevel((oldLevel->levelIndex() + 1) % numLevels);
    levelSlideAnim.init(oldLevel, &game.level());

    startSlideTransition();
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