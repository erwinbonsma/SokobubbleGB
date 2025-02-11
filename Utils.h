#pragma once

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
