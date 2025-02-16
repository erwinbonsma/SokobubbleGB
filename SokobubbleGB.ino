#include <Gamebuino-Meta.h>

#include <utility>

#include "Game.h"
#include "Images.h"
#include "Levels.h"
#include "Palettes.h"
#include "SoundFx.h"
#include "Utils.h"

UpdateFunction updateFunction;
DrawFunction drawFunction;

Level level;

void startLevel(int levelIndex) {
  level.init(levelIndex);

  gb.sound.fx(getReadySfx);
}

void draw() {
  gb.display.clear(DARKGRAY);

  level.draw();
}

void update() {
  level.update();

  if (level.isDone()) {
    startLevel((level.levelIndex() + 1) % numLevels);
  }
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  updateFunction = update;
  drawFunction = draw;

  startLevel(0);
}

void loop() {
  while(!gb.update());

  updateFunction();
  drawFunction();
}
