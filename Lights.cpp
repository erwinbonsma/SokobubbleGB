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

struct RGB888 {
	uint8_t r, g, b;
};
const RGB888 bubbleColors[numColors] = {
  RGB888 { .r = 255, .g = 0, .b = 0 },
  RGB888 { .r = 0, .g = 255, .b = 0 },
  RGB888 { .r = 0, .g = 0, .b = 255 },
  RGB888 { .r = 255, .g = 255, .b = 0 },
};

// How many ticks before activation dropped from max to min level
constexpr int maxActivation = 32;

constexpr uint8_t maxChannelVal = 255;
constexpr uint8_t minChannelVal = 16;

inline uint8_t scaleChannel(uint8_t channelVal, int activation) {
  return channelVal * (minChannelVal + (maxChannelVal - minChannelVal) * activation) / maxActivation / maxChannelVal;
}

void Lights::changeColor(ObjectColor color) {
  _activeColor = color;
  _activation = maxActivation;
}

void Lights::setColor(ObjectColor color) {
  _activeColor = color;
}

void Lights::update() {
  _updateInvokedSinceLastDraw = true;

  if (_activation > 0) {
    _activation--;
  }
}

void Lights::draw() {
  if (
    _activeColor == ObjectColor::None
    // Do not show lights when update was not invoked. This way the lights are
    // off when the pop-up menu is shown and automatically turn on again when
    // the menu is hidden
    || !_updateInvokedSinceLastDraw
  ) {
    gb.lights.clear(BLACK);
    return;
  }

  Color color;
  if (_activeColor != ObjectColor::Any) {
      RGB888 c = bubbleColors[static_cast<int>(_activeColor) - 1];
      // Intensity, range = [minChannelVal, 255]
      int i = minChannelVal + (256 - minChannelVal) * _activation / maxActivation;
      color = gb.createColor(c.r * i / 256, c.g * i / 256, c.b * i / 256);
  }

  for (int i = 8; --i >= 0; ) {
    int x = (i < 4) ? 0 : 1;
    int y = (i < 4) ? i : 7 - i;

    if (_activeColor == ObjectColor::Any) {
      // The "chain" that is currently occupying this light-pixel
      int chain = ((i + gb.frameCount / 2) / 4) % 2;
      int chainColorIndex =
        (gb.frameCount / 4 + chain * (numGradientColors / 2)) % numGradientColors;
      color = static_cast<Color>(gradientColors[chainColorIndex]);
    }

    gb.lights.drawPixel(x, y, color);
  }
  _updateInvokedSinceLastDraw = false;
}
