#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8keyboard.h"
#include "chip8screen.h"


const char keyboard_map[C8_MAX_KEYS] = {
    SDLK_0, SDLK_1, SDLK_2, SDLK_3,
    SDLK_4, SDLK_5, SDLK_6, SDLK_7,
    SDLK_8, SDLK_9, SDLK_a, SDLK_b,
    SDLK_c, SDLK_d, SDLK_e, SDLK_f
};

int main(int argc, char **argv){

    struct chip8 chip8;

    chip8_init(&chip8);

    
    chip8_screen_set(&chip8.screen, 10,1);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED, // x position window will apear on screen
        SDL_WINDOWPOS_UNDEFINED, // y position window will apear on screen
        C8_SCREEN_WIDTH*WINDOW_SCALE, 
        C8_SCREEN_HEIGHT*WINDOW_SCALE,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);



    while (1){

        SDL_Event event;
        while(SDL_PollEvent(&event)){


            switch(event.type){

                case SDL_QUIT:
                    goto out;
                break;

                case SDL_KEYDOWN:{

                    char real_key = event.key.keysym.sym;
                    int key = chip8_keyboard_map(keyboard_map, real_key);
                    if (key != -1)
                    {
                        chip8_key_press(&chip8.keyboard, key);
                        printf("fuck ");
                    }
                    
                }
                break;

                case SDL_KEYUP:{
                    
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
        SDL_SetRenderDrawColor(renderer, 10, 255, 20, 0.1); // screen color

        // ------------------------- //

        for (int x = 0; x < C8_SCREEN_WIDTH; x++)
        {
            for (int y = 0; y < C8_SCREEN_HEIGHT; y++)
            {
                if (chip8_screen_is_set(&chip8.screen, x, y))
                {
                    SDL_Rect r;
                    // position on window
                    {r.x = x*WINDOW_SCALE; r.y = y*WINDOW_SCALE;} 
                    // size of rect
                    {r.w = WINDOW_SCALE; r.h = WINDOW_SCALE;} 
                    SDL_RenderFillRect(renderer, &r);
                    
                }
                
                
            }
            
        }
        
        SDL_RenderPresent(renderer);
        
    }
    


    
    
out:

    SDL_DestroyWindow(window);
    return 0;
}
