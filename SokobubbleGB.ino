#include <Gamebuino-Meta.h>

#include "Utils.h"
#include "Images.h"
#include "Levels.h"

UpdateFunction updateFunction;
DrawFunction drawFunction;

uint8_t frameIndex = 0;

void drawLevel(int levelIndex) {
  const LevelSpec& spec = levels[levelIndex];

  int x0 = 40 - spec.grid.w * 4;
  int y0 = 32 - spec.grid.h * 4;

  for (int y = 0; y < spec.grid.h; ++y) {
    int rowOffset = y * spec.grid.w;
    for (int x = 0; x < spec.grid.w; ++x) {
      int tileIndex = spec.grid.tiles[x + rowOffset];
      if (tileIndex > 0) {
        wallsImage.setFrame(tileIndex - 1);
        gb.display.drawImage(x0 + x * 8, y0 + y * 8, wallsImage);
      }
    }
  }

  playerImage.setFrame(frameIndex);
  gb.display.drawImage(x0 + spec.startPos.x * 8, y0 + spec.startPos.y * 8, playerImage);
}

void draw() {
  gb.display.clear(DARKGRAY);

  drawLevel(0);
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
