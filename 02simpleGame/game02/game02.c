#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "konstanteak.h"
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int seguridadId1, seguridadId2;
void azalpena(int ebentu);
int FrameKop = 6;  
int frame = 0; 
int PantailaNum = 0;

JOKO_ELEMENTUA jokalaria, fondoa, dialogo;
int robo = 0;
int next = -1;
    int MATRIZ_1[ABEAK][ZUTABEAK] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}
    };
int MATRIZ_2[ABEAK][ZUTABEAK] = {
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {0, 0, 0, 0, 0, 1, 0, 2, 2, 3, 1, 3, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int MATRIZ_3[ABEAK][ZUTABEAK] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1}
};
int MATRIZ_4[ABEAK][ZUTABEAK] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
int MATRIZ_5[ABEAK][ZUTABEAK] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {2, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 4},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int MATRIZ_6[ABEAK][ZUTABEAK] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1}
};
int mapa[ABEAK][ZUTABEAK];
int giltza=0, erropa=0;
void irudiaKenduDialogo();
void mapakopiatu(int PantallaNum);



void jokoaAurkeztu(void)
{
    int ebentu = 0;
    fondoa.id = JOKOA_fondoaIrudiaSortu(PantailaNum);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    PantailaNum++;
    pantailaGarbitu();
    pantailaBerriztu();

}

EGOERA jokatu(void)
{

    int mugitu = 0, ebentu = 0;;
    EGOERA  egoera = JOLASTEN;
    jokalaria.pos.x = SCREEN_WIDTH - 384;
    jokalaria.pos.y = SCREEN_HEIGHT - 128 ;
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    fondoa.id = JOKOA_fondoaIrudiaSortu(PantailaNum);
    mapakopiatu(PantailaNum);
    jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu,jokalaria.pos);
    dialogo.id=dialogoa_sortu(NOTA);
    do {
        Sleep(5); 
        //Gertaerak jaso
        ebentu = ebentuaJasoGertatuBada();
        mugitu = EbentuakJaso(ebentu);
        if (mugitu != 0) {
            irudiaKenduDialogo();   
            irudiaKendu(jokalaria.id);
            jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu, jokalaria.pos);
            jokalaria.pos = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos, mugitu);
            //Hurrengo spritera pasatu
            frame = ((frame + 1) % FrameKop);
        }
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiakMarraztu();
        pantailaBerriztu();
        egoera = JOKOA_egoera(jokalaria);
    } while (egoera == JOLASTEN);
    azalpena(ebentu);
    toggleMusic();
    audioTerminate();
    return egoera;
}
void azalpena(int ebentu) {
    irudiaKendu(jokalaria.id);
    irudiaKendu(fondoa.id);
    fondoa.id = irudiaKargatu(AZALPENA);
    irudiaMugitu(fondoa.id, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    while (ebentu != TECLA_RETURN)
    {
        ebentu = ebentuaJasoGertatuBada();
    }
    irudiaKendu(fondoa.id);
}
int EbentuakJaso(int ebentu) {
    int mugitu=0;
    switch (ebentu)
    {
    case TECLA_UP:
        mugitu = GORA;
        break;
    case TECLA_DOWN:
        mugitu = BEHERA;
        break;
    case TECLA_RIGHT:
        mugitu = ESKUMA;
        break;
    case TECLA_LEFT:
        mugitu = EZKERRA;
        break;
    case TECLA_SPACE:
        jokalaria.pos = Interaktuatu(jokalaria.pos, PantailaNum, mugitu);
        break;
    default:
        mugitu = 0;
        break;
    }
    return mugitu;
}
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria) {
    EGOERA  ret = JOLASTEN;
    if (PantailaNum == 7) {
        ret = JOLASTEN2;
    }
    return ret;
}
int JOKOA_fondoaIrudiaSortu(int PantallaNum) {
    int fondoId;
    char* FONDO_PATH = FONDO01;
    
    switch (PantallaNum)
    {
    case 0:
        FONDO_PATH = FONDO00;
        break;
    case 1:
        FONDO_PATH = FONDO01; 
        break;
    case 2:
        FONDO_PATH = FONDO02;
        break;
    case 3:
        FONDO_PATH = FONDO03;
        break;
    case 4:
        FONDO_PATH = FONDO04;
        break;
    case 5:
        FONDO_PATH = FONDO05;
        break;
    case 6:
        FONDO_PATH = FONDO06;
        break;
    }
    fondoId = irudiaKargatu(FONDO_PATH);
    irudiaMugitu(fondoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoId;

}
int dialogoa_sortu(char* DIALOGO_PATH) {
    int dialogoId;
    
    dialogoId = irudiaKargatu(DIALOGO_PATH);
    irudiaMugitu(dialogoId, 12, 384);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return dialogoId;

}
POSIZIOA pantailaAldatu(POSIZIOA posizioa, int next) {
   if(next==1){
       PantailaNum++;
   }
   else
   {
       PantailaNum--;
   }
   irudiaKendu(fondoa.id);
   fondoa.id = JOKOA_fondoaIrudiaSortu(PantailaNum);
   mapakopiatu(PantailaNum);
   jokalaria.id = irudiaKargatu(".\\img\\sprite bmp\\33.bmp");
   posizioa = PertsonaiaKolokatu(jokalaria.pos,next);
   irudiaMugitu(jokalaria.id, posizioa.x, posizioa.y);
   return posizioa;
}
void irudiaKenduDialogo() {
    if (dialogo.id != -1) {   
        irudiaKendu(dialogo.id);
        dialogo.id = -1; 
    }
}

POSIZIOA PertsonaiaKolokatu(POSIZIOA posizioa, int next) {
    int i=0,j, kolokatuta=0, atea;
    if (next) {
        atea = 4;
    }
    else {
        atea = 2;
    }
        while (i < ABEAK && !kolokatuta) {
            j = 0;
            while (j < ZUTABEAK && !kolokatuta) {
                if (mapa[i][j] == atea) {
                    posizioa.x = j * 64;
                    posizioa.y = i * 64;
                    posizioa.x -= 32;
                    posizioa.y -= 32;
                    kolokatuta = 1;
                }
                j++;
            }
            i++;
        }
    return posizioa;
}


POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum, int mugitu) {
    int ebentu = 0;
    int NewPosX = posizioa.x, NewPosY = posizioa.y;
    int erantzuna1 = 0, erantzuna2 = 0;
    int num[50];
    char str1[50];
    NewPosX += ANCHO / 2;
    NewPosY += ALTO / 2;
    int bloqueX = NewPosX / BLOKEAREN_TAMAINA;
    int bloqueY = NewPosY / BLOKEAREN_TAMAINA;
 
    irudiaKenduDialogo();
    
    switch (mapa[bloqueY][bloqueX]) {
        case 2:
            switch (PantailaNum)
            {
                default:
                    next = 1;
                    posizioa = pantailaAldatu(posizioa, next);
                    break;
                case 2:
                    if (giltza != 1) {
                        dialogo.id = dialogoa_sortu(ATEA_ITXITA);
                    }
                    else {
                        next = 1;
                        posizioa = pantailaAldatu(posizioa, next);
                    }
                    break;
                case 4:
                    if (erropa != 1) {
                        dialogo.id = dialogoa_sortu(UNIFORMEA_FALTA);
                    }
                    else {
                        next = 1;
                        posizioa = pantailaAldatu(posizioa, next);
                    }
                    break;
                case 6:
                    if (robo != 1) {
                        dialogo.id = dialogoa_sortu(DIRUA_FALTA);
                    }
                    else {
                        next = 1;
                        posizioa = pantailaAldatu(posizioa, next);
                    }
            }        
            break;
        case 3:
               
                switch (PantailaNum) {
                case 2:
                   if (giltza != 1) {
                        giltza = 1;
                        irudiaKenduDialogo();
                        dialogo.id = dialogoa_sortu(GILTZA_HARTU);
                    }
                    break;
                case 3:
                    if (erropa != 1) {
                        erropa = 1;
                        irudiaKenduDialogo();
                        dialogo.id = dialogoa_sortu(UNIFORMEA_HARTU);
                    }
                    break;
                case 5:
                    if (robo != 1) {
                        
                        dialogo.id = dialogoa_sortu(ARIKETA);
                        erantzuna1 = auzazkoEkuazioaSortu(num, str1);
                        erantzuna2 = ErantzunaIdatzi(num, str1);
                        ErantzunaZuzenadenKalkulatu(erantzuna1, erantzuna2);
                    }
                    break;
                }
                break;
            case 4:
                next = 0;
                posizioa = pantailaAldatu(posizioa, next);
                break;
            default:
                break;
    }
    return posizioa;
}
void ErantzunaZuzenadenKalkulatu(int erantzuna1, int erantzuna2) {
    if (erantzuna1 == erantzuna2) {
        irudiaKenduDialogo();
        dialogo.id = dialogoa_sortu(ZUZENA);
        robo = 1;
    }
    else {
        irudiaKenduDialogo();
        dialogo.id = dialogoa_sortu(ERROREA);
    }
}
int auzazkoEkuazioaSortu(int num[], char str1[]) {
    int erantzuna = 0;
    srand((unsigned int)time(NULL));
    num[0] = rand() % 10;
    num[1] = rand() % 10;
    num[2] = rand() % 10;
    num[3] = rand() % 10;
    while (num[2] == 0) {
        num[2] = rand() % 10;
    }
    sprintf(str1, "(%d + %d) / %d + %d = ", num[0], num[1], num[2], num[3]);
    erantzuna = (num[0] + num[1]) / num[2] + num[3];
    textuaIdatzi(448, 478, str1);
    pantailaBerriztu();
    return erantzuna;
 }
int JOKOA_jokalariaIrudiaSortu(int mugitu, POSIZIOA posizioa)
{
    int PertsonaiaId = -1;
    char image_PATH[250];
    int sprite_num;
    int Direction = 33;
    //Norabide bakoitzerako norabideko lehen spritaren balioa eman
    switch (mugitu)
    {
    case GORA:
        Direction = 41;
        break;
    case BEHERA:
        Direction = 33;
        break;
    case EZKERRA:
        Direction = 57;
        break;
    case ESKUMA:
        Direction = 49;
        break;
    default:
        break;
    }
    //Lehen spritaren balioa spritaren dagoen framearen kopuruarekin batu.
    sprite_num = frame + Direction;
    //irudia kokatuta dagoen bidea zehaztu.
    sprintf(image_PATH, ".\\img\\sprite bmp\\%d.bmp", sprite_num);
    //Pertsonaia dagokion posizioan marraztu.
    PertsonaiaId = irudiaKargatu(image_PATH);
    irudiaMugitu(PertsonaiaId, posizioa.x, posizioa.y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return PertsonaiaId;
}


POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu) {
    int NewPosX = posizioa.x, NewPosY = posizioa.y;
    int kolisioa;
    //Jokalariaren ondorengo posizioa kalkulatu.
    switch (mugitu) {
    case GORA:
        NewPosY -= 5;
        break;
    case BEHERA:
        NewPosY += 5;
        break;
    case ESKUMA:
        NewPosX += 5;
        break;
    case EZKERRA:
        NewPosX -= 5;
        break;
    default:
        break;
    }
    kolisioa=kolisioarenDetekzioa(NewPosX,NewPosY);
    if (!kolisioa) {
        posizioa.x = NewPosX;
        posizioa.y = NewPosY;
    }
    return posizioa;
}
 int ErantzunaIdatzi(int num[], char str1[]) {
     
     int erantzuna=0, ebentu=0;
     while (ebentu != TECLA_RETURN)
     {
         ebentu = ebentuaJasoGertatuBada();
         switch (ebentu)
         {
         case TECLA_0:
             erantzuna *= 10;
             break;
         case TECLA_1:
             erantzuna *= 10;
             erantzuna += 1;
             break;
         case TECLA_2:
             erantzuna *= 10;
             erantzuna += 2;
             break;
         case TECLA_3:
             erantzuna *= 10;
             erantzuna += 3;
             break;
         case TECLA_4:
             erantzuna *= 10;
             erantzuna += 4;
             break;
         case TECLA_5:
             erantzuna *= 10;
             erantzuna += 5;
             break;
         case TECLA_6:
             erantzuna *= 10;
             erantzuna += 6;
             break;
         case TECLA_7:
             erantzuna *= 10;
             erantzuna += 7;
             break;
         case TECLA_8:
             erantzuna *= 10;
             erantzuna += 8;
             break;
         case TECLA_9:
             erantzuna *= 10;
             erantzuna += 9;
             break;
         case 8:
             erantzuna /= 10;
         }
         if (ebentu != 0) {
             irudiaKenduDialogo();
             dialogo.id = dialogoa_sortu(ARIKETA);
             sprintf(str1, "(%d + %d) / %d + %d = %d ", num[0], num[1], num[2], num[3], erantzuna);
             textuaIdatzi(448, 478, str1);
             pantailaBerriztu();
         }
     }

     return erantzuna;
}
void menua() {
    int ebentu = 0;
    //menuko lehen irudia marraztu.
    int fondoId = irudiaKargatu(".\\img\\MENUA.bmp");
    irudiaMugitu(fondoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    do {
        //ze tekla sakatu den konprobatu
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu) {
        case TECLA_1:
            irudiaKendu(fondoId);
            break;
        case TECLA_2:
            irudiaKendu(fondoId);
            fondoId = irudiaKargatu(".\\img\\KREDITUAK.bmp");
            irudiaMugitu(fondoId, 0, 0);
            irudiakMarraztu();
            pantailaBerriztu();
            while (ebentu != TECLA_RETURN) {
                ebentu = ebentuaJasoGertatuBada();
            }
            irudiaKendu(fondoId);
            fondoId = irudiaKargatu(".\\img\\MENUA.bmp");
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
            break;
        default:
            break;
        }
    } while (ebentu != TECLA_1);
}

int kolisioarenDetekzioa(int posX, int posY) {
    int Xmin, Xmax, Ymin, Ymax, bloqueXmin, bloqueXmax, bloqueYmin, bloqueYmax;
    JokalariarenErtzakKalkulatu(posX, posY, &Xmin, &Ymin, &Xmax, &Ymax);
    if (PantallarenBarruanDago(Xmin, Ymin, Xmax, Ymax)) {
        MatrizarenPosizioaKalkulatu(Xmin, Ymin, Xmax, Ymax, &bloqueXmin, &bloqueYmin, &bloqueXmax, &bloqueYmax);
        return KolisioaDetektatu(bloqueXmin, bloqueYmin, bloqueXmax, bloqueYmax);
    }
    else {
        return 1; // Pantailatik kanpo dago.
    }
}
void JokalariarenErtzakKalkulatu(int posX, int posY, int* Xmin, int* Ymin, int* Xmax, int* Ymax) {
    //Jokalariaren posizioarekiko pertsonaiaren ertzak kalkulatu.
    //Perpektibarengatik pertsonaiaren buruak kolisioak pasatu ahal ditu (Horregatik +30)
    *Xmin = posX + ANCHO / 2 - ANCHO_PERSONAJE / 2;
    *Ymin = posY + ALTO / 2 - ALTO_PERSONAJE / 2;
    *Xmax = *Xmin + ANCHO_PERSONAJE;
    *Ymax = *Ymin + ALTO_PERSONAJE;
    *Ymin += 30;
}
int PantallarenBarruanDago(int Xmin, int Ymin, int Xmax, int Ymax) {
    //Pertsonaia pantailatik atera ez dela zihurtatu.
    return (Xmin > 0 && Ymin > 0 && Xmax < SCREEN_WIDTH && Ymax < SCREEN_HEIGHT);
}
void MatrizarenPosizioaKalkulatu(int Xmin, int Ymin, int Xmax, int Ymax, int* bloqueXmin, int* bloqueYmin, int* bloqueXmax, int* bloqueYmax) {

    *bloqueXmin = Xmin / BLOKEAREN_TAMAINA;
    *bloqueYmin = Ymin / BLOKEAREN_TAMAINA;
    *bloqueXmax = Xmax / BLOKEAREN_TAMAINA;
    *bloqueYmax = Ymax / BLOKEAREN_TAMAINA;
}
int KolisioaDetektatu(int bloqueXmin, int bloqueYmin, int bloqueXmax, int bloqueYmax) {

    if (bloqueXmax < ZUTABEAK && bloqueYmax < ABEAK) {
        if (mapa[bloqueYmin][bloqueXmin] != 1 &&
            mapa[bloqueYmax][bloqueXmax] != 1 &&
            mapa[bloqueYmax][bloqueXmin] != 1 &&
            mapa[bloqueYmin][bloqueXmax] != 1) {
            return 0;
        }
        else {
            return 1;
        }
    }
    return 1; 
}
void mapakopiatu(int PantallaNum) {
    for (int i = 0; i < ABEAK; i++) {
        for (int j = 0; j < ZUTABEAK; j++) {
            switch (PantallaNum) {
            case 1:
                mapa[i][j] = MATRIZ_1[i][j];
                break;
            case 2:
                mapa[i][j] = MATRIZ_2[i][j];
                break;
            case 3:
                mapa[i][j] = MATRIZ_3[i][j];
                break;
            case 4:
                mapa[i][j] = MATRIZ_4[i][j];
                break;
            case 5:
                mapa[i][j] = MATRIZ_5[i][j];
                break;
            case 6:
                mapa[i][j] = MATRIZ_6[i][j];
                break;
            }
        }
    }
}