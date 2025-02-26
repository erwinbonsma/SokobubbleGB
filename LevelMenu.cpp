#include "LevelMenu.h"

#include "Images.h"
#include "Game.h"
#include "ProgressTracker.h"
#include "SoundFx.h"

void LevelMenu::init() {
  _xOffset = 8;
  _slideAnim = nullptr;
}

void LevelMenu::startSlideTransition() {
  levelSlideAnim.setCenterLevel();
  levelSlideAnim.showFromName();

  _slideAnim = &levelSlideAnim;

  gb.sound.fx(pushStartSfx);
}

void LevelMenu::update() {
  if (_xOffset == 0) {
    startLevelAnim.init();
    game.setAnimation(&startLevelAnim);
    scene = &game;
  } else if (_xOffset != 8) {
    _xOffset--;
  } else if (_slideAnim) {
    _slideAnim = static_cast<LevelSlideAnimation *>(_slideAnim->update());
  } else if (
    gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT)
  ) {
    Level* oldLevel = &game.level();
    int m = progressTracker.getMaxLevelIndex() + 1;

    if (gb.buttons.pressed(BUTTON_LEFT)) {
      game.initLevel((oldLevel->levelIndex() + m - 1) % m);
      levelSlideAnim.init(&game.level(), oldLevel);
      levelSlideAnim.setRightToLeft();
    } else {
      game.initLevel((oldLevel->levelIndex() + 1) % m);
      levelSlideAnim.init(oldLevel, &game.level());
    }

    startSlideTransition();
  } else if (gb.buttons.pressed(BUTTON_A)) {
    _xOffset--;
  }
}

void LevelMenu::draw() {
  if (_slideAnim) {
    _slideAnim->draw();
  } else {
    gb.display.setColor(BLACK);
    fillFastVRect(0, _xOffset);

    game.level().draw(_xOffset);
    game.level().drawName(_xOffset);

    iconsImage.setFrame(iconFrameButtonL);
    gb.display.drawImage(2, 28, iconsImage);

    iconsImage.setFrame(iconFrameButtonR);
    gb.display.drawImage(69, 28, iconsImage);

    iconsImage.setFrame(iconFrameButtonA);
    gb.display.drawImage(69, 53, iconsImage);
  }
}

LevelMenu levelMenu;