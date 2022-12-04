


void solution(SDL_Surface *screen,int e)
{
    char ch[50];
    SDL_Surface *image1 = NULL;
    SDL_Rect pos_bg1;
    pos_bg1.x =  0 ;
    pos_bg1.y =  0 ;
    SDL_Surface *image = NULL;
    SDL_Rect pos_bg;
    pos_bg.x =  0 ;
    pos_bg.y =  0 ;
    image1= IMG_Load("no.png");
    SDL_BlitSurface(image1,NULL,screen,&pos_bg1);
    SDL_Flip(screen);
    SDL_Delay(3000);
    sprintf(ch,"solu/%d.png",e);
    image= IMG_Load(ch);
    SDL_BlitSurface(image,NULL,screen,&pos_bg);
    SDL_Flip(screen);
    SDL_Delay(5000);
}



void gj(SDL_Surface *screen)
{
    char ch[50];
    SDL_Surface *image = NULL;
    SDL_Rect pos_bg;
    pos_bg.x =  0 ;
    pos_bg.y =  0 ;
    sprintf(ch,"good_job.png");
    image= IMG_Load(ch);
    SDL_BlitSurface(image,NULL,screen,&pos_bg);
    SDL_Flip(screen);
    SDL_Delay(5000);
}




void gj(SDL_Surface *screen,int e)
{   int continuer =1;
    int i=0;
    SDL_Event event;
    char ch[50], ch1[50], ch2[50], ch3[50];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect pos_im;
    pos_im.x =  0 ;
    pos_im.y =  0 ;
    sprintf(ch,"answer/%d.png",e);
    image= IMG_Load(ch);
    sprintf(ch1,"answer/%d/1.png",e);
    sprintf(ch2,"answer/%d/2.png",e);  // chaque dossier answer contient les bonnes reponses (même numéro que l'enigme ) et un dossier        
    sprintf(ch3,"answer/%d/3.png",e);  // contenant les 3 possibilités //
    image1= IMG_Load(ch1);
    image2= IMG_Load(ch2);
    image3= IMG_Load(ch3);
    SDL_BlitSurface(image,NULL,screen,&pos_im);
    SDL_Flip(screen);
    



    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==1 && e%3==1)
                    {
                        gj(screen);
                        continuer=0;
                    }
                    else if (i==2 && e%3==2)
                    {
                        gj(screen);
                        continuer=0;
                    }
                    else if (i==3 && e%3==0)
                    {
                        gj(screen);
                        continuer=0;
                    }
                    else
                    {
                        solution(screen,e);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, screen, &pos_im);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL,screen, &pos_im);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, screen, &pos_im);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=3;
                }
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, screen, &pos_im);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, screen, &pos_im);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, screen, &pos_im);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                }
                break;
            }
        }
        //SDL_BlitSurface(image,NULL,screen,&pos_im);
        SDL_Flip(screen);
    }


}
