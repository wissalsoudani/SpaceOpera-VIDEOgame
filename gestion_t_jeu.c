#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>



int main()
{
    TTF_Font *police = NULL;
    SDL_Color black = {0, 0, 0}, white = {255, 255, 255};
    int continuer = 1;
    int Currenttime  = 0, Previoustime  = 0, timer = 0;
    char time[20] = "";
    SDL_Rect position;
    SDL_Surface *texte = NULL;


    TTF_Init();
    /* Chargement de la police */
    police = TTF_OpenFont("police.ttf", 20); // paramètres à modifier selon le code final //
    /* Initialisation du temps et du texte */
    Currenttime  = SDL_GetTicks();
    sprintf(time, "Time : %d", timer);
    texte = TTF_RenderText_Shaded(police, time, black , white );
     

    while (continuer)
    {
  /* traitement du jeu */

    
        Previoustime = SDL_GetTicks();
        if (Currenttime  - Previoustime  >= 1000) /* Si 1 m au moins se sont écoulées */
        {
            timer += 1000; /* On rajoute 1 m au compteur timer */
            sprintf(time, "Time : %d", timer); /* On écrit dans la chaîne "time" le nouveau temps */
            SDL_FreeSurface(texte); /* On supprime la surface précédente */
            texte = TTF_RenderText_Shaded(police, time, black , white); /* On écrit la chaîne time dans la SDL_Surface */
            Previoustime = Currenttime ; /* On met à jour le Previoustime (temps précédent) */
        }

        position.x = //;
        position.y = //;
        SDL_BlitSurface(texte, NULL, screen, &position); /* Blit du texte */
        SDL_Flip(screen);
 }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
  SDL_Quit();

    return EXIT_SUCCESS;
}



