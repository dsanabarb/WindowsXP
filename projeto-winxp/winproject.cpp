#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//funções
void carregandoXP();
void senha();
void desligandoXP();
void areatrabalho();
void discador();
void redeconectada();
void menuiniciar();
void logoffXP();
void lixeira();
void galeria();
void chrome();
void facebook();
void msn();
void twitter();
void pesquisa();
void bitcoin();
void exibirCalendario();

//variáveis globais
int p=0;
int soma;
int acessorede=0;

main()
{
    while(p==0)
    {
        initwindow(800,600,"Windows XP",300,100);
        carregandoXP();
    }

    while(p==1)
    {

        if(mousex() >= 24 && mousex() <= 48 && mousey() >= 528 && mousey() <= 554 && ismouseclick (WM_LBUTTONDOWN))
        {
            desligandoXP();
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(mousex() >= 496 && mousex() <= 653 && mousey() >= 305 && mousey() <= 329 && ismouseclick (WM_LBUTTONDOWN))
        {
            senha();
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(mousex() >= 685 && mousex() <= 707 && mousey() >= 305 && mousey() <= 329 && ismouseclick (WM_LBUTTONDOWN)&& soma == 202)
        {
            areatrabalho();
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(mousex() >= 685 && mousex() <= 707 && mousey() >= 305 && mousey() <= 329 && ismouseclick (WM_LBUTTONDOWN)&& soma != 202)
        {
            PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }

    while(p==2)
    {
        if(mousex() >= 9 && mousex() <= 69 && mousey() >= 243 && mousey() <= 294 && ismouseclick (WM_LBUTTONDOWN) && acessorede == 0)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            discador();
        }

        if(mousex() >= 9 && mousex() <= 69 && mousey() >= 243 && mousey() <= 294 && ismouseclick (WM_LBUTTONDOWN) && acessorede == 1)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            redeconectada();
        }

        if(mousex() >= 0 && mousex() <= 94 && mousey() >= 572 && mousey() <= 597 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            menuiniciar();
        }

        if(mousex() >= 12 && mousex() <= 69 && mousey() >= 4 && mousey() <= 49 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            lixeira();

        }
        if(mousex() >= 15 && mousex() <= 70 && mousey() >= 83 && mousey() <=145 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            galeria();
        }

        if(mousex() >= 11 && mousex() <= 75 && mousey() >= 165 && mousey() <= 224 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            bitcoin();
        }

        if(mousex() >= 6 && mousex() <= 78 && mousey() >= 319 && mousey() <= 370 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            chrome();
        }

        if(mousex() >= 726 && mousex() <= 800 && mousey() >= 571 && mousey() <= 600 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            exibirCalendario();
        }
    }
}


void carregandoXP()
{
    readimagefile("loading1.jpg",0,0,800,600);
    delay(1000);
    readimagefile("loading2.jpg",0,0,800,600);
    delay(1500);
    readimagefile("loading3.jpg",0,0,800,600);
    delay(500);
    readimagefile("loading4.jpg",0,0,800,600);
    delay(1500);
    readimagefile("loading5.jpg",0,0,800,600);
    delay(1200);
    readimagefile("loading6.jpg",0,0,800,600);
    delay(1000);
    readimagefile("loading7.jpg",0,0,800,600);
    delay(950);
    readimagefile("tela-login.jpg",0,0,800,600);
    PlaySound(TEXT("startup.wav"),NULL,SND_SYNC);
    p = 1;
}

void desligandoXP()
{
    clearmouseclick(WM_LBUTTONDOWN);
    readimagefile("shutting-down.jpg",0,0,800,600);
    PlaySound(TEXT("shutdown.wav"),NULL,SND_SYNC);
    delay(1500);
    closegraph();
    p = 0;
}

void senha()
{
    int x1=496, y1=305, x2=653, y2=329, i=0, tecla;
    char pontodesenha[5] = {0};
    int converte = 42;
    char s[5];
    soma = 0;
    setcolor(15);
    rectangle(x1, y1, x2, y2);
    setfillstyle(1,15);
    bar(x1+1, y1+1, x2, y2);

    do
    {
        if(kbhit())
        {
            tecla = getch();
            if(tecla >= 48 && tecla <= 57)
            {
                s[i] = tecla;
                pontodesenha[i] = (char) converte;
                i++;
                s[i] = '\0';
                setfillstyle(1,15);
                bar(x1+1, y1+1, x2, y2);
                setbkcolor(15);
                setcolor(0);
                outtextxy(x1+20, y1+5, pontodesenha);
            }
        }

        if (tecla == 8)
        {
            if(i > 0)
            {
                i--;
                s[i] = '\0';
                pontodesenha[i] = '\0';
                setfillstyle(1,15);
                bar(x1+1, y1+1, x2, y2);
                setbkcolor(15);
                setcolor(0);
                outtextxy(x1+20, y1+5, pontodesenha);
            }
        }
    }while (tecla != 13);

    soma = s[0] + s[1] + s[2] + s[3];
}

void areatrabalho()
{
    readimagefile("area-trabalho.jpg",0,0,800,600);
    PlaySound(TEXT("logon.wav"),NULL,SND_SYNC);
    p=2;
}

void discador()
{
  p=3;
  int conecta = 0;
  soma = 0;
  while(p==3)
  {
    readimagefile("disk-aberto.jpg",0,0,800,600);

    if(mousex() >= 495 && mousex() <= 505 && mousey() >= 199 && mousey() <= 213 && ismouseclick (WM_LBUTTONDOWN))
        {
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
            clearmouseclick(WM_LBUTTONDOWN);
        }
    if(mousex() >= 395 && mousex() <= 457 && mousey() >= 293 && mousey() <= 306 && ismouseclick (WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x1=395, y1=292, x2=457, y2=305, i=0, tecla;
        char pontodesenha[5] = {0};
        int converte = 42;
        char s[5];
        soma = 0;
        setcolor(15);
        rectangle(x1, y1, x2, y2);
        setfillstyle(1,15);
        bar(x1+1, y1+1, x2, y2);

        do
        {
            if(kbhit())
            {
                tecla = getch();
                if(tecla >= 48 && tecla <= 57)
                {
                    s[i] = tecla;
                    pontodesenha[i] = (char) converte;
                    i++;
                    s[i] = '\0';
                    setfillstyle(1,15);
                    bar(x1+1, y1+1, x2, y2);
                    setbkcolor(15);
                    setcolor(0);
                    outtextxy(x1+20, y1, pontodesenha);
                }
            }

            if (tecla==8)
            {
                if(i > 0)
                {
                    i--;
                    s[i] = '\0';
                    pontodesenha[i] = '\0';
                    setfillstyle(1,15);
                    bar(x1+1, y1+1, x2, y2);
                    setbkcolor(15);
                    setcolor(0);
                    outtextxy(x1+20, y1, pontodesenha);
                }
            }
        }while (tecla != 13);

        soma = s[0] + s[1] + s[2] + s[3];
        }

        if(mousex() >= 336 && mousex() <= 400 && mousey() >= 346 && mousey() <= 363 && ismouseclick (WM_LBUTTONDOWN) && soma == 202)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("disk1.jpg",0,0,800,600);
            delay(1500);
            readimagefile("disk2.jpg",0,0,800,600);
            delay(1500);
            readimagefile("disk3.jpg",0,0,800,600);
            delay(200);
            readimagefile("disk4.jpg",0,0,800,600);
            delay(1500);
            readimagefile("disk5.jpg",0,0,800,600);
            delay(2000);
            readimagefile("disk6.jpg",0,0,800,600);
            delay(1000);
            PlaySound(TEXT("dial-up.wav"),NULL,SND_SYNC);
            readimagefile("disk7.jpg",0,0,800,600);
            delay(1000);
            readimagefile("disk8.jpg",0,0,800,600);
            delay(1100);
            readimagefile("disk9.jpg",0,0,800,600);
            delay(2500);
            conecta = round((double)rand() / RAND_MAX); //conecta? 1 para sim e 0 para não
            if(conecta==1)
            {
                readimagefile("disk-sucessfull.jpg",0,0,800,600);
                PlaySound(TEXT("tada.wav"),NULL,SND_SYNC);
                acessorede = 1; //acesso a internet
                delay(500);
                readimagefile("area-trabalho.jpg",0,0,800,600);
                p=2;
            }
            if(conecta==0)
            {
                readimagefile("disk-bad.jpg",0,0,800,600);
                PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
                acessorede = 0; //sem internet
                delay(500);
                readimagefile("area-trabalho.jpg",0,0,800,600);
                p=2;
            }
        }
        if(mousex() >= 336 && mousex() <= 400 && mousey() >= 346 && mousey() <= 363 && ismouseclick (WM_LBUTTONDOWN) && soma != 202)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
        }
    }
}

void redeconectada()
{
    p=4;
    while(p==4)
    {
        readimagefile("disk-sucessfull.jpg",0,0,800,600);
        if(mousex() >= 495 && mousex() <= 505 && mousey() >= 199 && mousey() <= 213 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("area-trabalho.jpg",0,0,800,600);
            p=2;
        }
    }
}

void logoffXP()
{
    readimagefile("tela-login.jpg",0,0,800,600);
    PlaySound(TEXT("logoff.wav"),NULL,SND_SYNC);
    p=1;
}

void menuiniciar()
{
    readimagefile("menu-iniciar.jpg",0,0,800,600);
    p=5;

    while (p==5)
    {
        if(mousex() >= 178 && mousex() <= 198 && mousey() >= 538 && mousey() <= 560 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            logoffXP();
            main();
        }

        if(mousex() >= 253 && mousex() <= 272 && mousey() >= 539 && mousey() <= 559 && ismouseclick (WM_LBUTTONDOWN))
        {
            desligandoXP();
        }

        if(mousex() >= 0 && mousex() <= 94 && mousey() >= 572 && mousey() <= 597 && ismouseclick (WM_LBUTTONDOWN))
        {
            readimagefile("area-trabalho.jpg",0,0,800,600);
            p=2;
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(mousex() >= 3 && mousex() <= 180 && mousey() >= 159 && mousey() <= 197 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            galeria();
        }

        if(mousex() >= 194 && mousex() <= 352 && mousey() >= 163 && mousey() <= 194 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            galeria();
        }
    }

}

void lixeira()
{
    readimagefile("lixeira-aberta.jpg",0,0,800,600);
    p=6;

    while(p==6)
    {

        if(mousex() >= 606 && mousex() <= 627 && mousey() >= 23 && mousey() <= 43 && ismouseclick (WM_LBUTTONDOWN))
        {
            readimagefile("area-trabalho.jpg",0,0,800,600);
            p = 2;
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(mousex() >= 317 && mousex() <= 540 && mousey() >= 121 && mousey() <= 371 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            PlaySound(TEXT("bark.wav"),NULL,SND_SYNC);
        }

        if(mousex() >= 61 && mousex() <= 124 && mousey() >= 167 && mousey() <= 182 && ismouseclick (WM_LBUTTONDOWN))
        {
            readimagefile("area-trabalho.jpg",0,0,800,600);
            p=2;
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }

}

void galeria()
{
    readimagefile("foto-inicio.jpg", 0, 0, 800, 600);
    p=7;
    int t=0;

    while (p==7)
    {


        // fechar janela
        if (mousex() >= 672 && mousex() <=691 && mousey() >=13 && mousey() <=31 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("area-trabalho.jpg", 0, 0, 800, 600);
            p=2;
        }
        //próxima foto (início)
        if (mousex () >= 352 && mousex() <= 367 && mousey() >= 467 && mousey () <= 481 && ismouseclick (WM_LBUTTONDOWN) && t==0)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("foto-meio.jpg", 0, 0, 800, 600);
            t=1;

        }

        // voltar foto (meio)
        if (mousex() >= 328 && mousex () <= 343 && mousey() >= 465 && mousey() <= 481 && ismouseclick (WM_LBUTTONDOWN) && t==1)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("foto-inicio.jpg",0, 0, 800, 600);
            t=0;
        }


        //próxima foto (fim)
         if (mousex () >= 352 && mousex() <= 367 && mousey() >= 467 && mousey () <= 481 && ismouseclick (WM_LBUTTONDOWN) && t==1)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("foto-fim.jpg", 0, 0, 800, 600);
            t=2;
        }

        // voltar foto (fim)
        if (mousex() >= 328 && mousex () <= 343 && mousey() >= 465 && mousey() <= 481 && ismouseclick (WM_LBUTTONDOWN) && t==2)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("foto-meio.jpg",0, 0, 800, 600);
            t=1;
        }

    }
}

void chrome()
{
    p=10;

    if(acessorede==1 && p==10)
    {
        readimagefile("chrome-loading-1.jpg",0,0,800,600);
        delay(500);
        readimagefile("chrome-loading-2.jpg",0,0,800,600);
        delay(1000);
        readimagefile("chrome-loading-1.jpg",0,0,800,600);
        delay(500);
        readimagefile("chrome-loading-2.jpg",0,0,800,600);
        delay(1000);
        readimagefile("chrome-1.jpg",0,0,800,600);
        p=11;
    }

    if(acessorede==0 && p==10)
    {
        readimagefile("chrome-loading-1.jpg",0,0,800,600);
        delay(500);
        readimagefile("chrome-loading-2.jpg",0,0,800,600);
        delay(1000);
        readimagefile("chrome-loading-1.jpg",0,0,800,600);
        delay(500);
        readimagefile("chrome-loading-2.jpg",0,0,800,600);
        delay(1000);
        readimagefile("chrome-error.jpg",0,0,800,600);
        p=16;
    }

    while(p==11)
    {
        if(mousex() >= 778 && mousex() <= 796 && mousey() >= 3 && mousey() <= 22 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
        }

        if(mousex() >= 293 && mousex() <= 357 && mousey() >= 321 && mousey() <= 339 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            facebook(); //facebook
        }

        if(mousex() >= 442 && mousex() <= 505 && mousey() >= 321 && mousey() <= 339 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            twitter(); //twitter
        }

        if(mousex() >= 369 && mousex() <= 432 && mousey() >= 321 && mousey() <= 339 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            msn(); //MSN
        }

        if(mousex() >= 538 && mousex() <= 556 && mousey() >= 293 && mousey() <= 307 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            pesquisa(); //Pesquisar
        }

    }

    while(p==16)
    {
        if(mousex() >= 778 && mousex() <= 796 && mousey() >= 3 && mousey() <= 22 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
        }
    }
}

void facebook()
{
    p=12;
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("facebook-load1.jpg",0,0,800,600);
    delay(500);
    readimagefile("facebook-load2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("facebook-load3.jpg",0,0,800,600);
    delay(1500);
    readimagefile("facebook-load4.jpg",0,0,800,600);
    delay(500);
    readimagefile("facebook-loaded.jpg",0,0,800,600);
    PlaySound(TEXT("fb-message.wav"),NULL,SND_SYNC);

    while(p==12)
    {
        if(mousex() >= 1 && mousex() <= 23 && mousey() >= 26 && mousey() <= 48 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            chrome();
        }

        if(mousex() >= 778 && mousex() <= 796 && mousey() >= 3 && mousey() <= 22 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
        }
    }
}
void msn()
{
    p=13;
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("msn-load1.jpg",0,0,800,600);
    delay(500);
    readimagefile("msn-load2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("msn-load3.jpg",0,0,800,600);
    delay(1500);
    readimagefile("msn-load4.jpg",0,0,800,600);
    delay(500);
    readimagefile("msn-loaded.jpg",0,0,800,600);
    PlaySound(TEXT("msn-entered.wav"),NULL,SND_SYNC);

    while(p==13)
    {
        if(mousex() >= 1 && mousex() <= 23 && mousey() >= 26 && mousey() <= 48 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            chrome();
        }

        if(mousex() >= 778 && mousex() <= 796 && mousey() >= 3 && mousey() <= 22 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
        }
    }
}
void twitter()
{
    p=14;
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("twitter-load1.jpg",0,0,800,600);
    delay(500);
    readimagefile("twitter-load2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("twitter-load3.jpg",0,0,800,600);
    delay(1500);
    readimagefile("twitter-load4.jpg",0,0,800,600);
    delay(500);
    readimagefile("twitter-loaded.jpg",0,0,800,600);
    PlaySound(TEXT("tw-message.wav"),NULL,SND_SYNC);

    while(p==14)
    {
        if(mousex() >= 1 && mousex() <= 23 && mousey() >= 26 && mousey() <= 48 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            chrome();
        }

        if(mousex() >= 778 && mousex() <= 796 && mousey() >= 3 && mousey() <= 22 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
        }
    }
}

void pesquisa()
{
    p=15;
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("chrome-loading-1.jpg",0,0,800,600);
    delay(500);
    readimagefile("chrome-loading-2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("search-load1.jpg",0,0,800,600);
    delay(500);
    readimagefile("search-load2.jpg",0,0,800,600);
    delay(1000);
    readimagefile("search-load3.jpg",0,0,800,600);
    delay(1500);
    readimagefile("search-load4.jpg",0,0,800,600);
    delay(500);
    readimagefile("search-loaded.jpg",0,0,800,600);
    PlaySound(TEXT("chicken.wav"),NULL,SND_SYNC);

    while(p==15)
    {
        if(mousex() >= 1 && mousex() <= 23 && mousey() >= 26 && mousey() <= 48 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            chrome();
        }

        if(mousex() >= 778 && mousex() <= 796 && mousey() >= 3 && mousey() <= 22 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            p=2;
            readimagefile("area-trabalho.jpg",0,0,800,600);
        }
    }
}

void bitcoin()
{
    p=17;

    readimagefile("trab-errconfirm.jpg",0,0,800,600);
    PlaySound(TEXT("error.wav"),NULL,SND_SYNC);

    while(p==17)
    {
        if(mousex() >= 375 && mousex() <= 451 && mousey() >= 294 && mousey() <= 316 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("trab-err1.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err2.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err3.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err4.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err5.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err6.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err7.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err8.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err9.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err10.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err11.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err12.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err13.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err14.jpg",0,0,800,600);
            PlaySound(TEXT("error-frenetic.wav"),NULL,SND_SYNC);

            readimagefile("trab-err15.jpg",0,0,800,600);

            readimagefile("fatal.jpg",0,0,800,600);
            PlaySound(TEXT("fatal-error.wav"),NULL,SND_SYNC);

            readimagefile("blue-screen.jpg",0,0,800,600);
            PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
            delay(3500);
            p=0;
            closegraph();
        }
    }

}

void exibirCalendario()
{
    readimagefile("calendario.jpg",0,0,800,600);
    p=18;

    while(p==18)
    {

        if(mousex() >= 726 && mousex() <= 800 && mousey() >= 571 && mousey() <= 600 && ismouseclick (WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("area-trabalho.jpg",0,0,800,600);
            p=2;
        }
    }
}



