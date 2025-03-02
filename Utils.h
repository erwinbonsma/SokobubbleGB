#pragma once

#include <Gamebuino-Meta.h>

#define CALL_MEMBER_FN(object, ptrToMember)  ((object).*(ptrToMember))

//#define DEVELOPMENT

class Scene {
public:
  virtual void update() = 0;
  virtual void draw() = 0;
};

extern Scene* scene;
extern const char* version;

void assertFailed(const char *function, const char *file, int lineNo, const char *expression);

#define assertTrue(condition) \
if (!(condition)) { \
  assertFailed(__func__, __FILE__, __LINE__, #condition); \
}

struct Vector2D {
  int8_t x;
  int8_t y;

  Vector2D() = default;
  Vector2D(const Vector2D& v) { x = v.x; y = v.y; }
  Vector2D(int x, int y)
  : x(static_cast<int8_t>(x))
  , y(static_cast<int8_t>(y)) {}

  void add(const Vector2D& v) { x += v.x; y += v.y; }
  void sub(const Vector2D& v) { x -= v.x; y -= v.y; }
};

inline bool operator==(const Vector2D &lhs, const Vector2D &rhs) {
  return (lhs.x == rhs.x && lhs.y == rhs.y);
}
inline bool operator!=(const Vector2D &lhs, const Vector2D &rhs) {
  return !(lhs == rhs);
}

inline Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs) {
  return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
}

typedef Vector2D GridPos;

constexpr int numColors = 4;
enum class ObjectColor : uint8_t {
  None = 0,

  Red = 1,
  Green = 2,
  Blue = 3,
  Yellow = 4,

  Any = 5, // For targets
};
