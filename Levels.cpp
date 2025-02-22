#include "Levels.h"

const int8_t tilesBubbles[] = {
  0x02, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0, 0x08,    0, 0x08,    0, 0x06,
  0x06,    0, 0x06,    0, 0x06,   -1, 0x06,
  0x06,    0, 0x04, 0x07, 0x0e, 0x07, 0x0d,
  0x06,    0,    0,    0,    0,   -1, 0x06,
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
  0x02, 0x07, 0x0c, 0x07, 0x0c, 0x07, 0x03,
  0x06,   -1, 0x0a,    0, 0x0a,   -1, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,   -1, 0x08,    0, 0x08,   -1, 0x06,
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
  0x02, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
  0x06,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x0f, 0x09,    0,    0,    0,    0, 0x0b, 0x0d,
  0x06,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
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
  0x02, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x10, 0x06,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,   -1,   -1, 0x06,
  0x06,    0,    0, 0x10,    0,   -1,   -1, 0x06,
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
  0x02, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
  0x06,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x06,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0,    0, 0x06,
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
  0x02, 0x07, 0x07, 0x07, 0x03,  -99,  -99,  -99,
  0x06,    0,    0,    0, 0x04, 0x07, 0x07, 0x03,
  0x06,    0,    0,    0,    0,    0,   -1, 0x06,
  0x0f, 0x09,    0, 0x01,    0,    0, 0x0b, 0x0d,
  0x06,    0,    0,    0,    0,    0,   -1, 0x06,
  0x06,    0,    0,    0,    0,    0,   -1, 0x06,
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

const LevelSpec levels[numLevels] = {
  LevelSpec {
    .name = "Bubbles",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesBubbles },
    .startPos = GridPos(1, 3),
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
    .startPos = GridPos(3, 3),
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
    .startPos = GridPos(4, 2),
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
    .startPos = GridPos(2, 2),
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
    .startPos = GridPos(1, 1),
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
    .startPos = GridPos(1, 4),
    .numBoxes = 3,
    .boxes = boxesBarrier,
    .numTargets = 3,
    .targets = targetsBarrier,
    .numBubbles = 3,
    .bubbles = bubblesBarrier,
  },
};
