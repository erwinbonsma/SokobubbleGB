#pragma once

#include "Utils.h"

class Lights {
  ObjectColor _activeColor = ObjectColor::None;
  int _activation;

public:
  /* None -> No lights
   * R, G, B, Y -> Single color, with bright activation
   * Any -> Colors cycle, no activation
   */
  void changeColor(ObjectColor color);

  // Similar to changeColor, but without activation
  void setColor(ObjectColor color);

  void update();
  void draw();
};