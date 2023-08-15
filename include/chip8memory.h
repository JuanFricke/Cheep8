#ifndef CHIP8MEMORY_H
#define CHIP8MEMORY_H

#include "config.h"

struct chip8_ram
{
    unsigned char ram[C8_RAM_SIZE];
};

void chip8_ram_set(struct chip8_ram *ram, int index, unsigned char val);
unsigned char chip8_ram_get(struct chip8_ram *ram, int index);
unsigned short chip8_ram_get_short(struct chip8_ram *ram, int index);

#endif