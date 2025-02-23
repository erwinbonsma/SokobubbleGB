#include "Levels.h"

const int8_t tilesBubbles[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0, 0x08,    0, 0x08,    0, 0x06,
  0x16,    0, 0x16,    0, 0x16,   -1, 0x06,
  0x16,    0, 0x24, 0x17, 0x2e, 0x17, 0x0d,
  0x16,    0,    0,    0,    0,   -1, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesBubbles[] = {
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Red },
};
const ObjectSpec targetsBubbles[] = {
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Any },
};
const ObjectSpec bubblesBubbles[] = {
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
};

const int8_t tilesTargets[] = {
  0x02, 0x17, 0x0c, 0x17, 0x0c, 0x17, 0x03,
  0x16,   -1, 0x0a,    0, 0x0a,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1, 0x08,    0, 0x08,   -1, 0x06,
  0x04, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x05,
};
const ObjectSpec boxesTargets[] = {
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Red },
};
const ObjectSpec targetsTargets[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Red },
};
const ObjectSpec bubblesTargets[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Red },
};

const int8_t tilesOrder[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x0f, 0x09,    0,    0,    0,    0, 0x0b, 0x0d,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesOrder[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
};
const ObjectSpec targetsOrder[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesOrder[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Blue },
};

const int8_t tilesOverlap[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x10, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,   -1,   -1, 0x06,
  0x16,    0,    0, 0x10,    0,   -1,   -1, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesOverlap[] = {
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
};
const ObjectSpec targetsOverlap[] = {
  ObjectSpec { .pos = GridPos(6, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesOverlap[] = {
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Blue },
};

const int8_t tilesSwap[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesSwap[] = {
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Blue },
};
const ObjectSpec targetsSwap[] = {
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesSwap[] = {
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
};

const int8_t tilesBarrier[] = {
  0x02, 0x17, 0x17, 0x17, 0x03,  -99,  -99,  -99,
  0x16,    0,    0,    0, 0x14, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x0f, 0x09,    0, 0x01,    0,    0, 0x0b, 0x0d,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesBarrier[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Blue },
};
const ObjectSpec targetsBarrier[] = {
  ObjectSpec { .pos = GridPos(6, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 5), .color = ObjectColor::Red },
};
const ObjectSpec bubblesBarrier[] = {
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Red },
};

const int8_t tilesEspresso[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x2a, 0x13,    0,    0,    0,    0, 0x12, 0x2b,
   -99, 0x04, 0x07, 0x07, 0x07, 0x07, 0x05,  -99,
};
const ObjectSpec boxesEspresso[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Red },
};
const ObjectSpec targetsEspresso[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesEspresso[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Blue },
};

const int8_t tilesEnclosed[] = {
  0x28, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x29,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,   -1,    0,    0,   -1,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,   -1,    0,    0,   -1,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x2a, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x2b,
};
const ObjectSpec boxesEnclosed[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Red },
};
const ObjectSpec targetsEnclosed[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
};
const ObjectSpec bubblesEnclosed[] = {
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
};

const int8_t tilesSwap2[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesSwap2[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
};
const ObjectSpec targetsSwap2[] = {
  ObjectSpec { .pos = GridPos(6, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesSwap2[] = {
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
};

const int8_t tilesCoffee[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x2a, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x2b,
};
const ObjectSpec boxesCoffee[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Red },
};
const ObjectSpec targetsCoffee[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Red },
};
const ObjectSpec bubblesCoffee[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Blue },
};

const int8_t tilesCramped[] = {
  0x28, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x29,
  0x16,   -1,   -1,    0,    0,    0,   -1, 0x06,
  0x16,   -1,    0,   -1,    0,    0,    0, 0x06,
  0x16,   -1,   -1,   -1,    0,    0,    0, 0x06,
  0x16,   -1,   -1,   -1,    0,    0,    0, 0x06,
  0x16,    0,   -1,    0,    0,    0,    0, 0x06,
  0x16,    0,   -1,    0,    0,    0,    0, 0x06,
  0x2a, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x2b,
};
const ObjectSpec boxesCramped[] = {
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Red },
};
const ObjectSpec targetsCramped[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 6), .color = ObjectColor::Red },
};
const ObjectSpec bubblesCramped[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Red },
};

const int8_t tilesRGB[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,   -1,   -1, 0x06,
  0x16,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesRGB[] = {
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
};
const ObjectSpec targetsRGB[] = {
  ObjectSpec { .pos = GridPos(4, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
};
const ObjectSpec bubblesRGB[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Blue },
};

const LevelSpec levels[numLevels] = {
  LevelSpec {
    .name = "Bubbles",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesBubbles },
    .player = ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::None },
    .numBoxes = 2,
    .boxes = boxesBubbles,
    .numTargets = 2,
    .targets = targetsBubbles,
    .numBubbles = 2,
    .bubbles = bubblesBubbles,
  },
  LevelSpec {
    .name = "Targets",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesTargets },
    .player = ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::None },
    .numBoxes = 2,
    .boxes = boxesTargets,
    .numTargets = 4,
    .targets = targetsTargets,
    .numBubbles = 2,
    .bubbles = bubblesTargets,
  },
  LevelSpec {
    .name = "Order",
    .grid = GridSpec { .w = 8, .h = 6, .tiles = tilesOrder },
    .player = ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::None },
    .numBoxes = 4,
    .boxes = boxesOrder,
    .numTargets = 4,
    .targets = targetsOrder,
    .numBubbles = 2,
    .bubbles = bubblesOrder,
  },
  LevelSpec {
    .name = "Overlap",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesOverlap },
    .player = ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::None },
    .numBoxes = 4,
    .boxes = boxesOverlap,
    .numTargets = 4,
    .targets = targetsOverlap,
    .numBubbles = 2,
    .bubbles = bubblesOverlap,
  },
  LevelSpec {
    .name = "Swap",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesSwap },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .numBoxes = 4,
    .boxes = boxesSwap,
    .numTargets = 4,
    .targets = targetsSwap,
    .numBubbles = 4,
    .bubbles = bubblesSwap,
  },
  LevelSpec {
    .name = "Barrier",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesBarrier },
    .player = ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::None },
    .numBoxes = 3,
    .boxes = boxesBarrier,
    .numTargets = 3,
    .targets = targetsBarrier,
    .numBubbles = 3,
    .bubbles = bubblesBarrier,
  },
  LevelSpec {
    .name = "Espresso",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesEspresso },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .numBoxes = 4,
    .boxes = boxesEspresso,
    .numTargets = 4,
    .targets = targetsEspresso,
    .numBubbles = 4,
    .bubbles = bubblesEspresso,
  },
  LevelSpec {
    .name = "Enclosed",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesEnclosed },
    .player = ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::None },
    .numBoxes = 8,
    .boxes = boxesEnclosed,
    .numTargets = 8,
    .targets = targetsEnclosed,
    .numBubbles = 2,
    .bubbles = bubblesEnclosed,
  },
  LevelSpec {
    .name = "Swap 2",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesSwap2 },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .numBoxes = 4,
    .boxes = boxesSwap2,
    .numTargets = 4,
    .targets = targetsSwap2,
    .numBubbles = 4,
    .bubbles = bubblesSwap2,
  },
  LevelSpec {
    .name = "Coffee",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesCoffee },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .numBoxes = 8,
    .boxes = boxesCoffee,
    .numTargets = 8,
    .targets = targetsCoffee,
    .numBubbles = 4,
    .bubbles = bubblesCoffee,
  },
  LevelSpec {
    .name = "Cramped",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesCramped },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
    .numBoxes = 13,
    .boxes = boxesCramped,
    .numTargets = 13,
    .targets = targetsCramped,
    .numBubbles = 4,
    .bubbles = bubblesCramped,
  },
  LevelSpec {
    .name = "RGB",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesRGB },
    .player = ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::None },
    .numBoxes = 3,
    .boxes = boxesRGB,
    .numTargets = 3,
    .targets = targetsRGB,
    .numBubbles = 3,
    .bubbles = bubblesRGB,
  },
};
