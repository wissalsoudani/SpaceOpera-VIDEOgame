#include "scrolling.h"
#include <stdbool.h> 
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void scrolling (SDL_Rect camera,background *bg,SDL_Surface *screen)
{
	SDL_Surface *image=NULL;
	SDL_Event event;	
	SDL_Rect position;
	position.x=0;
	position.y=390;
	const int slow=1;
	const int speed1=50;
	int go=1;
	camera.x=0;
	camera.y=0;
	image=IMG_Load("astro.png");
	camera.w=1200;
	camera.h=800;
	bool b[2]= {0,0};
	SDL_EnableKeyRepeat(10,10);	
	while (go)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					go=0;
					break;
				case SDL_KEYDOWN :
					switch(event.key.keysym.sym)
					{	
						case SDLK_RIGHT :
							position.x+=5;
							if ( position.x>=550)
							{
								position.x=550;
								camera.x+=10;
							}
							if (camera.x>=(8000-800))
							{	
								camera.x=8000-800;
							}	
							break;
						case SDLK_LEFT:
							position.x-=5;	
							if (position.x<=100)
							{
								position.x=100;
								camera.x-=10;
							}
							if (camera.x<=0)
							{
								camera.x=0;
								position.x=0;
							}
							break;
					}
			}
		 }	
	SDL_BlitSurface (bg->bgimg,&camera,screen,NULL);
	SDL_BlitSurface (image,NULL,screen,&position);
	SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255,255,255));
	SDL_Flip(screen);
	}
}

				

