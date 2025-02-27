#pragma once

#include "Utils.h"

class PopupMenu : Scene {
  Scene* _mainScene;
  int _selectedItem;

public:
  void toggleVisibility();
  void show();
  void hide();

  void update();
  void draw();
};

extern PopupMenu popupMenu;
