#include <Gamebuino-Meta.h>

#include <utility>

#include "Game.h"
#include "Images.h"
#include "Levels.h"
#include "Music.h"
#include "SoundFx.h"
#include "Utils.h"

bool musicOn = false;

UpdateFunction updateFunction;
DrawFunction drawFunction;

void toggleMusic() {
  musicOn = !musicOn;
  if (musicOn) {
    gb.sound.playSong(song, true);
  } else {
    gb.sound.stopSong();
  }
}

void draw() {
  game.draw();
}

void update() {
  game.update();

  if (gb.buttons.pressed(BUTTON_B)) {
    toggleMusic();
  }
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  updateFunction = update;
  drawFunction = draw;

  game.level().init(0);
}

void loop() {
  while(!gb.update());

  updateFunction();
  drawFunction();
}
