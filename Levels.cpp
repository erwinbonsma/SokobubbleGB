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
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Green }, // TEMP
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Yellow }, // TEMP
};
const ObjectSpec targetsBubbles[] = {
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Any },
};
const ObjectSpec bubblesBubbles[] = {
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
};

const LevelSpec levels[numLevels] = {
  LevelSpec {
    .name = "Bubbles",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesBubbles },
    .startPos = GridPos(1, 1),
    .numBoxes = 4,
    .boxes = boxesBubbles,
    .numTargets = 2,
    .targets = targetsBubbles,
    .numBubbles = 2,
    .bubbles = bubblesBubbles,
  }
};
