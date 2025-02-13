#pragma once

#include <Gamebuino-Meta.h>

const uint8_t numPalettes = 6;

const uint8_t numPaletteColors = 16;
extern const Color palettes[numPalettes][numPaletteColors];

extern Color* PALETTE_DEFAULT;
