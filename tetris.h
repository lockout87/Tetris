#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include <SDL/SDL.h>
#include <cmath>
#include <ctime>
#include <string>
#include <cassert>
#define NDEBUG
using namespace std;

SDL_Surface *loadImage(string fileName);
void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination);


#endif // TETRIS_H_INCLUDED
