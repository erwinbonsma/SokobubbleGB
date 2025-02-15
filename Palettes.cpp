#include "Palettes.h"

const Color LBLUE = LIGHTBLUE;
const Color LGREEN = LIGHTGREEN;
const Color DGRAY = DARKGRAY;
const Color DBLUE = DARKBLUE;

const Color palettes[numPalettes][numPaletteColors] = {
  // Default
  { BLACK,  DBLUE,  PURPLE, GREEN,  BROWN,  DGRAY,  GRAY,   WHITE,  RED,    ORANGE, YELLOW, LGREEN, LBLUE,  BLUE,   PINK,   BEIGE },
  // Red
  { BLACK,  PURPLE, PURPLE, GREEN,  BROWN,  DGRAY,  GRAY,   WHITE,  RED,    ORANGE, YELLOW, LGREEN, PINK,   RED,    PINK,   BEIGE },
  // Green
  { BLACK,  DBLUE,  PURPLE, GREEN,  BROWN,  DGRAY,  GRAY,   WHITE,  RED,    ORANGE, YELLOW, LGREEN, LGREEN, GREEN,  PINK,   BEIGE },
  // Blue (happens to match default)
  { BLACK,  DBLUE,  PURPLE, GREEN,  BROWN,  DGRAY,  GRAY,   WHITE,  RED,    ORANGE, YELLOW, LGREEN, LBLUE,  BLUE,   PINK,   BEIGE },
  // Yellow
  { BLACK,  BROWN,  PURPLE, GREEN,  BROWN,  DGRAY,  GRAY,   WHITE,  RED,    ORANGE, YELLOW, LGREEN, YELLOW, ORANGE, PINK,   BEIGE },
  // Any
  { BLACK,  BROWN,  PURPLE, GREEN,  BROWN,  DGRAY,  GRAY,   WHITE,  RED,    ORANGE, YELLOW, LGREEN, WHITE,  GRAY,   PINK,   BEIGE },
};

Color* PALETTE_DEFAULT = const_cast<Color *>(palettes[0]);
