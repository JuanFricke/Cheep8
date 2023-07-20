
#include "chip8keyboard.h"
#include <assert.h>

static void chip8_is_kb_in_bounds(int key){

    assert(key >=0 && key < C8_MAX_KEYS);
}
int chip8_keyboard_map(const char* map, char real_key){

    for (int i = 0; i < C8_MAX_KEYS; i++){
        if (map[i] == real_key){
            return i;
        }
    }
    return -1;

}

void chip8_key_press(struct chip8_keyboard* keyboard, int key){

    keyboard->keyboard[key] = true;
}
void chip8_key_unpress(struct chip8_keyboard* keyboard, int key){

    keyboard->keyboard[key] = false;
}
bool chip8_key_is_pressed(struct chip8_keyboard* keyboard, int key){
    return keyboard->keyboard[key];
}
