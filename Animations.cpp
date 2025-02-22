#include "Animations.h"

#include <Gamebuino-Meta.h>

#include "SoundFx.h"

LevelDoneAnimation levelDoneAnim;
LevelSlideAnimation levelSlideAnim;

int ease(int x, int range) {
  return (
    x <= range / 2
    ? x * x * 2 / range
    : range - ease(range - x, range)
  );
}

Animation* LevelDoneAnimation::update() {
  _step++;

  if (_step == 15) {
    gb.sound.fx(levelDoneSfx);
  } else if (_step == 90) {
    Level* oldLevel = &game.level();
    game.initNextLevel();
    levelSlideAnim.init(oldLevel, &game.level());
    return &levelSlideAnim;
  }

  return this;
}

void LevelSlideAnimation::init(Level* levelL, Level* levelR, bool leftToRight) {
  _levelL = levelL;
  _levelR = levelR;
  _leftToRight = leftToRight;

  _step = 0;
  _offset = 0;
}

Animation* LevelSlideAnimation::update() {
  if (_step == 0) {
    gb.sound.fx(pushStartSfx);
  }

  if (_step < 10) {
    _nameY = 3 - _step;
  } else if (_step > 70) {
    _nameY = _step - 77;
  } else {
    _nameY = -99;
  }

  ++_step;

  // TODO: easing
  _offset = ease(_step, 80);

  return (_step == 80) ? nullptr : this;
}

void LevelSlideAnimation::draw() {
  int offset = _leftToRight ? _offset : 80 - _offset;

  _levelL->draw(-offset);
  _levelR->draw(80-offset);

  // TODO: Draw level name
}
