#include "Animations.h"

#include <Gamebuino-Meta.h>

#include "Lights.h"
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

  if (_step == 1) {
    // Enable celebration lights
    _lights->changeColor(ObjectColor::Any);
  } else if (_step == 15) {
    gb.sound.fx(levelDoneSfx);
  } else if (_step == 90) {
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
  game.level().setShowScore(false);
  _slideAnim = &levelSlideAnim;
  _nameY = 2;
}

Animation* LevelStartAnimation::update() {
  if (_slideAnim) {
    _slideAnim = static_cast<LevelSlideAnimation *>(_slideAnim->update());
    return this;
  }

  _nameY--;
  if (_nameY == -7) {
    game.level().setShowScore(true);
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

  drawLevelName(&game.level(), offset, _nameY);
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
  _offset = _step; //ease(_step, 80);

  return (_step == 80) ? nullptr : this;
}

void LevelSlideAnimation::draw() {
  int offset = _leftToRight ? _offset : 80 - _offset;

  _levelL->draw(offsetLeft());
  _levelR->draw(offsetRight());

  // TODO: Draw level name
}
