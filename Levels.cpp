#include "Levels.h"

const uint8_t tilesBubbles[] = {
  0x02, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0, 0x08,    0, 0x08,    0, 0x06,
  0x06,    0, 0x06,    0, 0x06,    0, 0x06,
  0x06,    0, 0x04, 0x07, 0x0e, 0x07, 0x0d,
  0x06,    0,    0,    0,    0,    0, 0x06,
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

const uint8_t tilesTargets[] = {
  0x02, 0x07, 0x0c, 0x07, 0x0c, 0x07, 0x03,
  0x06,    0, 0x0a,    0, 0x0a,    0, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0,    0,    0,    0,    0, 0x06,
  0x06,    0, 0x08,    0, 0x08,    0, 0x06,
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
};
