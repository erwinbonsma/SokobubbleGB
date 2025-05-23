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

const int8_t tilesRibbon[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,   -1,   -1,   -1,   -1,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesRibbon[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
};
const ObjectSpec targetsRibbon[] = {
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Green },
};
const ObjectSpec bubblesRibbon[] = {
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 4), .color = ObjectColor::Green },
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
  0x34, 0x13,    0,    0,    0,    0, 0x12, 0x35,
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
  0x32, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x33,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,   -1,    0,    0,   -1,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,   -1,    0,    0,   -1,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x34, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x35,
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

const int8_t tilesSwap[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,   -1,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesSwap[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
};
const ObjectSpec targetsSwap[] = {
  ObjectSpec { .pos = GridPos(6, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesSwap[] = {
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
  0x34, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x35,
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
  0x32, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x33,
  0x16,   -1,   -1,    0,    0,    0,   -1, 0x06,
  0x16,   -1,    0,   -1,    0,    0,    0, 0x06,
  0x16,   -1,   -1,   -1,    0,    0,    0, 0x06,
  0x16,   -1,   -1,   -1,    0,    0,    0, 0x06,
  0x16,    0,   -1,    0,    0,    0,    0, 0x06,
  0x16,    0,   -1,    0,    0,    0,    0, 0x06,
  0x34, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x35,
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

const int8_t tilesRGB2[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x0b, 0x0d,
  0x0f, 0x09,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0, 0x08,   -1,   -1, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x0e, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesRGB2[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Green },
};
const ObjectSpec targetsRGB2[] = {
  ObjectSpec { .pos = GridPos(5, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 2), .color = ObjectColor::Green },
};
const ObjectSpec bubblesRGB2[] = {
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Blue },
};

const int8_t tilesFoursome[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,   -1,   -1, 0x06,
  0x16,    0,    0,    0,   -1,   -1, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesFoursome[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Blue },
};
const ObjectSpec targetsFoursome[] = {
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Any },
};
const ObjectSpec bubblesFoursome[] = {
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Yellow },
};

const int8_t tilesSkull[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x34, 0x13,   -1,   -1,   -1,   -1, 0x12, 0x35,
   -99, 0x16,    0,    0,    0,    0, 0x06,  -99,
   -99, 0x04, 0x07, 0x07, 0x07, 0x07, 0x05,  -99,
};
const ObjectSpec boxesSkull[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Red },
};
const ObjectSpec targetsSkull[] = {
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Green },
};
const ObjectSpec bubblesSkull[] = {
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 6), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Green },
};

const int8_t tilesSpiral[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,   -1,    0,    0, 0x10,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16, 0x10,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x10, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0, 0x10,    0,    0,   -1, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesSpiral[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Blue },
};
const ObjectSpec targetsSpiral[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesSpiral[] = {
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Yellow },
};

const int8_t tilesCenter[] = {
   -99, 0x02, 0x17, 0x17, 0x17, 0x17, 0x03,  -99,
  0x02, 0x15,    0,    0,    0,    0, 0x14, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x04, 0x13,    0,   -1,   -1,    0,    0, 0x06,
   -99, 0x16,    0,    0,    0,    0,    0, 0x06,
   -99, 0x16,    0,    0,    0,    0, 0x12, 0x05,
   -99, 0x04, 0x07, 0x07, 0x07, 0x07, 0x05,  -99,
};
const ObjectSpec boxesCenter[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Red },
};
const ObjectSpec targetsCenter[] = {
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Green },
};
const ObjectSpec bubblesCenter[] = {
  ObjectSpec { .pos = GridPos(4, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Red },
};

const int8_t tilesSquares[] = {
  0x32, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x33,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,   -1,   -1, 0x06,
  0x16,    0,    0,    0,    0,   -1,   -1, 0x06,
  0x34, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x35,
};
const ObjectSpec boxesSquares[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Yellow },
};
const ObjectSpec targetsSquares[] = {
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(6, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 6), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesSquares[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Green },
};

const int8_t tilesReverse[] = {
  0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x03,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,   -1,   -1,   -1,   -1,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
};
const ObjectSpec boxesReverse[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 2), .color = ObjectColor::Red },
};
const ObjectSpec targetsReverse[] = {
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Yellow },
};
const ObjectSpec bubblesReverse[] = {
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Blue },
};

const int8_t tilesCross[] = {
  0x02, 0x17, 0x09, 0x0b, 0x09, 0x0b, 0x17, 0x03,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x0a,    0,    0,    0,    0,    0,    0, 0x3a,
  0x08,   -1,    0,    0,    0,    0,   -1, 0x28,
  0x0a,   -1,    0,    0,    0,    0,   -1, 0x3a,
  0x08,    0,    0,    0,    0,    0,    0, 0x28,
  0x16,    0,    0,   -1,   -1,    0,    0, 0x06,
  0x04, 0x07, 0x29, 0x2b, 0x29, 0x2b, 0x07, 0x05,
};
const ObjectSpec boxesCross[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Yellow },
};
const ObjectSpec targetsCross[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 6), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Blue },
};
const ObjectSpec bubblesCross[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Blue },
};

const int8_t tilesWindmill[] = {
  0x08, 0x0b, 0x17, 0x17, 0x17, 0x17, 0x17, 0x39,
  0x16,    0,    0,   -1,    0,   -1,    0, 0x28,
  0x16,   -1,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x16,   -1,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x0a,    0,   -1,    0,   -1,    0,    0, 0x06,
  0x1b, 0x07, 0x07, 0x07, 0x07, 0x07, 0x29, 0x1a,
};
const ObjectSpec boxesWindmill[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Green },
};
const ObjectSpec targetsWindmill[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 6), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Red },
};
const ObjectSpec bubblesWindmill[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Green },
};

const int8_t tilesWhirly[] = {
  0x32, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x33,
  0x16,   -1,   -1,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,   -1,   -1, 0x06,
  0x34, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x35,
};
const ObjectSpec boxesWhirly[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Green },
};
const ObjectSpec targetsWhirly[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(6, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 6), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 6), .color = ObjectColor::Red },
};
const ObjectSpec bubblesWhirly[] = {
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 6), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 6), .color = ObjectColor::Red },
};

const int8_t tiles3x3[] = {
  0x02, 0x09, 0x0b, 0x17, 0x17, 0x09, 0x0b, 0x03,
  0x0a,   -1,   -1,    0,    0,   -1,   -1, 0x3a,
  0x08,   -1,    0,    0,    0,    0,   -1, 0x28,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x16,    0,    0,    0,    0,    0,    0, 0x06,
  0x0a,    0,    0,   -1,    0,    0,    0, 0x3a,
  0x08,    0,    0,   -1,   -1,    0,    0, 0x28,
  0x04, 0x29, 0x2b, 0x07, 0x07, 0x29, 0x2b, 0x05,
};
const ObjectSpec boxes3x3[] = {
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(5, 4), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 5), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(4, 5), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Red },
};
const ObjectSpec targets3x3[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 2), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 6), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 6), .color = ObjectColor::Green },
};
const ObjectSpec bubbles3x3[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
  ObjectSpec { .pos = GridPos(6, 1), .color = ObjectColor::Blue },
  ObjectSpec { .pos = GridPos(3, 6), .color = ObjectColor::Green },
};

const int8_t tilesTheEnd[] = {
  0x1b, 0x3c, 0x40, 0x38, 0x38, 0x02, 0x39,
   -99, 0x16,    0, 0x0f, 0x2d, 0x0f, 0x39,
   -99, 0x30,    0, 0x0a, 0x0a, 0x24, 0x39,
  0x02, 0x09, 0x22, 0x26, 0x22, 0x26, 0x28,
  0x0f, 0x09, 0x16, 0x16, 0x16, 0x16, 0x1a,
  0x04, 0x29, 0x2a, 0x2a, 0x04, 0x37,  -99,
};
const ObjectSpec boxesTheEnd[] = {
  ObjectSpec { .pos = GridPos(6, 5), .color = ObjectColor::Yellow },
};
const ObjectSpec targetsTheEnd[] = {
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Yellow },
};
const ObjectSpec bubblesTheEnd[] = {};

const int8_t tilesStar[] = {
  0x32, 0x17, 0x17, 0x17, 0x17, 0x17, 0x33,
  0x16,   -1,    0,   -1,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,    0,    0,   -1, 0x06,
  0x16,    0,    0,    0,    0,    0, 0x06,
  0x16,   -1,    0,   -1,    0,   -1, 0x06,
  0x34, 0x07, 0x07, 0x07, 0x07, 0x07, 0x35,
};
const ObjectSpec boxesStar[] = {
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(3, 2), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(3, 4), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(2, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Yellow },
};
const ObjectSpec targetsStar[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(3, 1), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 3), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Any },
  ObjectSpec { .pos = GridPos(3, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Any },
};
const ObjectSpec bubblesStar[] = {
  ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(5, 1), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(4, 4), .color = ObjectColor::Green },
  ObjectSpec { .pos = GridPos(1, 5), .color = ObjectColor::Yellow },
  ObjectSpec { .pos = GridPos(5, 5), .color = ObjectColor::Yellow },
};

const LevelSpec levels[numLevels] = {
  LevelSpec {
    .name = "Bubbles",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesBubbles },
    .player = ObjectSpec { .pos = GridPos(1, 3), .color = ObjectColor::None },
    .saveSlot = 1,
    .numBoxes = 2,
    .numTargets = 2,
    .numBubbles = 2,
    .boxes = boxesBubbles,
    .targets = targetsBubbles,
    .bubbles = bubblesBubbles,
  },
  LevelSpec {
    .name = "Targets",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesTargets },
    .player = ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::None },
    .saveSlot = 2,
    .numBoxes = 2,
    .numTargets = 4,
    .numBubbles = 2,
    .boxes = boxesTargets,
    .targets = targetsTargets,
    .bubbles = bubblesTargets,
  },
  LevelSpec {
    .name = "Order",
    .grid = GridSpec { .w = 8, .h = 6, .tiles = tilesOrder },
    .player = ObjectSpec { .pos = GridPos(4, 2), .color = ObjectColor::None },
    .saveSlot = 3,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 2,
    .boxes = boxesOrder,
    .targets = targetsOrder,
    .bubbles = bubblesOrder,
  },
  LevelSpec {
    .name = "Overlap",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesOverlap },
    .player = ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::None },
    .saveSlot = 4,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 2,
    .boxes = boxesOverlap,
    .targets = targetsOverlap,
    .bubbles = bubblesOverlap,
  },
  LevelSpec {
    .name = "Barrier",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesBarrier },
    .player = ObjectSpec { .pos = GridPos(1, 4), .color = ObjectColor::None },
    .saveSlot = 5,
    .numBoxes = 3,
    .numTargets = 3,
    .numBubbles = 3,
    .boxes = boxesBarrier,
    .targets = targetsBarrier,
    .bubbles = bubblesBarrier,
  },
  LevelSpec {
    .name = "Espresso",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesEspresso },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 6,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesEspresso,
    .targets = targetsEspresso,
    .bubbles = bubblesEspresso,
  },
  LevelSpec {
    .name = "Ribbon",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesRibbon },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 7,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 12,
    .boxes = boxesRibbon,
    .targets = targetsRibbon,
    .bubbles = bubblesRibbon,
  },
  LevelSpec {
    .name = "Star",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesStar },
    .player = ObjectSpec { .pos = GridPos(1, 2), .color = ObjectColor::None },
    .saveSlot = 26,
    .numBoxes = 8,
    .numTargets = 8,
    .numBubbles = 6,
    .boxes = boxesStar,
    .targets = targetsStar,
    .bubbles = bubblesStar,
  },
  LevelSpec {
    .name = "Enclosed",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesEnclosed },
    .player = ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::None },
    .saveSlot = 8,
    .numBoxes = 8,
    .numTargets = 8,
    .numBubbles = 2,
    .boxes = boxesEnclosed,
    .targets = targetsEnclosed,
    .bubbles = bubblesEnclosed,
  },
  LevelSpec {
    .name = "Swap",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesSwap },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 9,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesSwap,
    .targets = targetsSwap,
    .bubbles = bubblesSwap,
  },
  LevelSpec {
    .name = "Coffee",
    .grid = GridSpec { .w = 8, .h = 7, .tiles = tilesCoffee },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 10,
    .numBoxes = 8,
    .numTargets = 8,
    .numBubbles = 4,
    .boxes = boxesCoffee,
    .targets = targetsCoffee,
    .bubbles = bubblesCoffee,
  },
  LevelSpec {
    .name = "Cramped",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesCramped },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::Red },
    .saveSlot = 11,
    .numBoxes = 13,
    .numTargets = 13,
    .numBubbles = 4,
    .boxes = boxesCramped,
    .targets = targetsCramped,
    .bubbles = bubblesCramped,
  },
  LevelSpec {
    .name = "RGB",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesRGB },
    .player = ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::None },
    .saveSlot = 12,
    .numBoxes = 3,
    .numTargets = 3,
    .numBubbles = 3,
    .boxes = boxesRGB,
    .targets = targetsRGB,
    .bubbles = bubblesRGB,
  },
  LevelSpec {
    .name = "RGB2",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesRGB2 },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 14,
    .numBoxes = 6,
    .numTargets = 6,
    .numBubbles = 3,
    .boxes = boxesRGB2,
    .targets = targetsRGB2,
    .bubbles = bubblesRGB2,
  },
  LevelSpec {
    .name = "Foursome",
    .grid = GridSpec { .w = 7, .h = 7, .tiles = tilesFoursome },
    .player = ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::None },
    .saveSlot = 15,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesFoursome,
    .targets = targetsFoursome,
    .bubbles = bubblesFoursome,
  },
  LevelSpec {
    .name = "Skull",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesSkull },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 16,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesSkull,
    .targets = targetsSkull,
    .bubbles = bubblesSkull,
  },
  LevelSpec {
    .name = "Spiral",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesSpiral },
    .player = ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::None },
    .saveSlot = 17,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesSpiral,
    .targets = targetsSpiral,
    .bubbles = bubblesSpiral,
  },
  LevelSpec {
    .name = "Center",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesCenter },
    .player = ObjectSpec { .pos = GridPos(4, 3), .color = ObjectColor::None },
    .saveSlot = 18,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesCenter,
    .targets = targetsCenter,
    .bubbles = bubblesCenter,
  },
  LevelSpec {
    .name = "Squares",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesSquares },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 19,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 4,
    .boxes = boxesSquares,
    .targets = targetsSquares,
    .bubbles = bubblesSquares,
  },
  LevelSpec {
    .name = "Reverse",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesReverse },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 20,
    .numBoxes = 4,
    .numTargets = 4,
    .numBubbles = 8,
    .boxes = boxesReverse,
    .targets = targetsReverse,
    .bubbles = bubblesReverse,
  },
  LevelSpec {
    .name = "Cross",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesCross },
    .player = ObjectSpec { .pos = GridPos(2, 2), .color = ObjectColor::None },
    .saveSlot = 21,
    .numBoxes = 8,
    .numTargets = 8,
    .numBubbles = 4,
    .boxes = boxesCross,
    .targets = targetsCross,
    .bubbles = bubblesCross,
  },
  LevelSpec {
    .name = "Windmill",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesWindmill },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 22,
    .numBoxes = 8,
    .numTargets = 8,
    .numBubbles = 4,
    .boxes = boxesWindmill,
    .targets = targetsWindmill,
    .bubbles = bubblesWindmill,
  },
  LevelSpec {
    .name = "Whirly",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tilesWhirly },
    .player = ObjectSpec { .pos = GridPos(1, 1), .color = ObjectColor::None },
    .saveSlot = 23,
    .numBoxes = 8,
    .numTargets = 8,
    .numBubbles = 4,
    .boxes = boxesWhirly,
    .targets = targetsWhirly,
    .bubbles = bubblesWhirly,
  },
  LevelSpec {
    .name = "3x3",
    .grid = GridSpec { .w = 8, .h = 8, .tiles = tiles3x3 },
    .player = ObjectSpec { .pos = GridPos(3, 3), .color = ObjectColor::None },
    .saveSlot = 24,
    .numBoxes = 9,
    .numTargets = 9,
    .numBubbles = 3,
    .boxes = boxes3x3,
    .targets = targets3x3,
    .bubbles = bubbles3x3,
  },
  LevelSpec {
    .name = "The end",
    .grid = GridSpec { .w = 7, .h = 6, .tiles = tilesTheEnd },
    .player = ObjectSpec { .pos = GridPos(2, 1), .color = ObjectColor::Yellow },
    .saveSlot = 25,
    .numBoxes = 1,
    .numTargets = 1,
    .numBubbles = 0,
    .boxes = boxesTheEnd,
    .targets = targetsTheEnd,
    .bubbles = bubblesTheEnd,
  },
};
