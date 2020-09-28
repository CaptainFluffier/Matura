#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <SDL.h>
bool GameOver = false;
SDL_Event event;
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1000;
const int buttonwidth = 250;
const int buttonheigth = 100;
const int buttonheigthback = 490;
const int buttonwidthback = 490;
int SCREEN_BPP = 32;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* button1 = NULL;
SDL_Surface* button2 = NULL;
SDL_Surface* button3 = NULL;
SDL_Surface* button4 = NULL;
SDL_Surface* button5 = NULL;
SDL_Surface* button6 = NULL;
void apply(int x , int y , SDL_Surface* source , SDL_Surface* destination)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_BlitSurface(source,NULL,destination,&rect);
}
bool ini()
{
    GameOver = false;
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL ni uspel inicializirati! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "SDL game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
         if( gWindow == NULL )
         {
              printf( "Ni uspel odpreti okna SDL_Error: %s\n", SDL_GetError() );
               success = false;
         }
         else
         {
              gScreenSurface = SDL_GetWindowSurface( gWindow );
         }
    }
        return success;
}
bool loadMedia1()
{
    bool success = true;
     gHelloWorld = SDL_LoadBMP( "output.bmp" );
      if( gHelloWorld == NULL )
      {
           printf( "ni uspel naloziti slike %s! SDL Error: %s\n", "output.bmp", SDL_GetError() );
            success = false;
      }
    return success;
}
bool loadMedia2()
{
    bool success = true;
     gHelloWorld = SDL_LoadBMP( "Kupi.bmp" );
      if( gHelloWorld == NULL )
      {
           printf( "ni uspel naloziti slike %s! SDL Error: %s\n", "Kupi.bmp", SDL_GetError() );
            success = false;
      }
    return success;
}
bool loadMedia3()
{
    bool success = true;
     gHelloWorld = SDL_LoadBMP( "sklad.bmp" );
      if( gHelloWorld == NULL )
      {
           printf( "ni uspel naloziti slike %s! SDL Error: %s\n", "sklad.bmp", SDL_GetError() );
            success = false;
      }
    return success;
}
void close()
{
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_Quit();
}
void firstscreen(int x1, int y1 , int y2 , int y3 , int y4)
{
    button1 = SDL_LoadBMP("button1.bmp");
    button2 = SDL_LoadBMP("button2.bmp");
    button3 = SDL_LoadBMP("button3.bmp");
    button4 = SDL_LoadBMP("tole.bmp");
    button5 = SDL_LoadBMP("change.bmp");
    button6 = SDL_LoadBMP("change1.bmp");
                SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
                SDL_UpdateWindowSurface( gWindow );
                apply(550,150,button1,gScreenSurface);
                apply(550,300,button2,gScreenSurface);
                apply(550,450,button3,gScreenSurface);
                apply(550,600,button4,gScreenSurface);
                apply(1300,100,button5,gScreenSurface);
                apply(0,100,button6,gScreenSurface);
                SDL_UpdateWindowSurface( gWindow );
}
void buyscreen(int y1, int y2, int x1 , int x2 , int x3, int yb5)
{
    button1 = SDL_LoadBMP("button1.bmp");
    button2 = SDL_LoadBMP("Back.bmp");
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
                SDL_UpdateWindowSurface( gWindow );
                apply(x1,y1,button1,gScreenSurface);
                apply(x2,y1,button1,gScreenSurface);
                apply(x3,y1,button1,gScreenSurface);
                apply(x1,yb5,button2,gScreenSurface);
                apply(x2,y2,button1,gScreenSurface);
                apply(x3,y2,button1,gScreenSurface);
                SDL_UpdateWindowSurface( gWindow );
}
void sellscreen(int y1, int y2, int x1 , int x2 , int x3, int yb5)
{
    button1 = SDL_LoadBMP("button2.bmp");
    button2 = SDL_LoadBMP("Back.bmp");
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
                SDL_UpdateWindowSurface( gWindow );
                apply(x1,y1,button1,gScreenSurface);
                apply(x2,y1,button1,gScreenSurface);
                apply(x3,y1,button1,gScreenSurface);
                apply(x1,yb5,button2,gScreenSurface);
                apply(x2,y2,button1,gScreenSurface);
                apply(x3,y2,button1,gScreenSurface);
                SDL_UpdateWindowSurface( gWindow );
}
bool checkclick1(int posx , int posy , int xb1 , int yb1)
{
    if(posx>xb1 && posx<xb1+buttonwidth && posy>yb1 && posy<yb1+buttonheigth)
    return 1;
    return 0;
}
bool checkclickBack(int posx , int posy , int xb1 , int yb1)
{
    if(posx>xb1 && posx<xb1+buttonwidthback && posy>yb1 && posy<yb1+buttonheigthback)
    return 1;
    return 0;
}
void skladscreen()
{
    button1 = SDL_LoadBMP("izpis.bmp");
    button2 = SDL_LoadBMP("Back.bmp");
    button3 = SDL_LoadBMP("button1.bmp");
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
                SDL_UpdateWindowSurface( gWindow );
                apply(550,150,button1,gScreenSurface);
                apply(0,505,button2,gScreenSurface);
                apply(550,300,button3,gScreenSurface);
                SDL_UpdateWindowSurface( gWindow );
}
#endif // INPUT_H_INCLUDED
