#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"

int main(int argc, char **argv)
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED, // x position window will apear on screen
        SDL_WINDOWPOS_UNDEFINED, // y position window will apear on screen
        C8_WIDTH*WINDOW_SCALE, 
        C8_HEIGHT*WINDOW_SCALE,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);


    char * mamamia = "240 vezes AIIIII";
    printf("hello world!\n");
    printf("incrivel posso debugar no terminal ");
    printf(mamamia);


    while (1){

        SDL_Event event;
        while(SDL_PollEvent(&event)){

            if (event.type ==SDL_QUIT){
                goto out;
            }
            
        }

        // ----- screen reset ------ //
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // ------------------------- //
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_Rect r;
        r.x = 0; r.y = 0; // position on window
        r.w = 40; r.h = 40; // size of rect
        SDL_RenderFillRect(renderer, &r);
        SDL_RenderPresent(renderer);
    }
    


    
    
out:

    SDL_DestroyWindow(window);
    return 0;
}
