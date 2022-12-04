#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include "background.h"


background initbackground()
{	background bg;
	bg.bgimg = IMG_Load("mars.png");
	
		return bg;
}

void affbackground (background bg, SDL_Surface *screen)
{
	SDL_BlitSurface (bg.bgimg,NULL,screen,NULL);
	SDL_Flip(screen);
}
