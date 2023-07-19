#ifndef CHIP8MEMORY_H
#define CHIP8MEMORY_H

#include "config.h"

struct chip8_memory {
    unsigned char memory[C8_MEM_SIZE];

};

void chip8_memory_set(struct chip8_memory* memory, int index, unsigned char val);
unsigned char chip8_memory_get(struct chip8_memory* memory, int index);



#endif