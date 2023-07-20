#ifndef CHIP8SCREEN_H
#define CHIP8SCREEN_H

#include "config.h"
#include <stdbool.h>
struct chip8_screen
{
    bool pxls[C8_SCREEN_HEIGHT][C8_SCREEN_WIDTH];
};

void chip8_screen_set(struct chip8_screen* screen, int x, int y);
bool chip8_screen_is_set(struct chip8_screen* screen, int x, int y );
#endif