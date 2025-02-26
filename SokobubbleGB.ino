#include <Gamebuino-Meta.h>

#include <utility>

#include "Game.h"
#include "Images.h"
#include "Levels.h"
#include "Music.h"
#include "SoundFx.h"
#include "Utils.h"

bool musicOn = false;
Scene* scene;

void toggleMusic() {
  musicOn = !musicOn;
  if (musicOn) {
    gb.sound.playSong(song, true);
  } else {
    gb.sound.stopSong();
  }
}

void draw() {
  scene->draw();
}

void update() {
  scene->update();

  if (gb.buttons.pressed(BUTTON_B)) {
    toggleMusic();
  }
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  game.level().init(0);
  scene = &game;
}

void loop() {
  while(!gb.update());

  update();
  draw();
}
