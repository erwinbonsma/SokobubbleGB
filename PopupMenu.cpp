#include "PopupMenu.h"

#include "Images.h"
#include "Music.h"

constexpr int numMenuOptions = 4;
const char* menuOptions[numMenuOptions] = {
  "Help",
  "Best scores",
  "Music [   ]",
  "Credits",
};
const char* musicState[2] = { "off", "on" };

bool PopupMenu::isVisible() {
  return scene == this;
}

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
    if (_selectedItem == 2) {
      toggleMusic();
    } else if (_showSubView) {
      _showSubView = false;
      hide();
    } else {
      _showSubView = true;
    }
  } else if (gb.buttons.pressed(BUTTON_MENU)) {
    if (_showSubView) {
      _showSubView = false;
    } else {
      hide();
    }
  } else if (gb.buttons.pressed(BUTTON_UP)) {
    _selectedItem = (_selectedItem + numMenuOptions - 1) % numMenuOptions;
  } else if (gb.buttons.pressed(BUTTON_DOWN)) {
    _selectedItem = (_selectedItem + 1) % numMenuOptions;
  }
}

void PopupMenu::drawCredits() {
  gb.display.clear(DARKBLUE);

  gb.display.setColor(BLUE);
  gb.display.setCursor(26, 2);
  gb.display.print("Credits");

  // gb.display.setColor(BLACK);
  // for (int i = 0; i < numHelpText; ++i) {
  //   gb.display.setCursor(2, 2 + i * 6);
  //   gb.display.print(helpText[i]);
  // }
}

void PopupMenu::drawStats() {
  gb.display.clear(DARKBLUE);

  gb.display.setColor(BLUE);
  gb.display.setCursor(30, 2);
  gb.display.print("Stats");
}

void PopupMenu::drawHelp() {
  gb.display.clear(DARKGRAY);

  playerImage.setFrame(0);
  for (int row = 0; row < 6; ++row) {
    int y = row * 8 + 3;
    for (int col = 0; col < 2; ++col) {
      int x = col * 40;
      gb.display.drawImage(x + 8, y, playerImage);
      if (row == 0) {
        bubbleImage.setFrame(col * 2);
        gb.display.drawImage(x + 18, y + 2, bubbleImage);

        helpIconsImage.setFrame(2);
        gb.display.drawImage(x + 25, y + 2, helpIconsImage);

        gb.display.drawImage(x + 31, y, playerImage);

        cockpitImage.setFrame(1 + col * 2);
        gb.display.drawImage(x + 34, y + 3, cockpitImage);
      } else {
        helpIconsImage.setFrame(row % 3 / 2);
        gb.display.drawImage(x + 2, y + 1, helpIconsImage);

        cockpitImage.setFrame(1 + (((row == 2) + col) % 2) * 2);
        gb.display.drawImage(x + 11, y + 3, cockpitImage);

        boxImage.setFrame(col * 4);
        gb.display.drawImage(x + 17, y + 1, boxImage);
      }
      if (row >= 3) {
        int idx = (col == 0 ? row * 4 : row * 2 + 2) % 6;
        targetImage.setFrame(idx);
        gb.display.drawImage(x + 24, y, targetImage);
      }
    }
  }

  gb.display.setColor(BLUE);
  gb.display.setCursor(3, 55);
  gb.display.print("Hold A");
  gb.display.setColor(GRAY);
  gb.display.print(" = Retry/Quit");
}

void PopupMenu::drawPopup() {
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

    if (i == 2) {
      gb.display.setCursor(44 + 2 * musicOn, 32);
      gb.display.print(musicState[musicOn]);
    }
  }
}

void PopupMenu::draw() {
  if (_showSubView) {
    if (_selectedItem == 0) {
      drawHelp();
    } else if (_selectedItem == 1) {
      drawStats();
    } else {
      drawCredits();
    }
  } else {
    drawPopup();
  }
}

PopupMenu popupMenu;