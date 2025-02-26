#include <Gamebuino-Meta.h>

#include <utility>

#include "LevelMenu.h"
#include "Music.h"
#include "ProgressTracker.h"
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
  scene = scene->update();

  if (gb.buttons.pressed(BUTTON_B)) {
    toggleMusic();
  }
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  game.level().init(progressTracker.getMaxLevelIndex());
  levelMenu.init();
  scene = &levelMenu;
}

void loop() {
  while(!gb.update());

  update();
  draw();
}
