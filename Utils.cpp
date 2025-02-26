#include "Utils.h"

#undef min
#undef max
#include <algorithm>

// Fast implementation of fillRect.
//
// It mainly speeds up how it avoids drawing outside of the screen.
// Also some gain as the full height is hardcoded.
void fillFastVRect(int x0, int w) {
  int x = std::max(0, x0);
  int xmax = std::min(80, x0 + w);
  while (x < xmax) {
    gb.display.drawLine(x, 0, x, 63);
    ++x;
  }
}

void assertFailed(const char *function, const char *file, int lineNo, const char *expression) {
  if (SerialUSB) {
    SerialUSB.println("=== ASSERT FAILED ===");
    SerialUSB.println(function);
    SerialUSB.println(file);
    SerialUSB.println(lineNo, DEC);
    SerialUSB.println(expression);
    SerialUSB.flush();
  }

  while (1) {
    if (gb.update()) {
      gb.display.clear();
      gb.display.setColor(INDEX_RED);
      gb.display.println("Assert failed:");
      gb.display.println(function);
      gb.display.println(file);
      gb.display.println(lineNo, DEC);
      gb.display.println(expression);
    }
  }
}
