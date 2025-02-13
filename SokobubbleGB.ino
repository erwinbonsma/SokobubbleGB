#include <Gamebuino-Meta.h>

#include "Utils.h"
#include "Images.h"
#include "Levels.h"
#include "Palettes.h"

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

  for (int i = 0; i < spec.numTargets; ++i) {
    auto& obj = spec.targets[i];
    gb.display.colorIndex = const_cast<Color *>(palettes[static_cast<int>(obj.color)]);
    gb.display.drawImage(x0 + obj.pos.x * 8, y0 + obj.pos.y * 8, targetImage);
  }

  boxImage.setFrame(0);
  for (int i = 0; i < spec.numBoxes; ++i) {
    auto& obj = spec.boxes[i];
    gb.display.colorIndex = const_cast<Color *>(palettes[static_cast<int>(obj.color)]);
    gb.display.drawImage(x0 + obj.pos.x * 8, y0 + obj.pos.y * 8, boxImage);
  }

  for (int i = 0; i < spec.numBubbles; ++i) {
    auto& obj = spec.bubbles[i];
    gb.display.colorIndex = const_cast<Color *>(palettes[static_cast<int>(obj.color)]);
    gb.display.drawImage(x0 + obj.pos.x * 8, y0 + obj.pos.y * 8, bubbleImage);
  }

  gb.display.colorIndex = PALETTE_DEFAULT;

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
