#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include <SDL.h>
#include <fstream>
#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;
float literkoruza = 15;
float literkrompir = 30;
float literlubenica = 100;
float litergrozdje = 70;
float literparadiznik = 55;
bool dogajanje=true;
bool buy(float j)
{
    int i;
    float money;
    beri1.open("money.txt");
    beri1 >> money;
    if(money < j)
        {    for(i=0;i<10;i++)
                std::cout<<"*";
            std::cout<<endl;
            std::cout<<"Nimas dovolj denarja za ta nakup"<<endl;
            for(i=0;i<10;i++)
                std::cout<<"*";
            std::cout<<endl;
            beri1.close();
            return 0;
        }
    else
    {
        pisi1.open("money.txt",ios::trunc);
        money -= j;
        pisi1 << money;
        pisi1.close();
        beri1.close();
        for(i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        std::cout<<"Opravljen nakup imas se: "<<money<<" enot denarja."<<endl;
        for(i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        return 1;
    }

}



void nastavi()
{
    int i;
    pisi1.open("stock.txt");
    for(i=0;i<5;i++)
        pisi1 << 0 << endl;
    pisi1.close();
    pisi1.open("money.txt");
    pisi1 << 5000 << endl;
    pisi1.close();
    pisi1.open("letnicas.txt");
    pisi1 << "poletje" << endl;
    pisi1 << 10 << endl;
    pisi1.close();
    pisi1.open("cena.txt");
    for(i=0;i<5;i++)
    {
        switch(i)
        {
            case 0: pisi1 << litergrozdje*3 <<endl; break;
            case 1: pisi1 << literlubenica*3 << endl; break;
            case 2: pisi1 << literkrompir*3 <<endl; break;
            case 3: pisi1 << literparadiznik*3 <<endl; break;
            case 4: pisi1 << literkoruza*3 << endl; break;
        }
    }
    pisi1.close();
    pisi1.open("sklad.txt");
    pisi1 << 1000 << endl;
    pisi1 << 99000 << endl;
    pisi1.open("konk.txt");
    pisi1 << "konkurenca1" << " " << 25.22 << endl;
    pisi1 << "konkurenca2" << " " << 13.1 << endl;
    pisi1 << "konkurenca3" << " " << 2.5 << endl;
    pisi1 << "konkurenca4" << " " << 3.39 << endl;
    pisi1.close();
    pisi1.open("beri.txt");
    for(int i=0;i<5;i++)
        pisi1 << 0 << endl;
    pisi1.close();
    pisi1.open("day.txt");
      for(int i=0;i<5;i++)
        pisi1 << 0 << endl;
        pisi1.close();
}
void spreminajaj_delnice()
{
    float procenti = 0;
    int shrani=0;
    int stevilo3 = rand()% 4 + 1;
    int stevilo[5];
    int stej[5];
    for(int i=0;i<5;i++)
        stej[i]=0;
    int stej2[5];
    int stej3[5];
    float stevilo2;
    float skupaj=0;
    srand(time(0));
    int sestevekcen = 0;
    beri1.open("cena.txt");
    float i[5];
    float r[5];
    int w=0;
    float nove[5];
    int j=0;
    while(beri1>>i[j])
        j++;
    beri1.close();
    beri1.open("day.txt");
 int o=0;
 while(beri1>>stej3[o])
    o++;
 beri1.close();
 beri1.open("beri.txt");
  o=0;
 while(beri1>>stej2[o])
    o++;
while(skupaj < 4.9  || skupaj<5.1){
            skupaj = 0;
        for(int w = 0;w<5;w++){
        float random = rand()+1;
        r[w]=0;
        while(r[w]==0)
        r[w]=(1/(random+1))*sin(rand()%90)+1;
        skupaj+=r[w];
        }
    }
    for(int t = 0;t<5;t++){
        nove[t] =  i[t]*r[t];
    }
    pisi1.open("cena.txt");
    for(int i=0;i<stevilo3;i++)
        stevilo[i]= rand()%5 + 1;
    for(int t = 0;t<5;t++){
            if(stevilo[t]==t)
            {
                stevilo2 = rand()%17 + 4;
                nove[t]=nove[t]*((100-stevilo2)/100);
            }
        float nov=rand()%51+1;
        nov=nov/100;
    if(stej3[t]>0)
    {
        int tmp=stej3[t];
        switch(tmp)
        {
            case 1: procenti=0.5; break;
            case 2: procenti=0.43; break;
            case 3: procenti = 0.36; break;
            case 4: procenti = 0.29; break;
            case 5: procenti = 0.22; break;
            case 6: procenti = 0.15; break;
            case 7: procenti = 0.08; break;
            default: procenti = 0;  break;
        }
        if (procenti==0)
        {
            if(stej2[t]==1)
            nove[t]=nove[t]*0.9;
            else if(stej2[t]==0)
            nove[t]=nove[t]*1.1;
        }
        if(nov < procenti)
        {
            if(stej2[t]==0)
                while(nove[t]>i[t])
                nove[t]=nove[t]*0.92;
            else
                while(nove[t]<i[t])
                nove[t]=nove[t]*1.08;
        }
    }

        if(nove[t]>i[t])
        {
            stej[t]=1;
            if(stej[t]==stej2[t])
               {
                   stej3[t]=stej3[t]+1;
               }
                else stej3[t]=0;
            if(stej3[t]>7)
            nove[t]=nove[t]*0.82;
        }
        else
        {

            stej[t]=0;
            if(stej[t]==stej2[t])
            {
                stej3[t]=stej3[t]+1;
            }
            else stej3[t]=0;
            if(stej3[t]>7)
            nove[t]=nove[t]*1.18;
        }
        pisi1<<nove[t]<<endl;
    }
    pisi1.close();
    pisi1.open("beri.txt");
    pisi2.open("day.txt");
    for(int i=0;i<5;i++)
    {
        pisi1 << stej[i] << endl;
        pisi2 << stej3[i] << endl;
    }
    pisi1.close();
    pisi2.close();
}
bool razmere()
{
    srand (time(NULL));
    int j = (rand()%100)+1;
    if(j>0 && j<6)
        return 1;
    return 0;
}

#endif // LOGIC_H_INCLUDED
