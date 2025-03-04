#include <Gamebuino-Meta.h>

#include <utility>

#include "Images.h"
#include "LevelMenu.h"
#include "Music.h"
#include "PopupMenu.h"
#include "ProgressTracker.h"
#include "Utils.h"

const char* version = "v1.0 beta2";

Scene* scene;

void draw() {
  scene->draw();
}

void update() {
  if (gb.buttons.pressed(BUTTON_MENU)) {
    if (!popupMenu.isVisible()) {
      popupMenu.show();
      return;
    }
  }

  scene->update();

#ifdef DEVELOPMENT
  if (gb.buttons.pressed(BUTTON_B)) {
    toggleMusic();
  }
#endif
}

void setup() {
  gb.begin();
  gb.setFrameRate(30);

  gb.display.setPalette(customPalette);

  progressTracker.init();
  progressTracker.dump();

  game.level().init(progressTracker.getMaxLevelIndex());
  levelMenu.init();
  scene = &levelMenu;

  playMusic();
}

void loop() {
  while(!gb.update());

  update();
  draw();
}
