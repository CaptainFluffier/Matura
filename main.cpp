#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include "input.h"
#include "Data.h"
#include "logic.h"
using namespace std;

/*
stock[0]=grozdje
stock[1]=lubenice
stock[2]=krompir
stock[3]=paradiznik
stock[4]=koruza
*/
int main( int argc, char* args[] )
 {  srand (time(NULL));
    bool start=1;
    bool screentime;
    int xb1,yb1,yb2,yb3,yb4,yb5;
    int posy;
    tabdayberi();
    tabkupljenoberi();
    tabstockberi();
    int posx;
      while(!GameOver)
{
        if(start==1){
        if( !ini() )
        {
          printf( "ni uspel inicializirati!\n" );
        }
        if( !loadMedia1() )
        printf( "Ni uspel naloziti!\n" );
          else
        {
            xb1=550;
            yb1=150;
            yb2=300;
            yb3=450;
            yb4=600;
            firstscreen(xb1,yb1,yb2,yb3,yb4);
        }}
        if(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                GameOver = true;
                break;
            case SDL_MOUSEBUTTONUP:
                posx = event.button.x;
                posy = event.button.y;
                                if(checkclick1(posx,posy,xb1,yb1))
                                { screentime=1;

                                    close();
                                    if( !ini() )
                                    {
                                        printf( "ni uspel inicializirati!\n" );
                                    }
                                    if( !loadMedia2() )
                                        printf( "Ni uspel naloziti!\n" );
                                    else
                                    {
                                        xb1=390;
                                        yb1=890;
                                        yb5=505;
                                        yb2=0;
                                        yb3=530;
                                        yb4=1030;
                                        buyscreen(xb1,yb1,yb2,yb3,yb4,yb5);
                                    }
                                while(screentime!=0)
                                {
                                    if(SDL_PollEvent(&event))
                                    {
                                                   switch(event.type)
                                                    {
                                                        case SDL_QUIT:
                                                        GameOver = true;
                                                        break;
                                                        case SDL_MOUSEBUTTONUP:
                                                        posx = event.button.x;
                                                        posy = event.button.y;
                                                            if(checkclickBack(posx,posy,0,505))
                                                            {
                                                                close();
                                                                    if( !ini() )
                                                                    {
                                                                        printf( "ni uspel inicializirati!\n" );
                                                                    }
                                                                    if( !loadMedia1() )
                                                                    printf( "Ni uspel naloziti!\n" );
                                                                    else
                                                                    {
                                                                        xb1=550;
                                                                        yb1=150;
                                                                        yb2=300;
                                                                        yb3=450;
                                                                        yb4=600;
                                                                        firstscreen(xb1,yb1,yb2,yb3,yb4);

                                                                    }
                                                                screentime=0;
                                                            }
                                                            if(checkclick1(posx,posy,0,390))
                                                            {
                                                                std::cout<<"Koliko zelite kupiti : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(0) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                                if(buy(bericena(0)*kolicina))
                                                                {
                                                                    dayfill(0,kolicina);
                                                                }
                                                            }
                                                            if(checkclick1(posx,posy,530,390))
                                                            {
                                                                std::cout<<"Koliko zelite kupiti : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(1) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                                if(buy(bericena(1)*kolicina))
                                                                {
                                                                    dayfill(1,kolicina);
                                                                }
                                                            }
                                                            if(checkclick1(posx,posy,1030,390))
                                                            {
                                                                std::cout<<"Koliko zelite kupiti : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(2) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                                if(buy(bericena(2)*kolicina))
                                                                {
                                                                    dayfill(2,kolicina);
                                                                }
                                                            }
                                                            if(checkclick1(posx,posy,530,890))
                                                            {
                                                                std::cout<<"Koliko zelite kupiti"<<endl;
                                                                std::cout<<"Cena je : "<< bericena(3) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                                if(buy(bericena(3)*kolicina))
                                                                {
                                                                    dayfill(3,kolicina);
                                                                }
                                                            }
                                                            if(checkclick1(posx,posy,1030,890))
                                                            {
                                                                std::cout<<"Koliko zelite kupiti: "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(4) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                                if(buy(bericena(4)*kolicina))
                                                                {
                                                                    dayfill(4,kolicina);
                                                                }
                                                            }
                                                        }
                                    }
                                    }}
                                else if(checkclick1(posx,posy,xb1,yb2))
                                { screentime=1;
                                    close();
                                    if( !ini() )
                                    {
                                        printf( "ni uspel inicializirati!\n" );
                                    }
                                    if( !loadMedia2() )
                                        printf( "Ni uspel naloziti!\n" );
                                    else
                                    {
                                        xb1=390;
                                        yb1=890;
                                        yb5=505;
                                        yb2=0;
                                        yb3=530;
                                        yb4=1030;
                                        sellscreen(xb1,yb1,yb2,yb3,yb4,yb5);
                                    }
                                      while(screentime!=0)
                                {
                                    if(SDL_PollEvent(&event))
                                    {
                                                   switch(event.type)
                                                    {
                                                        case SDL_QUIT:
                                                        GameOver = true;
                                                        break;
                                                        case SDL_MOUSEBUTTONUP:
                                                        posx = event.button.x;
                                                        posy = event.button.y;
                                                            if(checkclickBack(posx,posy,0,505))
                                                            {
                                                                close();
                                                                    if( !ini() )
                                                                    {
                                                                        printf( "ni uspel inicializirati!\n" );
                                                                    }
                                                                    if( !loadMedia1() )
                                                                    printf( "Ni uspel naloziti!\n" );
                                                                    else
                                                                    {
                                                                        xb1=550;
                                                                        yb1=150;
                                                                        yb2=300;
                                                                        yb3=450;
                                                                        yb4=600;
                                                                        firstscreen(xb1,yb1,yb2,yb3,yb4);
                                                                    }
                                                                    screentime=0;
                                                            }
                                                            if(checkclick1(posx,posy,0,390))
                                                            {
                                                                std::cout<<"Koliko zelite prodati : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(0)<<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                             thedeal(kolicina,0);
                                                            }
                                                            if(checkclick1(posx,posy,530,390))
                                                            {
                                                                std::cout<<"Koliko zelite prodati : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(1) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                             thedeal(kolicina,1);
                                                            }
                                                            if(checkclick1(posx,posy,1030,390))
                                                            {
                                                                std::cout<<"Koliko zelite prodati : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(2) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                               thedeal(kolicina,2);
                                                            }
                                                            if(checkclick1(posx,posy,530,890))
                                                            {
                                                                std::cout<<"Koliko zelite prodati : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(3) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                           thedeal(kolicina,3);
                                                            }
                                                            if(checkclick1(posx,posy,1030,890))
                                                            {
                                                                std::cout<<"Koliko zelite prodati : "<<endl;
                                                                std::cout<<"Cena je : "<< bericena(4) <<" enot"<<endl;
                                                                std::cin>>kolicina;
                                                              thedeal(kolicina,4);
                                                            }

                                }}}}
                else if(checkclick1(posx,posy,xb1,yb3))
                {   screentime=1;
                        close();
                        if( !ini() )
                        {
                            printf( "ni uspel inicializirati!\n" );
                        }
                        if( !loadMedia3() )
                        printf( "Ni uspel naloziti!\n" );
                        else
                        skladscreen();
                        while(screentime!=0)
                        {
                            if(SDL_PollEvent(&event))
                            {
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                    GameOver = true;
                                    break;
                                    case SDL_MOUSEBUTTONUP:
                                    posx = event.button.x;
                                    posy = event.button.y;
                                      if(checkclickBack(posx,posy,0,505))
                                        {
                                            close();
                                            if( !ini() )
                                            {
                                                printf( "ni uspel inicializirati!\n" );
                                            }
                                            if( !loadMedia1() )
                                                printf( "Ni uspel naloziti!\n" );
                                            else
                                            {
                                                xb1=550;
                                                yb1=150;
                                                yb2=300;
                                                yb3=450;
                                                yb4=600;
                                                firstscreen(xb1,yb1,yb2,yb3,yb4);
                                            }
                                            screentime=0;
                                        }
                                        else if(checkclick1(posx,posy,550,150))
                                        {
                                            berisklad();
                                        }
                                        else if(checkclick1(posx,posy,550,300))
                                        {
                                            std::cout<<"Koliko skladisca zelite dokupiti cena je 2500 enot na 1000 litrov enota mora biti zaokrozena na 1000 : "<<endl;
                                            std::cin>>here;
                                            dokupi(here);
                                        }
                                }
                            }
                        }
                }
                else if(checkclick1(posx,posy,xb1,yb4))
                    izpisCena();
                else if(checkclick1(posx,posy,1300,100))
                {
                    spreminajaj_delnice();
                        skladiscenjedan();
                        novdan();
                        if(razmere())
                        {
                            if(IzpisRaz()==1)
                            {
                                for(int j=0;j<100;j++)
                                {
                                    if(kupljeno[j]!=0)
                                    {
                                        kupljeno[j]=kupljeno[j]*0.6;
                                    }
                                }
                            }
                            else if(IzpisRaz()==2)
                            {
                                for(int j=0;j<100;j++)
                                {
                                    if(kupljeno[j]!=0)
                                    {
                                        kupljeno[j]=kupljeno[j]*0.8;
                                    }
                                }
                            }
                            else if(IzpisRaz()==3)
                            {
                                for(int j=0;j<100;j++)
                                {
                                    if(kupljeno[j]!=0)
                                    {
                                        kupljeno[j]=kupljeno[j]*0.4;
                                    }
                                }
                            }
                            else if(IzpisRaz()==4)
                            {
                                for(int j=0;j<100;j++)
                                {
                                    if(kupljeno[j]!=0)
                                    {
                                        kupljeno[j]=kupljeno[j]*0.8;
                                    }
                                }
                            }
                        }
                        RazChange();
                        int i;
                        float tmp;
                        int number;
                        for(i=0;i<100;i++)
                        {
                            if(dnevi[i]==0)
                            {
                                float temp;
                                temp = skladprostor();
                                number=stock[i];
                                if(temp < kupljeno[i])
                                {
                                    for(int i=0;i<10;i++)
                                        std::cout<<"*";
                                    std::cout<<endl;
                                    std::cout<<"Preveč napolnjeno skladišče nekaj pridelka je šlo v nič! "<<endl;
                                    for(int i=0;i<10;i++)
                                        std::cout<<"*";
                                        std::cout<<endl;
                                        kupljeno[i]=temp;
                                }
                                tmp=kupljeno[i];
                                stockplus(tmp,number);
                                skladplus(tmp);
                                dnevi[i]=-1;
                                 skladiscenjeadd(tmp,number);
                            }
                        }
                }
                else if(checkclick1(posx,posy,0,100))
                {
                    nova();
                    nastavi();
                    napolni();
                   skladiscenjeset();
                    int i;
                    for(i=0;i<100;i++)
                        kupljeno[i] = 0;
                     for(i=0;i<100;i++)
                        stock[i] = 0;
                }
                    break;

            }
        }
        start=0;

}
    tabdaypisi();
    tabkupljenopisi();
    tabstockpisi();
          return 0;
 }
