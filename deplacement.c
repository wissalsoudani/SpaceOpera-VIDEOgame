#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
void main  (){
  SDL_Surface *screen;
  SDL_Surface *image;
SDL_Surface *enemie;
  SDL_Rect positionecran;
  char pause;
  int done=1;
  SDL_Event event;
  Mix_Music *music;
  SDL_Surface *bg;
  SDL_Rect posbg;
SDL_Rect penemie;
  if(SDL_Init(SDL_INIT_VIDEO)!=0)
  {
      printf("Error: %s\n",SDL_GetError());

  }
  screen = SDL_SetVideoMode(450,450,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(!screen)
  {
      printf("Error 2: %s\n",SDL_GetError());

  }
  image = IMG_Load("detective.png");
  enemie=IMG_Load("enemie.png");
  bg = SDL_LoadBMP("background.bmp");
  if(!image)
  {
     printf("Error: %s\n",SDL_GetError());

  }
  if(!enemie)
  {
     printf("Error: %s\n",SDL_GetError());

  }
  positionecran.x = 225-32;    posbg.x = 0;
  positionecran.y = 225-32;    posbg.y = 0;
  positionecran.h = image->h;  posbg.h = image->h;
  positionecran.w = image->w;  posbg.w = image->w;
penemie.x=200;
penemie.y=200;
penemie.h=enemie->h;
penemie.w=enemie->w;
  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    printf("Error : %s",Mix_GetError());
  music = Mix_LoadMUS("music.mp3");
  Mix_PlayMusic(music,-1);
  while(done)
  {
    SDL_BlitSurface(bg,NULL,screen,&posbg);
    SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(image->format,255,255,255));
    SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(enemie,NULL,screen,&penemie);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
    {
     switch(event.type)
     {
        case SDL_KEYDOWN:
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {
           positionecran.x -= 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
            positionecran.x += 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
           positionecran.x+=10;
           positionecran.y -= 20;
            SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
          positionecran.y += 5;
            //affichage d image
            SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
        break;
        case SDL_MOUSEBUTTONUP:
          if(event.button.button == SDL_BUTTON_LEFT )
          {
            positionecran.x -= 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
           positionecran.x += 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
            positionecran.x+=10;
            positionecran.y -= 20;
            SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
            positionecran.y += 5;
            //affichage d image
           SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
        break;
        case SDL_QUIT:

        break;
      }
    }
if( (positionecran.x +positionecran. w< penemie. x) || (positionecran.x>  penemie. x + penemie. w)|| (positionecran.y + positionecran.h< penemie. y) || (positionecran.y>  penemie. y + penemie. h ))
 {
     printf("pas de colision \n");
    // return 0;
     
 }
 else 
 {
     printf("il ya colision \n");
     //return 1;
     
     
 }
  }
 
  Mix_FreeMusic(music);
  SDL_FreeSurface(image);

}

