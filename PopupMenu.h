#pragma once

#include "Utils.h"

class PopupMenu : Scene {
  Scene* _mainScene;
  int _selectedItem;
  bool _showSubView;

  void drawHelp();
  void drawStats();
  void drawCredits();

  void drawPopup();

public:
  bool isVisible();
  void toggleVisibility();
  void show();
  void hide();

  void update();
  void draw();
};

extern PopupMenu popupMenu;
