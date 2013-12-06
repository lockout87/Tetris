#include "tetris.h"

SDL_Surface *loadImage(string fileName)
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;


    loadedImage = SDL_LoadBMP(fileName.c_str());
    if (loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        if (optimizedImage != NULL)
        {
            Uint32 colorKey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorKey);
            SDL_FreeSurface(loadedImage);
        }
    }
    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, NULL, destination, &offset);
}

