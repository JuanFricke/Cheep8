#ifndef CHIP8REGISTERS_H
#define CHIP8REGISTERS_H

#include "config.h"
struct chip8_registers
{
    unsigned char v[C8_DATA_REGISTERS];
    unsigned short I;
    unsigned char delayTimer;
    unsigned char soundTimer;
    unsigned short pc;
    unsigned char sp;
};

#endif