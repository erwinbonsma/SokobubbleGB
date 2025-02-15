#include <Gamebuino-Meta.h>

#include "Game.h"
#include "Images.h"
#include "Levels.h"
#include "Palettes.h"
#include "Utils.h"

UpdateFunction updateFunction;
DrawFunction drawFunction;

Level level{levels[0]};

void draw() {
  gb.display.clear(DARKGRAY);

  level.draw();
}

void update() {
  level.update();
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  updateFunction = update;
  drawFunction = draw;
}

void loop() {
  while(!gb.update());

  updateFunction();
  drawFunction();
}
