#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include <SDL/SDL_ttf.h>
#include <time.h>
int main()
{
  SDL_Color black={0,0,0};
  SDL_Surface *texte = NULL, *bg=NULL ; //declaration des variables globale 
  SDL_Rect pos_texte,pos_e;
  pos_texte.x=150;
  pos_texte.y=220; // à regler dans le code final //
  pos_e.x=0 ; 
  pos_e.y=0 ; 
  SDL_Surface *screen =NULL;
  TTF_Font *police;// 


  int e=1;
   SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
 
   srand(time(NULL));   
   e=rand()%15;  // 15 enigmes statiques //
 
 TTF_Init();
   if(TTF_Init()==-1)
     {fprintf(stderr,"ERREUR INIT: %s \n",TTF_GetError());
      exit(EXIT_FAILURE);}
      police=TTF_OpenFont("police.ttf",200); // à regler selon le code final //


  screen=SDL_SetVideoMode(1000, 800, 32,SDL_HWSURFACE); // Ouverture de la fenêtre
  bg = IMG_Load("bg.png");  // background de l'enigme //
  SDL_BlitSurface(bg,NULL, screen, &pos_e);
  SDL_Flip(screen);

  question(screen,e);
  SDL_BlitSurface(bg,NULL,screen, &pos_e);
  SDL_Flip(screen);
  
  answer(screen,e);
  SDL_FreeSurface(bg);

  TTF_CloseFont(police);
  TTF_Quit();
  SDL_Quit(); 

    return EXIT_SUCCESS;
}
