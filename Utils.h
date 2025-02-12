#pragma once

#include <Gamebuino-Meta.h>

#define CALL_MEMBER_FN(object, ptrToMember)  ((object).*(ptrToMember))

typedef void (*UpdateFunction)();
typedef void (*DrawFunction)();

// Defined in .ino file. Declared here for convenience
extern UpdateFunction updateFunction;
extern DrawFunction drawFunction;

void assertFailed(const char *function, const char *file, int lineNo, const char *expression);

#define assertTrue(condition) \
if (!(condition)) { \
  assertFailed(__func__, __FILE__, __LINE__, #condition); \
}

struct GridPos {
  uint8_t x;
  uint8_t y;

  GridPos(int xVal, int yVal)
  : x(static_cast<int8_t>(xVal))
  , y(static_cast<int8_t>(yVal)) {}
};

enum class ObjectColor : uint8_t {
  Red = 1,
  Green = 2,
  Blue = 3,
  Yellow = 4,

  Any = 5, // For targets
};
