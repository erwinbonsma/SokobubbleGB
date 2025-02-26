#include "Animations.h"

#include <Gamebuino-Meta.h>

#include "Lights.h"
#include "ProgressTracker.h"
#include "SoundFx.h"

LevelDoneAnimation levelDoneAnim;
LevelStartAnimation levelStartAnim;
LevelSlideAnimation levelSlideAnim;

int ease(int x, int range) {
  return (
    x <= range / 2
    ? x * x * 2 / range
    : range - ease(range - x, range)
  );
}

void LevelDoneAnimation::init(Lights* lights) {
  _lights = lights;
  _step = 0;
}

Animation* LevelDoneAnimation::update() {
  _step++;

  bool done = false;

  if (_step == 1) {
    // Enable celebration lights
    _lights->changeColor(ObjectColor::Any);
  } else if (_step == 15) {
    gb.sound.fx(levelDoneSfx);
  } else if (_step == 90) {
    auto& level = game.level();
    bool improvedHi = progressTracker.markLevelSolved(
      level.levelIndex(), level.getMoveCount()
    );

    if (improvedHi) {
      gb.sound.fx(newHiSfx);
    } else {
      done = true;
    }
  } else if (_step == 140) {
    auto& level = game.level();

    if (level.getBestMoveCount() <= level.getMoveCount()) {
      done = true;
    } else {
      level.decBestMoveCount();
      gb.sound.fx(pushStartSfx);
      _step = 130;
    }
  }

  if (done) {
    _lights->changeColor(ObjectColor::None);

    levelStartAnim.init();
    return &levelStartAnim;
  }

  _lights->update();

  return this;
}

void LevelStartAnimation::init() {
  Level* oldLevel = &game.level();
  game.initNextLevel();
  levelSlideAnim.init(oldLevel, &game.level());
  _slideAnim = &levelSlideAnim;
  _yOffsetName = 0;
}

Animation* LevelStartAnimation::update() {
  if (_slideAnim) {
    _slideAnim = static_cast<LevelSlideAnimation *>(_slideAnim->update());
    return this;
  }

  _yOffsetName--;
  if (_yOffsetName == -9) {
    gb.sound.fx(getReadySfx);
    return nullptr;
  }

  return this;
}

void LevelStartAnimation::draw() {
  int offset = 0;
  if (_slideAnim) {
    _slideAnim->draw();
    offset = _slideAnim->offsetRight();
  } else {
    game.level().draw();
  }

  game.level().drawName(offset, _yOffsetName);
}

void LevelSlideAnimation::init(Level* levelL, Level* levelR) {
  _levelL = levelL;
  _levelR = levelR;

  // Set defaults
  _leftToRight = true;
  _centerLevel = false;

  _step = 0;
  _offset = 0;
}

Animation* LevelSlideAnimation::update() {
  if (_step < 10) {
    _yOffsetName = -_step;
  } else if (_step > 30) {
    _yOffsetName = _step - 40;
  } else {
    _yOffsetName = -99;
  }

  ++_step;
  _offset = _step * 2;

  return (_step == 40) ? nullptr : this;
}

void LevelSlideAnimation::draw() {
  _levelL->draw(offsetLeft());
  _levelR->draw(offsetRight());

  if (_centerLevel) {
    // Ensure background left of left level is cleared
    gb.display.setColor(BLACK);
    fillFastVRect(offsetLeft() - 8, 8);
  }

  if (_yOffsetName != -99) {
    if ((_offset < 40) == _leftToRight) {
      _levelL->drawName(offsetLeft(), _yOffsetName);
    } else {
      _levelR->drawName(offsetRight(), _yOffsetName);
    }
  }
}
