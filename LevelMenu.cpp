#include "LevelMenu.h"

#include "Images.h"
#include "Game.h"
#include "PopupMenu.h"
#include "ProgressTracker.h"
#include "SoundFx.h"

void LevelMenu::init() {
  _xOffset = 8;
  _slideAnim = nullptr;
#ifdef DEVELOPMENT
  _numSelectable = numLevels;
#else
  _numSelectable = progressTracker.getMaxLevelIndex() + 1;
#endif
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
    _numSelectable > 1 && (
      gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT)
    )
  ) {
    Level* oldLevel = &game.level();

    if (gb.buttons.pressed(BUTTON_LEFT)) {
      game.initLevel((oldLevel->levelIndex() + _numSelectable - 1) % _numSelectable);
      levelSlideAnim.init(&game.level(), oldLevel);
      levelSlideAnim.setRightToLeft();
    } else {
      game.initLevel((oldLevel->levelIndex() + 1) % _numSelectable);
      levelSlideAnim.init(oldLevel, &game.level());
    }

    startSlideTransition();
  } else if (gb.buttons.pressed(BUTTON_A)) {
    if (game.level().levelIndex() < numLevels - 1) {
      // Move level to ensure smooth level start transition
      _xOffset--;
    } else {
      // From level 'The end' go to stats
      popupMenu.showStats();
    }
  }
}

void LevelMenu::draw() {
  if (_slideAnim) {
    _slideAnim->draw();
  } else {
    gb.display.setColor(BLACK);
    gb.display.fillRect(0, 0, _xOffset, 64);

    game.level().draw(_xOffset);
    game.level().drawName(_xOffset);

    if (_numSelectable > 1) {
      iconsImage.setFrame(iconFrameButtonL);
      gb.display.drawImage(2, 28, iconsImage);

      iconsImage.setFrame(iconFrameButtonR);
      gb.display.drawImage(69, 28, iconsImage);
    }

    iconsImage.setFrame(iconFrameButtonA);
    gb.display.drawImage(69, 53, iconsImage);
  }
}

LevelMenu levelMenu;