#include <assert.h>
#include "chip8screen.h"
#define FIRST_BIT 0b10000000

static void chip8_is_screen_in_bounds(int x, int y)
{

    assert(x >= 0 && x < C8_SCREEN_WIDTH && y >= 0 && y < C8_SCREEN_HEIGHT);
}

void chip8_screen_set(struct chip8_screen *screen, int x, int y)
{

    chip8_is_screen_in_bounds(x, y);
    screen->pxls[y][x] = true;
}

bool chip8_screen_is_set(struct chip8_screen *screen, int x, int y)
{

    chip8_is_screen_in_bounds(x, y);
    return screen->pxls[y][x];
}

bool chip8_screen_draw_sprite(struct chip8_screen *screen, int x, int y, const char *sprite, int num)
{

    bool sprite_colision = false;

    for (int ly = 0; ly < num; ly++)
    {

        char c = sprite[ly];

        for (int lx = 0; lx < 8; lx++)
        {

            if ((c & (FIRST_BIT >> lx)) == 0)
            {
                continue;
            }

            if (screen->pxls[(ly + y) % C8_SCREEN_HEIGHT][(lx + x) % C8_SCREEN_WIDTH])
            {
                sprite_colision = true;
                  
            }
            

            screen->pxls[(ly + y) % C8_SCREEN_HEIGHT][(lx + x) % C8_SCREEN_WIDTH] ^= true;
        }
    }

    return sprite_colision;
}
