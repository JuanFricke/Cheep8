#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#define Sleep sleep
#endif
#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8keyboard.h"

const char keyboard_map[C8_MAX_KEYS] = {
    SDLK_0, SDLK_1, SDLK_2, SDLK_3,
    SDLK_4, SDLK_5, SDLK_6, SDLK_7,
    SDLK_8, SDLK_9, SDLK_a, SDLK_b,
    SDLK_c, SDLK_d, SDLK_e, SDLK_f};

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("provide a file to load \n");
        return -1;
    }

    const char* filename = argv[1];
    printf("the filename to load is: %s\n" , filename);

    FILE* f = fopen(filename, "rb");

    if(!f){
        printf("Failure to open file");
        return -1;
    }

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char buf[file_size];
    int res = fread(buf, file_size, 1, f);

    if (res != 1){
        printf("Failure to read from file");
        return -1;
    }

    
    struct chip8 chip8;
    chip8_init(&chip8);
    chip8_load(&chip8, buf, file_size);
    

    chip8_screen_draw_sprite(&chip8.screen, 32, 30, &chip8.ram.ram[0x00], 5);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED, // x position window will apear on screen
        SDL_WINDOWPOS_UNDEFINED, // y position window will apear on screen
        C8_SCREEN_WIDTH * WINDOW_SCALE,
        C8_SCREEN_HEIGHT * WINDOW_SCALE,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);

    bool quit = false;
    while (!quit)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {

            case SDL_QUIT:
                //goto out;
                quit = true;
                break;

            case SDL_KEYDOWN:
            {

                char real_key = event.key.keysym.sym;
                int key = chip8_keyboard_map(keyboard_map, real_key);
                if (key != -1)
                {
                    chip8_key_press(&chip8.keyboard, key);
                    printf("fuck ");
                }
            }
            break;

            case SDL_KEYUP:
            {

                char real_key = event.key.keysym.sym;
                int key = chip8_keyboard_map(keyboard_map, real_key);
                if (key != -1)
                {
                    chip8_key_unpress(&chip8.keyboard, key);
                    printf("yeah ");
                }
            }

            break;
            }
        }

        // ----- screen reset ------ //

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 10, 255, 20, 0); // screen color

        // ------------------------- //

        for (int x = 0; x < C8_SCREEN_WIDTH; x++)
        {
            for (int y = 0; y < C8_SCREEN_HEIGHT; y++)
            {
                if (chip8_screen_is_set(&chip8.screen, x, y))
                {
                    SDL_Rect r;
                    // position on window
                    {
                        r.x = x * WINDOW_SCALE;
                        r.y = y * WINDOW_SCALE;
                    }
                    // size of rect
                    {
                        r.w = WINDOW_SCALE;
                        r.h = WINDOW_SCALE;
                    }
                    SDL_RenderFillRect(renderer, &r);
                }
            }
        }

        SDL_RenderPresent(renderer);
        if (chip8.registers.delayTimer > 0);

        {
            Sleep(100);
            chip8.registers.delayTimer -=1;
            
        }

        if (chip8.registers.soundTimer > 0){
            Beep(2500, 100 * chip8.registers.soundTimer);
            chip8.registers.soundTimer -= 1;
        }

        unsigned short opcode = chip8_ram_get_short(&chip8.ram, chip8.registers.pc);
        chip8_exec(&chip8, opcode);
        chip8.registers.pc += 2;
    }

out:

    SDL_DestroyWindow(window);
    return 0;
}
