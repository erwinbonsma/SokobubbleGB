#pragma once

#include "Utils.h"

enum class PopupMenuItem : uint8_t {
  Help = 0,
  Stats = 1,
  Music = 2,
  Credits = 3,
};

class PopupMenu : Scene {
  Scene* _mainScene;
  PopupMenuItem _selectedItem;
  bool _showSubView;
  int _step;

  void drawHelp();
  void drawStats();
  void drawCredits();

  void drawPopup();

public:
  bool isVisible();
  void toggleVisibility();
  void show();
  void hide();
  void showStats();

  void update();
  void draw();
};

extern PopupMenu popupMenu;
