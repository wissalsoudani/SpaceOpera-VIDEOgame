#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_audio.h>

typedef struct{
	SDL_Surface *image;
	SDL_Rect pos;
    
    int vi;
    int coins;
}perso;
void main()
{
int cont=1;
SDL_Surface *menu=NULL;
SDL_Surface *screen=NULL;
perso p;
SDL_Rect positionmenu;
//positionimage menu 
positionmenu.x=0;
positionmenu.y=0;
SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1280,720, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL)
printf ("Erreur");
menu=IMG_Load("MENU.jpg");



while (cont){


SDL_BlitSurface(menu,NULL,screen,&positionmenu);
	p.image=IMG_Load("1.png");

	p.pos.x=20;
	p.pos.y=30;
	p.pos.w= p.image->w;
	p.pos.h= p.image->h;


	p.vi = 4;
	p.coins=0;
SDL_BlitSurface(p.image, NULL, screen, &p.pos);




SDL_Flip (screen);
}
SDL_Quit;	
}


