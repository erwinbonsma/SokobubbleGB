#pragma once

#include <cstdint>

#include "Levels.h"

class ProgressTracker {
  uint16_t _minMoves[numLevels];
  uint16_t _totalMoves;
  uint8_t _maxLevelIndex;

  void clearStoredMoveCounts();

public:
  void init();
  void dump();

  int getMaxLevelIndex() const { return _maxLevelIndex; }
  int getTotalMoves() const { return _totalMoves; }
  int getLevelMinMoves(int levelIndex) const { return _minMoves[levelIndex]; }
  bool isLevelSolved(int levelIndex) const { return _minMoves[levelIndex] != 0; }

  // Returns true if this beat the standing minimum move count
  bool markLevelSolved(int levelIndex, int numMoves);
};

extern ProgressTracker progressTracker;