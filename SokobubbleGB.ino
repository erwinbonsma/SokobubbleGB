#include <Gamebuino-Meta.h>

#include <utility>

#include "Images.h"
#include "LevelMenu.h"
#include "Music.h"
#include "PopupMenu.h"
#include "ProgressTracker.h"
#include "Utils.h"

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

  if (gb.buttons.pressed(BUTTON_B)) {
    toggleMusic();
  }
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
}

void loop() {
  while(!gb.update());

  update();
  draw();
}
