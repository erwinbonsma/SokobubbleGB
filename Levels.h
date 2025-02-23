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

  const uint8_t numBoxes;
  const ObjectSpec* boxes;
  
  const uint8_t numTargets;
  const ObjectSpec* targets;

  const uint8_t numBubbles;
  const ObjectSpec* bubbles;
};

constexpr int maxBoxes = 13;
constexpr int numLevels = 12;
extern const LevelSpec levels[numLevels];
