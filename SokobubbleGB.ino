#include <Gamebuino-Meta.h>

#include <utility>

#include "Game.h"
#include "Images.h"
#include "Levels.h"
#include "Palettes.h"
#include "Utils.h"

UpdateFunction updateFunction;
DrawFunction drawFunction;

Level level;


void draw() {
  gb.display.clear(DARKGRAY);

  level.draw();
}

void update() {
  level.update();

  if (level.isDone()) {
    level.init((level.levelIndex() + 1) % numLevels);
  }
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  updateFunction = update;
  drawFunction = draw;

  level.init(0);
}

void loop() {
  while(!gb.update());

  updateFunction();
  drawFunction();
}
