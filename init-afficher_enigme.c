




void quiz(SDL_Surface *screen,int e)
{
    char ch[50];
    SDL_Surface *image = NULL;
    SDL_Rect pos_bg;
    pos_bg.x =  0 ;
    pos_bg.y =  0 ;
    sprintf(ch,"quest/%d.png",d); // dossier contenant les questions //
    image= IMG_Load(ch);          // on charge l'image contenant la question //
    SDL_BlitSurface(image,NULL,screen,&pos_bg); // on blit l'image //
    SDL_Flip(screen);
    SDL_Delay(5000); // durée 5000ms //
}
