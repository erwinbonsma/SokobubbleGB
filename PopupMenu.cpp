#include "PopupMenu.h"

#undef min
#undef max
#include <algorithm>

#include "Images.h"
#include "Levels.h"
#include "Music.h"
#include "ProgressTracker.h"
#include "SoundFx.h"

constexpr int numMenuOptions = 4;
const char* menuOptions[numMenuOptions] = {
  "Help",
  "Best scores",
  "Music [   ]",
  "Credits",
};
const char* musicState[2] = { "off", "on" };
constexpr int numCreditsText = 11;
const char* creditsText[numCreditsText] {
  "(c)2025",
  "",
  "Concept",
  "Coding",
  "Level design",
  "Graphics",
  "Sound effects",
  "by Erwin Bonsma",
  "",
  "Music",
  "by Paul Bonsma",
};

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
      _step = 0;
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

  if (_showSubView) {
    _step++;
    if (_step == 450 && _selectedItem == 3) {
      _showSubView = false;
      hide();
    }
  }
}

int bump(int t, int t_peak) {
  return std::max(0, 2 - abs(t - t_peak));
}

void PopupMenu::drawCredits() {
  gb.display.clear(BLACK);

  int scroll = std::max(0, _step / 3 - 12);

  if (scroll < 40) {
    gb.display.drawImage(8, 16 - scroll, LogoSOKO_Image);
  }
  if (scroll < 51) {
    int x = 16 + 38;
    int y = 36 - scroll;

    gb.display.drawImage(x, y - bump(_step, 32) + 4, LogoE_Image);
    x -= 6;
    gb.display.drawImage(x, y - bump(_step, 28), LogoL_Image);
    x -= 8;
    gb.display.drawImage(x, y - bump(_step, 24), LogoB_Image);
    x -= 8;
    gb.display.drawImage(x, y - bump(_step, 20), LogoB_Image);
    x -= 8;
    gb.display.drawImage(x, y - bump(_step, 16) + 4, LogoU_Image);
    x -= 8;
    gb.display.drawImage(x, y - bump(_step, 12), LogoB_Image);
  }

  for (int i = 0; i < numCreditsText; ++i) {
    int y = 64 - scroll + i * 6;
    if (y < -4 || y >= 64) continue;

    const char* s = creditsText[i];
    gb.display.setCursor(40 - strlen(s) * 2, y);
    gb.display.setColor(BLUE);
    if (strncmp(s, "by", 2) == 0) {
      gb.display.print("by ");
      gb.display.setColor(LIGHTBLUE);
      gb.display.print(&s[3]);
    } else {
      gb.display.print(s);
    }
  }
}

void PopupMenu::drawStats() {
  gb.display.clear(BLUE);

  gb.display.setColor(DARKBLUE);
  gb.display.fillRect(1, 1, 78, 7);
  gb.display.fillRect(24, 9, 28, 49);

  gb.display.setColor(LIGHTBLUE);
  gb.display.setCursor(30, 2);
  gb.display.print("MOVES");

  gb.display.setColor(YELLOW);
  gb.display.setCursor(58, 58);
  gb.display.printf("%5d", progressTracker.getTotalMoves());

  gb.display.setColor(WHITE);
  for (int i = 0; i < numLevels; ++i) {
    int moves = progressTracker.getLevelMinMoves(i);

    gb.display.setCursor(-2 + 28 * (i / 8), 10 + 6 * (i % 8));
    gb.display.setColor((i / 8) % 2 ? BLUE : DARKBLUE);
    gb.display.printf("%2d.", i + 1);

    gb.display.setColor(WHITE);
    if (moves) {
      gb.display.printf("%3d", moves);
    } else {
      gb.display.print("  -");
    }
  }
}

void PopupMenu::drawHelp() {
  gb.display.clear(DARKGRAY);

  playerImage.setFrame(5);
  for (int row = 0; row < 6; ++row) {
    int y = row * 8 + 3;
    for (int col = 0; col < 2; ++col) {
      int x = col * 40 - 4;
      if (row < 3) {
        gb.display.drawImage(x + 8, y, playerImage);

        if (row != 0) {
          cockpitImage.setFrame(1 + (((row == 2) + col) % 2) * 2);
          gb.display.drawImage(x + 11, y + 3, cockpitImage);
        }
      } else {
        int idx = (col == 0 ? row * 4 : row * 2 + 2) % 6;
        targetImage.setFrame(idx);
        gb.display.drawImage(x + 16, y, targetImage);
      }
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
        gb.display.drawImage(x + 25, y + 1, helpIconsImage);

        boxImage.setFrame(col * 4);
        gb.display.drawImage(x + 17, y + 1, boxImage);
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