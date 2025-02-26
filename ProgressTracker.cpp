#include "ProgressTracker.h"

#include <Gamebuino-Meta.h>

#undef min
#undef max
#include <algorithm>

constexpr uint8_t VMAJOR = 0;
constexpr uint8_t VMINOR = 1;

constexpr uint8_t SAVEINDEX_VMAJOR = 0;
constexpr uint8_t SAVEINDEX_VMINOR = 1;
constexpr uint8_t SAVEINDEX_MOVES = 2;

void ProgressTracker::clearStoredMoveCounts() {
  for (int i = 0; i < numLevels; i++) {
    gb.save.set(SAVEINDEX_MOVES + levels[i].saveSlot, static_cast<int32_t>(0));
    _minMoves[i] = 0;
  }
}

void ProgressTracker::init() {
  _totalMoves = 0;

  if (gb.save.get(SAVEINDEX_VMAJOR) != VMAJOR) {
    SerialUSB.print("Version mismatch, clearing progress\n");
    clearStoredMoveCounts();
  } else {
    for (int i = 0; i < numLevels; i++) {
      _minMoves[i] = gb.save.get(SAVEINDEX_MOVES + levels[i].saveSlot);
      _totalMoves += _minMoves[i];
    }
  }

  _maxLevelIndex = 0;
  while (isLevelSolved(_maxLevelIndex)) {
    _maxLevelIndex++;
  }

  gb.save.set(SAVEINDEX_VMAJOR, static_cast<int32_t>(VMAJOR));
  gb.save.set(SAVEINDEX_VMINOR, static_cast<int32_t>(VMINOR));
}

void ProgressTracker::dump() {
#ifdef DEVELOPMENT
  SerialUSB.printf(
    "Save file format v%d.%d\n",
    gb.save.get(SAVEINDEX_VMAJOR),
    gb.save.get(SAVEINDEX_VMINOR)
  );
  for (int i = 0; i < numLevels; i++) {
    SerialUSB.printf("Minimum moves level %d = %d\n", (i + 1), _minMoves[i]);
  }
#endif
}

bool ProgressTracker::markLevelSolved(int levelIndex, int numMoves) {
  uint16_t oldMoves = _minMoves[levelIndex];

  // Did this improve current progress?
  if (oldMoves != 0 && oldMoves <= numMoves) return false;

  _totalMoves -= oldMoves;
  _minMoves[levelIndex] = numMoves;
  _totalMoves += numMoves;
  _maxLevelIndex = std::max(_maxLevelIndex, static_cast<uint8_t>(levelIndex + 1));

  gb.save.set(SAVEINDEX_MOVES + levels[levelIndex].saveSlot, numMoves);

  // A first solve does not count as a new level record
  return oldMoves != 0;
}

ProgressTracker progressTracker;
