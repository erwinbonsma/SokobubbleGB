#pragma once

#include "Utils.h"

struct GridSpec {
  const uint8_t w;
  const uint8_t h;
  const int8_t* tiles;
};

struct ObjectSpec {
  const GridPos pos;
  const ObjectColor color;
};

struct LevelSpec {
  const char* name;
  const GridSpec grid;

  const ObjectSpec player;

  // Used for storing progress. Helps to retain scores when levels are
  // re-ordered or only a few levels are changed.
  const uint8_t saveSlot;

  const uint8_t numBoxes;
  const uint8_t numTargets;
  const uint8_t numBubbles;

  const ObjectSpec* boxes;
  const ObjectSpec* targets;
  const ObjectSpec* bubbles;
};

constexpr int maxBoxes = 13;
constexpr int numLevels = 17;
extern const LevelSpec levels[numLevels];
