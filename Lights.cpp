#include "Lights.h"

#undef min
#undef max
#include <algorithm>

constexpr uint8_t numGradientColors = 36;
const uint16_t gradientColors[numGradientColors] = {
  0xf800, 0xf940, 0xfaa0, 0xfbe0, 0xfd40, 0xfea0,
  0xffe0, 0xd7e0, 0xafe0, 0x7fe0, 0x57e0, 0x2fe0,
  0x07e0, 0x07e5, 0x07ea, 0x07ef, 0x07f5, 0x07fa,
  0x07ff, 0x06bf, 0x055f, 0x03ff, 0x02bf, 0x015f,
  0x001f, 0x281f, 0x501f, 0x781f, 0xa81f, 0xd01f,
  0xf81f, 0xf81a, 0xf815, 0xf80f, 0xf80a, 0xf805,
};

constexpr int numActivationLevels = 8;
const uint16_t activationColors[numColors * numActivationLevels] = {
  0x1800, 0x3800, 0x5800, 0x7800, 0x9800, 0xb800, 0xd800, 0xf800,
  0x00e0, 0x01e0, 0x02e0, 0x03e0, 0x04e0, 0x05e0, 0x06e0, 0x07e0,
  0x0003, 0x0007, 0x000b, 0x000f, 0x0013, 0x0017, 0x001b, 0x001f,
  0x18e0, 0x39e0, 0x5ae0, 0x7be0, 0x9ce0, 0xbde0, 0xdee0, 0xffe0,
};

// The number of ticks before activation drops a level
constexpr int activationTicks = 4;

void Lights::changeColor(ObjectColor color) {
  _activeColor = color;

  // Ignored for None and Any, but no harm in setting it
  _activation = numActivationLevels * activationTicks - 1;
}

void Lights::update() {
  if (_activation > 0) {
    _activation--;
  }
}

void Lights::draw() {
  if (_activeColor == ObjectColor::None) {
    gb.lights.clear(BLACK);
    return;
  }

  for (int i = 8; --i >= 0; ) {
    int x = (i < 4) ? 0 : 1;
    int y = (i < 4) ? i : 7 - i;
    Color color;

    if (_activeColor == ObjectColor::Any) {
      // The "chain" that is currently occupying this light-pixel
      int chain = ((i + gb.frameCount / 2) / 4) % 2;
      int chainColorIndex =
        (gb.frameCount / 4 + chain * (numGradientColors / 2)) % numGradientColors;
      color = static_cast<Color>(gradientColors[chainColorIndex]);
    } else {
      int intensity = _activation / activationTicks;
      color = static_cast<Color>(activationColors[
        intensity + (static_cast<int>(_activeColor) - 1) * numActivationLevels
      ]);
    }

    gb.lights.drawPixel(x, y, color);
  }
}
