#include "Images.h"

const uint8_t PLAYER_DATA[] = {
    // metadata
    8,    // frame width
    8,    // frame height
    10,   // frames (lower byte)
    0,    // frames (upper byte)
    0,    // frame loop
    0x5,  // transparent color
    1,    // indexed color mode

    // frame 1/10
    0x55, 0x55, 0x55, 0x55,
    0x54, 0x00, 0x00, 0x45,
    0x54, 0x00, 0x00, 0x45,
    0x56, 0x07, 0x60, 0x65,
    0x54, 0x06, 0x60, 0x45,
    0x54, 0x00, 0x00, 0x45,
    0x56, 0x00, 0x00, 0x65,
    0x55, 0x55, 0x55, 0x55,

    // frame 2/10
    0x55, 0x55, 0x55, 0x55,
    0x54, 0x00, 0x00, 0x45,
    0x56, 0x00, 0x00, 0x65,
    0x54, 0x07, 0x60, 0x45,
    0x54, 0x06, 0x60, 0x45,
    0x56, 0x00, 0x00, 0x65,
    0x54, 0x00, 0x00, 0x45,
    0x55, 0x55, 0x55, 0x55,

    // frame 3/10
    0x55, 0x55, 0x55, 0x55,
    0x56, 0x00, 0x00, 0x65,
    0x54, 0x00, 0x00, 0x45,
    0x54, 0x07, 0x60, 0x45,
    0x56, 0x06, 0x60, 0x65,
    0x54, 0x00, 0x00, 0x45,
    0x54, 0x00, 0x00, 0x45,
    0x55, 0x55, 0x55, 0x55,

    // frame 4/10
    0x55, 0x54, 0x55, 0x55,
    0x55, 0x40, 0x00, 0x55,
    0x56, 0x00, 0x00, 0x05,
    0x54, 0x07, 0x60, 0x04,
    0x40, 0x06, 0x60, 0x45,
    0x50, 0x00, 0x00, 0x65,
    0x55, 0x00, 0x04, 0x55,
    0x55, 0x55, 0x45, 0x55,

    // frame 5/10
    0x55, 0x55, 0x45, 0x55,
    0x55, 0x64, 0x00, 0x55,
    0x54, 0x00, 0x00, 0x05,
    0x40, 0x07, 0x60, 0x05,
    0x50, 0x06, 0x60, 0x04,
    0x50, 0x00, 0x00, 0x45,
    0x55, 0x00, 0x46, 0x55,
    0x55, 0x54, 0x55, 0x55,

    // frame 6/10
    0x55, 0x55, 0x55, 0x55,
    0x54, 0x46, 0x44, 0x65,
    0x50, 0x00, 0x00, 0x05,
    0x50, 0x07, 0x60, 0x05,
    0x50, 0x06, 0x60, 0x05,
    0x50, 0x00, 0x00, 0x05,
    0x54, 0x46, 0x44, 0x65,
    0x55, 0x55, 0x55, 0x55,

    // frame 7/10
    0x55, 0x55, 0x55, 0x55,
    0x54, 0x64, 0x46, 0x45,
    0x50, 0x00, 0x00, 0x05,
    0x50, 0x07, 0x60, 0x05,
    0x50, 0x06, 0x60, 0x05,
    0x50, 0x00, 0x00, 0x05,
    0x54, 0x64, 0x46, 0x45,
    0x55, 0x55, 0x55, 0x55,

    // frame 8/10
    0x55, 0x55, 0x55, 0x55,
    0x56, 0x44, 0x64, 0x45,
    0x50, 0x00, 0x00, 0x05,
    0x50, 0x07, 0x60, 0x05,
    0x50, 0x06, 0x60, 0x05,
    0x50, 0x00, 0x00, 0x05,
    0x56, 0x44, 0x64, 0x45,
    0x55, 0x55, 0x55, 0x55,

    // frame 9/10
    0x55, 0x54, 0x55, 0x55,
    0x55, 0x00, 0x46, 0x55,
    0x50, 0x00, 0x00, 0x45,
    0x50, 0x07, 0x60, 0x04,
    0x40, 0x06, 0x60, 0x05,
    0x54, 0x00, 0x00, 0x05,
    0x55, 0x64, 0x00, 0x55,
    0x55, 0x55, 0x45, 0x55,

    // frame 10/10
    0x55, 0x55, 0x45, 0x55,
    0x55, 0x00, 0x04, 0x55,
    0x50, 0x00, 0x00, 0x65,
    0x40, 0x07, 0x60, 0x45,
    0x54, 0x06, 0x60, 0x04,
    0x56, 0x00, 0x00, 0x05,
    0x55, 0x40, 0x00, 0x55,
    0x55, 0x54, 0x55, 0x55
};
Image playerImage(PLAYER_DATA);
