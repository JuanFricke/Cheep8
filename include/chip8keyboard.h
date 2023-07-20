#ifndef CHIP8KEYBOARD_H
#define CHIP8KEYBOARD_H

#include "config.h"
#include <stdbool.h>
struct chip8_keyboard
{
     bool keyboard[C8_MAX_KEYS];
};

int chip8_keyboard_map(const char* map, char real_key);
void chip8_key_press(struct chip8_keyboard* keyboard, int key);
void chip8_key_unpress(struct chip8_keyboard* keyboard, int key);
bool chip8_key_is_pressed(struct chip8_keyboard* keyboard, int key);


#endif