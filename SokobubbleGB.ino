#include <Gamebuino-Meta.h>

#include <utility>

#include "Game.h"
#include "Images.h"
#include "Levels.h"
#include "Music.h"
#include "Palettes.h"
#include "SoundFx.h"
#include "Utils.h"

UpdateFunction updateFunction;
DrawFunction drawFunction;

void draw() {
  game.draw();
}

void update() {
  game.update();
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  updateFunction = update;
  drawFunction = draw;

  game.level().init(0);

  //gb.sound.playSong(song, true);
}

void loop() {
  while(!gb.update());

  updateFunction();
  drawFunction();
}
