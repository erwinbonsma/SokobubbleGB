#include "PopupMenu.h"

#undef min
#undef max
#include <string>

constexpr int numMenuOptions = 4;
const char* menuOptions[numMenuOptions] = {
  "Help",
  "Best scores",
  "Music [off]",
  "Credits",
};

void PopupMenu::toggleVisibility() {
  if (scene == this) {
    hide();
  } else {
    show();
  }
}

void PopupMenu::show() {
  _mainScene = scene;
  scene = this;
}

void PopupMenu::hide() {
  scene = _mainScene;
  _mainScene = nullptr;
}

void PopupMenu::update() {
  if (gb.buttons.pressed(BUTTON_A)) {
    hide();
  } else if (gb.buttons.pressed(BUTTON_UP)) {
    _selectedItem = (_selectedItem + numMenuOptions - 1) % numMenuOptions;
  } else if (gb.buttons.pressed(BUTTON_DOWN)) {
    _selectedItem = (_selectedItem + 1) % numMenuOptions;
  }
}

void PopupMenu::draw() {
  _mainScene->draw();

  gb.display.setColor(BLACK);
  for (int y = 1; y < 64; y += 2) {
    gb.display.drawFastHLine(0, y, 80);
  }

  gb.display.setColor(DARKBLUE);
  gb.display.fillRect(12, 16, 56, 31);
  gb.display.setColor(BLACK);
  gb.display.drawRect(12, 16, 56, 31);

  for (int i = 0; i < numMenuOptions; ++i) {
    gb.display.setColor((i == _selectedItem) ? BLUE : BLACK);

    gb.display.setCursor(16, 20 + 6 * i);
    gb.display.print(menuOptions[i]);
  }
}

PopupMenu popupMenu;