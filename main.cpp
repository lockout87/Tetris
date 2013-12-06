#include "tetris.h"

const int SCREEN_WIDTH = 704;
const int SCREEN_HEIGHT = 576;
const int SCREEN_BPP = 32;
const string BACKGROUND_IMAGE = "background.bmp";
const string PLAYBOARD = "playboard.bmp";
const string SCOREBOARD = "scoreboard.bmp";

const string BLOCK_IMAGE = "block.bmp";
const int BLOCK_SIZE = 32;

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *playboard = NULL;
SDL_Surface *scoreboard = NULL;

SDL_Event *keypress;

/*
struct blocks
{
        SDL_Rect box;
        SDL_Surface *bIMG;
        bool active, upDown, leftRight;
        int lastMove;

        void blockMover()
    {
        Uint8 *keystate = SDL_GetKeyState(NULL);
        if (keystate[ SDLK_w])
        {
            box.y -= 4;
            lastMove = 1;
            upDown = true;
            leftRight = false;
        }
        if (keystate[ SDLK_s])
        {
            box.y += 4;
            lastMove = 2;
            upDown = true;
            leftRight = false;
        }
        if (keystate[ SDLK_a])
        {
            box.x -= 1;
            lastMove = 3;
            upDown = false;
            leftRight = true;
        }
        if (keystate [SDLK_d])
        {
            box.x +=4;
            lastMove = 4;
            upDown = false;
            leftRight = true;
        }
    }
/*       else
        {
            switch (lastMove)void wormMover()
    {
        Uint8 *keystate = SDL_GetKeyState(NULL);
        if (keystate[ SDLK_w])
        {
            box.y -= 4;
            lastMove = 1;
            upDown = true;
            leftRight = false;
        }
        if (keystate[ SDLK_s])
        {
            box.y += 4;
            lastMove = 2;
            upDown = true;
            leftRight = false;
        }
        if (keystate[ SDLK_a])
        {
            box.x -= 1;
            lastMove = 3;
            upDown = false;
            leftRight = true;
        }
        if (keystate [SDLK_d])
        {
            box.x +=4;
            lastMove = 4;
            upDown = false;
            leftRight = true;
        }
/*        else
        {
            switch (lastMove)
            {
            case 1:
                {
                    box.y -= 1;
                    break;
                }
            case 2:
                {
                    box.y += 1;
                    break;
                }
            case 3:
                {
                    box.x -= 1;
                    break;
                }
            case 4:
                {
                    box.x += 1;
                    break;
                }
            default: ;
            }
        }


    blocks(int x, int y)
    blocks{
        box.x = x;
        box.y = y;
        box.h = x + BLOCK_SIZE;
        box.w = y + BLOCK_SIZE;
        leftRight = false;
        upDown = true;
        lastMove = 1;

        bIMG = loadImage(BLOCK_IMAGE);
    }
};
*/
int main ( int argc, char** argv )
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        return -1;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
    {
        return -1;
    }

    SDL_WM_SetCaption("Tetris", NULL);

    background = loadImage(BACKGROUND_IMAGE);
    playboard = loadImage(PLAYBOARD);
    scoreboard = loadImage(SCOREBOARD);


    applySurface(0,0, background, screen);
    applySurface(0,0, playboard, screen);
    applySurface(352, 0, scoreboard, screen);
    if (SDL_Flip(screen) == -1)
        {
            return -1;
        }

    SDL_Delay(10000);

    SDL_Quit();
    return 0;
}
