#ifndef SDL_CORE_H_INCLUDED
#define SDL_CORE_H_INCLUDED

#include <SDL.h>

void InitializeGraphics()
{
        if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
        {
                printf("\nInitialized SDL");
        }
}

#endif // SDL_CORE_H_INCLUDED
