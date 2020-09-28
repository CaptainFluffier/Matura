#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <SDL.h>
#include <fstream>
#include <iostream>

using namespace std;
ifstream beri1;
ifstream beri3;
ofstream pisi3;
ofstream pisi1;
ifstream beri2;
ofstream pisi2;
float kolicina;
int here;
int dnevi[100];
float kupljeno[100];
int stock[100];
/*
0=grozdje
1=lubenice
2=krompir
3=paradiznik
4=koruza
*/
void tabdayberi()
{
    int i=0;
    beri1.open("dnevi.txt");
    while(beri1 >> dnevi[i])
    i++;
    beri1.close();
}
bool stockminus(float j , int number)
{
    float stock;
    float tmp;
    int i=0;
    beri1.open("stock.txt");
    while(beri1 >> stock && i!=number)
        i++;
    if(stock < j)
    {
        for(i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        std::cout<<"Nimas dovolj zalog za to prodajo"<<std::endl;
        for(i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        beri1.close();
        return 0;
    }
    else
    {
        pisi1.open("stock1.txt");
        tmp = stock - j;
        i=0;
        beri1.close();
        beri1.open("stock.txt");
        while(beri1 >> stock)
        {
            if(i==number)
            pisi1 << tmp << endl;
            else
            pisi1 << stock << endl;
            i++;
        }
        beri1.close();
        pisi1.close();
        remove("stock.txt");
        rename("stock1.txt","stock.txt");
        return 1;
    }
}
void tabkupljenoberi()
{
    int i=0;
    beri1.open("kupljeno.txt");
    while(beri1 >> kupljeno[i])
    i++;
    beri1.close();
}
void tabstockberi()
{
    int i=0;
    beri1.open("zaloga.txt");
    while(beri1 >> stock[i])
    i++;
    beri1.close();
}
void tabdaypisi()
{
    pisi1.open("dnevi.txt",ios::trunc);
    int i;
    for(i=0;i<100;i++)
    pisi1 << dnevi[i] <<endl;
    pisi1.close();
}
void tabkupljenopisi()
{
    pisi1.open("kupljeno.txt",ios::trunc);
    int i;
    for(i=0;i<100;i++)
    pisi1 << kupljeno[i] <<endl;
    pisi1.close();
}
void tabstockpisi()
{
    pisi1.open("zaloga.txt",ios::trunc);
    int i;
    for(i=0;i<100;i++)
    pisi1 << stock[i] <<endl;
    pisi1.close();
}
void nova()
{
    for(int i=0;i<10;i++)
    std::cout<<"*";
    std::cout<<endl;
    std::cout<<"Igra ponovno nastavljena"<<endl;
    beri1.open("stock.txt",ios::trunc);
    beri1.close();
    beri1.open("money.txt",ios::trunc);
    beri1.close();
    beri1.open("sklad.txt",ios::trunc);
    beri1.close();
    beri1.open("konk.txt",ios::trunc);
    beri1.close();
    beri1.open("cena.txt",ios::trunc);
    beri1.close();
    beri1.open("zaloga.txt",ios::trunc);
    beri1.close();
    beri1.open("kupljeno.txt",ios::trunc);
    beri1.close();
    beri1.open("dnevi.txt",ios::trunc);
    beri1.close();
    for(int i=0;i<10;i++)
    std::cout<<"*";
    std::cout<<endl;
}
void berisklad()
{
    float prostor[2];
    int i=0;
    beri1.open("sklad.txt");
    while(beri1>>prostor[i])
        i++;
    beri1.close();
    for(int i=0;i<10;i++)
        std::cout<<"*";
    std::cout<<endl;
    std::cout<<"Na voljo je se :"<<prostor[0]<<" litrov prostora."<<endl;
    for(int i=0;i<10;i++)
        std::cout<<"*";
    std::cout<<endl;
        for(int i=0;i<10;i++)
        std::cout<<"*";
    std::cout<<endl;
    std::cout<<"Dokupis lahko se :"<<prostor[1]<<" litrov prostora."<<endl;
    for(int i=0;i<10;i++)
        std::cout<<"*";
    std::cout<<endl;
}
bool dokupi(int j)
{
    float money;
    float prostor[2];
    int i=0;
    if(j%1000!=0)
    {
        for(int i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        std::cout<<"Stevilo dokupa mora biti zaokrozeno na 1000!"<<endl;
        for(int i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        return 0;
    }
    beri1.open("sklad.txt");
    pisi1.open("sklad1.txt");
    while(beri1>>prostor[i])
        i++;

    if(prostor[1]<j)
    {
        for(int i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        std::cout<<"Nemores dokupiti take vsote, ker je ni na voljo"<<endl;
        for(int i=0;i<10;i++)
            std::cout<<"*";
        std::cout<<endl;
        beri1.close();
        pisi1.close();
        return 0;
    }
    else
    {
        beri2.open("money.txt");
        beri2 >> money;
        if(money<j*2.5)
        {
            for(int i=0;i<10;i++)
                std::cout<<"*";
            std::cout<<endl;
            std::cout<<"Nemores dokupiti take vsote, ker nimas dovolj denarja"<<endl;
            for(int i=0;i<10;i++)
                std::cout<<"*";
            std::cout<<endl;
            beri1.close();
            pisi1.close();
            beri2.close();
            return 0;
        }
        else
        {
            beri2.close();
            pisi2.open("money.txt",ios::trunc);
            money -= j*2.5;
            pisi2 << money;
            pisi2.close();
            for(int i=0;i<10;i++)
                std::cout<<"*";
            std::cout<<endl;
            std::cout<<"Nakup opravljen imas se: "<<money<<" enot denarja."<<endl;
            pisi1 << prostor[0] + j << endl;
            pisi1 << prostor [1] - j << endl;
            std::cout<<"Na voljo je: "<<prostor[0]+j<<" litrov prostora."<<endl;
            for(int i=0;i<10;i++)
                std::cout<<"*";
            std::cout<<endl;
            pisi1.close();
            beri1.close();
            remove("sklad.txt");
            rename("sklad1.txt","sklad.txt");
            return 1;
        }
    }
}
float skladprostor()
{
    float j;
    beri1.open("sklad.txt");
    beri1 >> j;
    return j;
}
bool skladplus(float number)
{
    float var[2];
    beri1.open("sklad.txt");
    int i;
    while(beri1 >> var[i])
        i++;
    beri1.close();
    pisi1.open("sklad.txt",ios::trunc);
    pisi1 << var[0] - number <<endl;
    pisi1 << var[1] <<endl;
    pisi1.close();
}

bool skladminus(float number)
{
    float var[2];
    beri1.open("sklad.txt");
    int i;
    while(beri1 >> var[i])
        i++;
    beri1.close();
    pisi1.open("sklad.txt",ios::trunc);
    pisi1 << var[0] + number <<endl;
    pisi1 << var[1] <<endl;
    pisi1.close();
}

float beristock(int j)
{
    float value[5];
    int i=0;
    beri1.open("stock.txt");
    while(beri1 >> value[i])
    {
        i++;
    }
    beri1.close();
    return value[j];
}
float moneycheck()
{
    float money;
    beri1.open("money.txt");
    beri1 >> money;
    beri1.close();
    return money;
}
float bericena(int j)
{
    float value[5];
    int i=0;
    beri1.open("cena.txt");
    while(beri1 >> value[i])
    {
        i++;
    }
    beri1.close();
    return value[j];
}
void napolni()
{
    pisi1.open("dnevi.txt",ios::trunc);
    int i;
    for(i=0;i<100;i++)
    pisi1 << -1 << endl;
    pisi1.close();
    pisi1.open("zaloga.txt",ios::trunc);
    for(i=0;i<100;i++)
    pisi1 << 0 << endl;
    pisi1.close();
    pisi1.open("kupljeno.txt",ios::trunc);
    for(i=0;i<100;i++)
    pisi1 << 0 << endl;
    pisi1.close();
}
void dayfill(int number, float stevilo)
{
    int i;
    for(i=0;i<100;i++)
    {
        if(dnevi[i]==-1)
        {
            switch(number)
            {
                case 0: dnevi[i] = 7; break;
                case 1: dnevi[i] = 8; break;
                case 2: dnevi[i] = 5; break;
                case 3: dnevi[i] = 2; break;
                case 4: dnevi[i] = 4; break;
            }
            stock[i]=number;
            kupljeno[i]=stevilo;
            i=101;
        }
    }

}
void sell(float j)
{
    cout<<"Vrednost "<<j<<endl;
    float money;
    int i;
    beri1.open("money.txt");
    beri1 >> money;
    cout<<" Money" <<money <<endl;
    money += j;
    pisi1.open("money.txt",ios::trunc);
    pisi1 << money;
    for(i=0;i<10;i++)
        std::cout<<"*";
    std::cout<<endl;
    std::cout<<"Imas : "<<money<<" enot denarja"<<endl;
    for(i=0;i<10;i++)
        std::cout<<"*";
    std::cout<<endl;
    pisi1.close();
    beri1.close();
}
bool stockplus(float j, int number)
{
    float stock;
    float tmp;
    int i=0;
    beri1.open("stock.txt");
    pisi1.open("stock1.txt");
    while(beri1 >> stock && i!=number)
        i++;
        tmp = stock + j;
        i=0;
    beri1.close();
    beri1.open("stock.txt");
        while(beri1 >> stock)
        {
            if(i==number)
            pisi1 << tmp << endl;
            else
            pisi1 << stock << endl;
            i++;
        }
        beri1.close();
        pisi1.close();
        remove("stock.txt");
        rename("stock1.txt","stock.txt");
        return 1;
}
void skladiscenjeset()
{
    pisi1.open("skladiscenje.txt");
    int i;
    for(i=0;i<100;i++)
    pisi1 << -1 << endl;
    pisi1.close();
    pisi1.open("skladiscenjed.txt");
    for(i=0;i<100;i++)
    pisi1 << -1 << endl;
    pisi1.close();
    pisi1.open("skladiscenjedan.txt");
    for(i=0;i<100;i++)
    pisi1 << -1 << endl;
    pisi1.close();
}
void skladiscenjeadd(float j, int number)
{
    float i;
    int g=0;
    int place;
    beri1.open("skladiscenje.txt");
    pisi1.open("skladiscenje1.txt");
    beri2.open("skladiscenjed.txt");
    pisi2.open("skladiscenjed1.txt");
    while(beri1 >> i)
    {
        if(i==-1)
        {
            place=g;
            break;
        }
        g++;
    }
    beri1.close();
    beri1.open("skladiscenje.txt");
    g=0;
    while(beri1 >> i)
    {
        if(g==place)
            pisi1 << j << endl;
        else
            pisi1 << i << endl;
        g++;
    }
    g=0;
        while(beri2 >> i)
    {
        if(g==place)
            pisi2 << number << endl;
        else
            pisi2 << i << endl;
        g++;
    }
    pisi1.close();
    pisi2.close();
    beri1.close();
    beri2.close();
    pisi1.open("skladiscenjedan1.txt");
    beri1.open("skladiscenjedan.txt");
    g=0;
        while(beri1 >> i)
    {
        if(g==place)
            pisi1 << 0 << endl;
        else
            pisi1 << i << endl;
        g++;
    }
    pisi1.close();
    beri1.close();
        remove("skladiscenje.txt");
        rename("skladiscenje1.txt","skladiscenje.txt");
        remove("skladiscenjed.txt");
        rename("skladiscenjed1.txt" , "skladiscenjed.txt");
        remove("skladiscenjedan.txt");
        rename("skladiscenjedan1.txt","skladiscenjedan.txt");
}
void skladiscenjedan()
{
    int i;
    beri1.open("skladiscenjedan.txt");
    pisi1.open("skladiscenjedan1.txt");
            while(beri1 >> i)
    {
        if(i!=-1)
            pisi1 << ++i << endl;
        else
            pisi1 << i << endl;
    }
    pisi1.close();
    beri1.close();
    remove("skladiscenjedan.txt");
    rename("skladiscenjedan1.txt","skladiscenjedan.txt");
}
void thedeal(float j, int number)
{
    beri1.open("skladiscenje.txt");
    beri2.open("skladiscenjed.txt");
    beri3.open("skladiscenjedan.txt");
    int kaj[100], zakaj[100];
    int mesto[100], kje[100];
    float vrednosti[100];
    int dnevi[100];
    int dan;
    float spre;
    int t;
    int i=0, y=0;
    while(beri2 >> kaj[i])
    {
        if(kaj[i]==number)
        {
            mesto[y]=i;
            y++;
        }
        i++;
    }
    beri2.close();
    i=0;
    y=0;
    while(beri1 >> kje[i])
    {
        if(mesto[y]==i)
        {
            vrednosti[y]=kje[i];
            y++;
        }
        i++;
    }
    beri1.close();
    y=0;
    i=0;
    while(beri3 >> zakaj[i])
    {
        if(mesto[y]==i)
        {
            dnevi[y]=zakaj[i];
            y++;
        }
        i++;
    }
    beri3.close();
    i=0;
    y=0;
    while(j!=0)
    {
        dan=dnevi[y];
        if(dnevi[y]>10)
        {
            std::cout<<"I AM HERE"<<endl;
            if(j >= vrednosti[y])
            {
                switch(dan)
                {
                case 11:std::cout<<bericena(number)*vrednosti[y]*0.95<<"JUHUHU"<<endl; sell(bericena(number)*vrednosti[y]*0.95); skladminus(vrednosti[y]); break;
                case 12:std::cout<<bericena(number)*vrednosti[y]*0.90<<endl; sell(bericena(number)*vrednosti[y]*0.90); skladminus(vrednosti[y]); break;
                case 13:std::cout<<bericena(number)*vrednosti[y]*0.85<<endl; sell(bericena(number)*vrednosti[y]*0.85); skladminus(vrednosti[y]); break;
                case 14:std::cout<<bericena(number)*vrednosti[y]*0.80<<endl; sell(bericena(number)*vrednosti[y]*0.80); skladminus(vrednosti[y]); break;
                case 15:std::cout<<bericena(number)*vrednosti[y]*0.75<<endl; sell(bericena(number)*vrednosti[y]*0.75); skladminus(vrednosti[y]); break;
                case 16:std::cout<<bericena(number)*vrednosti[y]*0.70<<endl; sell(bericena(number)*vrednosti[y]*0.70); skladminus(vrednosti[y]); break;
                case 17:std::cout<<bericena(number)*vrednosti[y]*0.65<<endl; sell(bericena(number)*vrednosti[y]*0.65); skladminus(vrednosti[y]); break;
                case 18:std::cout<<bericena(number)*vrednosti[y]*0.60<<endl; sell(bericena(number)*vrednosti[y]*0.60); skladminus(vrednosti[y]); break;
                case 19:std::cout<<bericena(number)*vrednosti[y]*0.55<<endl; sell(bericena(number)*vrednosti[y]*0.55); skladminus(vrednosti[y]); break;
                case 20:std::cout<<bericena(number)*vrednosti[y]*0.50<<endl; sell(bericena(number)*vrednosti[y]*0.50); skladminus(vrednosti[y]); break;
                default: std::cout<<bericena(number)*vrednosti[y]*0<<endl;sell(bericena(number)*vrednosti[y]*0); skladminus(vrednosti[y]); break;
                }
                stockminus(vrednosti[y],number);
                j=j-vrednosti[y];
                vrednosti[y]=-1;
                dnevi[y]=-1;
            }
            else
            {
                switch(dan)
                {
                case 11: sell(bericena(number)*j*0.95); skladminus(j); break;
                case 12: sell(bericena(number)*j*0.90); skladminus(j); break;
                case 13: sell(bericena(number)*j*0.85); skladminus(j); break;
                case 14: sell(bericena(number)*j*0.80); skladminus(j); break;
                case 15: sell(bericena(number)*j*0.75); skladminus(j); break;
                case 16: sell(bericena(number)*j*0.70); skladminus(j); break;
                case 17: sell(bericena(number)*j*0.65); skladminus(j); break;
                case 18: sell(bericena(number)*j*0.60); skladminus(j); break;
                case 19: sell(bericena(number)*j*0.55); skladminus(j); break;
                case 20: sell(bericena(number)*j*0.50); skladminus(j); break;
                default: sell(bericena(number)*j*0); skladminus(j); break;
                }
                stockminus(j,number);
                vrednosti[y]=vrednosti[y]-j;
                j=0;
            }
        }
        else
        {
            if(j >= vrednosti[y])
            {   sell(bericena(number)*vrednosti[y]);
                skladminus(vrednosti[y]);
                stockminus(vrednosti[y],number);
                j=j-vrednosti[y];
                vrednosti[y]=-1;
                dnevi[y]=-1;
            }
            else
            {
                sell(bericena(number)*j);
                skladminus(j);
                stockminus(j,number);
                vrednosti[y]=vrednosti[y]-j;
                j=0;
            }
        }
    y++;
    }
    beri1.open("skladiscenje.txt");
    beri3.open("skladiscenjed.txt");
    pisi1.open("skladiscenje1.txt");
    beri2.open("skladiscenjedan.txt");
    pisi2.open("skladiscenjedan1.txt");
    pisi3.open("skladiscenjed1.txt");
    y=0;
    while(beri1 >> spre)
    {
        if(mesto[y]==i)
        {
            if(vrednosti[y]==-1)
                pisi1 << -1 <<endl;
            else
                pisi1 << vrednosti[y] <<endl;
            y++;
        }
        else
            pisi1 << spre <<endl;
        i++;
    }
    y=0;
    i=0;
        while(beri2 >> t)
    {
        if(mesto[y]==i)
        {
            if(vrednosti[y]==-1)
                pisi2 << -1 <<endl;
            else
                pisi2 << vrednosti[y] <<endl;
            y++;
        }
        else
            pisi2 << t <<endl;
        i++;
    }
    y=0;
    i=0;
        while(beri3 >> t)
    {
        if(mesto[y]==i)
        {
            if(vrednosti[y]==-1)
                pisi3 << -1 <<endl;
            else
                pisi3 << vrednosti[y] <<endl;
            y++;
        }
        else
            pisi3 << t <<endl;
        i++;
    }

    beri1.close();
    beri3.close();
    pisi1.close();
    beri2.close();
    pisi2.close();
    pisi3.close();
    remove("skladiscenje.txt");
    rename("skladiscenje1.txt","skladiscenje.txt");
    remove("skladiscenjed.txt");
    rename("skladiscenjed1.txt" , "skladiscenjed.txt");
    remove("skladiscenjedan.txt");
    rename("skladiscenjedan1.txt","skladiscenjedan.txt");
}

void novdan()
{
    int i;
    for(i=0;i<100;i++)
    {
        if(dnevi[i]>0)
        dnevi[i] --;
    }
        for(int i=0;i<10;i++)
    std::cout<<"*";
    std::cout<<endl<<"NOV DAN"<<endl;
        for(int i=0;i<10;i++)
    std::cout<<"*";
    std::cout<<endl;
}
int IzpisRaz()
{
    beri1.open("letnicas.txt");
    string cas;
    beri1 >> cas;
    if(cas=="poletje")
       {
           std::cout<<"Izredne vremenske razmere: suša"<<endl;
           beri1.close();
           return 1;
       }
    else if(cas=="jesen")
        {
            std::cout<<"Izredne vremenske razmere: prekomerne padavine"<<endl;
            beri1.close();
            return 2;
        }
    else if(cas=="zima")
        {
            std::cout<<"Izredne vremenske razmere: poledica"<<endl;
            beri1.close();
            return 3;
        }
    else if(cas=="pomlad")
        {
            std::cout<<"Izredne vremenske razmere: prekomerne padavine"<<endl;
            beri1.close();
            return 4;
        }
}
void izpisCena()
{
    float cena[5];
    int j=0;
    beri1.open("cena.txt");
    while(beri1 >> cena[j])
        j++;
    beri1.close();
    for(int i=0;i<10;i++)
    std::cout<<"*";
    std::cout<<endl;
    std::cout<<"Trenutne cene so"<<endl;
    for(int i=0;i<5;i++)
    {
        switch(i)
        {
                case 0: std::cout<<"Grozdje : "<<cena[i]<<endl; break;
                case 1: std::cout<<"Lubenice : "<<cena[i]<<endl;  break;
                case 2: std::cout<<"Krompir : "<<cena[i]<<endl;  break;
                case 3: std::cout<<"Paradiznik : "<<cena[i]<<endl;  break;
                case 4: std::cout<<"Koruza : "<<cena[i]<<endl;  break;
        }
    }
    for(int i=0;i<10;i++)
    std::cout<<"*";
    std::cout<<endl;
}
bool RazChange()
{
    beri1.open("letnicas.txt");
    string cas;
    int j;
    beri1 >> cas;
    while(beri1 >> j);
    beri1.close();
    pisi1.open("letnicas.txt");
    if(j==0)
    {
        j=10;
        if(cas=="poletje")
        {
            pisi1<<"jesen"<<endl;
            pisi1<<j<<endl;
        }
        if(cas=="zima")
        {
            pisi1<<"pomlad"<<endl;
            pisi1<<j<<endl;
        }
        if(cas=="jesen")
        {
            pisi1<<"zima"<<endl;
            pisi1<<j<<endl;
        }
        if(cas=="pomlad")
        {
            pisi1<<"poletje"<<endl;
            pisi1<<j<<endl;
        }
        pisi1.close();
       return 1;
    }
    else
    {
        j=j-1;
        pisi1<<cas<<endl;
        pisi1<<j<<endl;
        pisi1.close();
        return 0;
    }

}
#endif // DATA_H_INCLUDED
