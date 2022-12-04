#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct 
{
	SDL_Surface *bgimg ;
	SDL_Rect  bgpos;
}background;

background  initbackground ();
void affbackground (background bg, SDL_Surface *screen);

#endif
