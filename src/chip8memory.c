#include "chip8memory.h"
#include <assert.h>

static void chip8_is_ram_in_bounds(int i)
{
    assert(i >= 0 && i < C8_RAM_SIZE);
}

void chip8_ram_set(struct chip8_ram *ram, int index, unsigned char val)
{

    chip8_is_ram_in_bounds(index);
    ram->ram[index] = val;
}
unsigned char chip8_ram_get(struct chip8_ram *ram, int index)
{
    return ram->ram[index];
}
