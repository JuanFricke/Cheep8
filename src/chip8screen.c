#include <assert.h>
#include "chip8screen.h"


static void chip8_is_screen_in_bounds(int x, int y){

    assert(x >= 0 && x < C8_SCREEN_WIDTH && y >= 0 && y < C8_SCREEN_HEIGHT);
}

void chip8_screen_set(struct chip8_screen* screen, int x, int y){
    
    chip8_is_screen_in_bounds(x,y);
    screen->pxls[y][x] = true;
}

bool chip8_screen_is_set(struct chip8_screen* screen, int x, int y ){
    
    chip8_is_screen_in_bounds(x,y);
    return screen->pxls[y][x];
}
