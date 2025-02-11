#include <Gamebuino-Meta.h>

#include "Utils.h"
#include "Images.h"

UpdateFunction updateFunction;
DrawFunction drawFunction;

uint8_t frameIndex = 0;

void draw() {
  gb.display.clear(DARKGRAY);

  playerImage.setFrame(frameIndex);
  gb.display.drawImage(36, 28, playerImage);
}

void update() {
  frameIndex = (frameIndex + 1) % 3;
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
