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

int numFrames = 6;  // Número total de imágenes en la secuencia
int frameIndex = 0; // Índice actual de la imagen en la secuencia
int PantallaNum = 0;

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
JOKO_ELEMENTUA jokalaria, fondoa, dialogo;
int robo = 0;
int next = -1;
POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum, int mugitu);
POSIZIOA pantallaAldatu(POSIZIOA posizioa, int next);
int MATRIZ_1[FILAS][COLUMNAS] = {
    //DONE!!
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}



};
int MATRIZ_2[FILAS][COLUMNAS] = {
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
int MATRIZ_3[FILAS][COLUMNAS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 2, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1}
};
int MATRIZ_4[FILAS][COLUMNAS] = {

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
int MATRIZ_5[FILAS][COLUMNAS] = {

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
int MATRIZ_6[FILAS][COLUMNAS] = {

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

int mapa[FILAS][COLUMNAS];
int giltza=0, erropa=0;
void irudiaKenduDialogo();
int mapakopiatu(int PantallaNum) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
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


void jokoaAurkeztu(void)
{
    int ebentu = 0;

    
    fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
   
    do
    {
        
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    PantallaNum++;
    pantailaGarbitu();
    pantailaBerriztu();
}

EGOERA jokatu(void)
{

    int mugitu = 0;
    EGOERA  egoera = JOLASTEN;
    int ebentu = 0;
    dialogo.id = -1;
    POSIZIOA aux;

    jokalaria.pos.x = SCREEN_WIDTH - 384;
    jokalaria.pos.y = SCREEN_HEIGHT - 128 ;
    //Uint32 time01 = SDL_GetTicks(), time02;
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    mapakopiatu(PantallaNum);
    fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
    jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu,jokalaria.pos);
    dialogo.id=dialogoa_sortu(NOTA);
    do {
        Sleep(5); 
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiakMarraztu();
        pantailaBerriztu();
        ebentu = ebentuaJasoGertatuBada();
        
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
            aux = Interaktuatu(jokalaria.pos, PantallaNum, mugitu);
            jokalaria.pos.x = aux.x;
            jokalaria.pos.y = aux.y;
            
            break;
        default:
            mugitu = 0;

            break;
        }

        if (mugitu != 0) {
            irudiaKenduDialogo();   
            irudiaKendu(jokalaria.id);
            jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu, jokalaria.pos);
            aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos, mugitu);
            jokalaria.pos.x = aux.x;
            jokalaria.pos.y = aux.y;
            frameIndex = ((frameIndex + 1) % numFrames);

        }
        egoera = JOKOA_egoera(jokalaria);
    } while (egoera == JOLASTEN);
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
    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria) {
    EGOERA  ret = JOLASTEN;
    if (PantallaNum == 7) {
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
POSIZIOA pantallaAldatu(POSIZIOA posizioa, int next) {


    irudiaKendu(fondoa.id);
   if(next==1){
       PantallaNum++;
   }
   else
   {
       PantallaNum--;
   }
   playSound(loadSound(".\\sound\\Puerta.WAV"));

   irudiaKendu(fondoa.id);
    fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
    mapakopiatu(PantallaNum);
    jokalaria.id = irudiaKargatu(".\\img\\sprite bmp\\33.bmp");
    
    switch (PantallaNum) {
    case 1:
            posizioa.x =  64;
            posizioa.y = 136;        
        break;
    case 2:
        if(next){
            
            posizioa.x = 0;
            posizioa.y = SCREEN_HEIGHT - 192;
        }
        else {
            posizioa.x = SCREEN_WIDTH / 2-64;
            posizioa.y = 192;
        }
        break;
    case 3:
        if (next) {
            posizioa.x = SCREEN_WIDTH / 2 - 64;
            posizioa.y = SCREEN_HEIGHT - 128;
        }
        else {
            posizioa.x = 128;
            posizioa.y = 236;
            irudiaKendu(seguridadId1);
            irudiaKendu(seguridadId2);
        }

        break;
    case 4:
        if (next){
        posizioa.x = SCREEN_WIDTH -128;
        posizioa.y = SCREEN_HEIGHT/2;
        }
        else {
            posizioa.x = 0;
            posizioa.y = SCREEN_HEIGHT / 2;
        }
        seguridadId1 = irudiaKargatu(MAKARRA);
        seguridadId2 = irudiaKargatu(MAKARRA);
        irudiaMugitu(seguridadId1, SCREEN_WIDTH / 2 - 256, SCREEN_HEIGHT / 2 - 110);
        irudiaMugitu(seguridadId2, SCREEN_WIDTH / 2 - 128, SCREEN_HEIGHT / 2 - 110);
        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();
        break;
    case 5:
        if (next) {
            posizioa.x = SCREEN_WIDTH - 128;
            posizioa.y = SCREEN_HEIGHT / 2 - 64;
        }
        else {
            posizioa.x = SCREEN_WIDTH / 2-64;
            posizioa.y = SCREEN_HEIGHT - 128;   
        }
        irudiaKendu(seguridadId1);
        irudiaKendu(seguridadId2);
        break;
    case 6:
        if (next) {
            posizioa.x = SCREEN_WIDTH - 384;
            posizioa.y = SCREEN_HEIGHT -128;
        }
        else {
            posizioa.x = SCREEN_WIDTH - 384;
            posizioa.y = 0;
        }
      
        break;
    }
    irudiaMugitu(jokalaria.id, posizioa.x, posizioa.y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return posizioa;

}
void irudiaKenduDialogo() {
    if (dialogo.id != -1) {   
        irudiaKendu(dialogo.id);
        dialogo.id = -1; 
    }
}


POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum, int mugitu) {
    int ebentu = 0;
    int NewPosX = posizioa.x, NewPosY = posizioa.y;
    NewPosX += ANCHO / 2;
    NewPosY += ALTO / 2;
    int bloqueX = NewPosX / TAMANO_BLOQUE;
    int bloqueY = NewPosY / TAMANO_BLOQUE;
    NewPosX -= ANCHO / 2;
    NewPosY -= ALTO / 2;
    irudiaKendu(dialogo.id);
    switch (mapa[bloqueY][bloqueX]) {
    case 2:
        if (PantallaNum == 2 && giltza!=1) {
            irudiaKendu(dialogo.id);
            dialogo.id = dialogoa_sortu(ATEA_ITXITA);
        }
        else if (PantallaNum == 4 && erropa != 1) {
            irudiaKendu(dialogo.id);
            dialogo.id = dialogoa_sortu(UNIFORMEA_FALTA);
        }
        
        else if (PantallaNum == 6) {
            if (robo != 1) {
                irudiaKendu(dialogo.id);
                dialogo.id = dialogoa_sortu(DIRUA_FALTA);
            }
            else {
                next = 1;
                posizioa = pantallaAldatu(posizioa, next);
            }
        }
        else {
            next = 1;
            posizioa = pantallaAldatu(posizioa, next);
        }
        break;
    case 3:
        if (PantallaNum == 2) {
            if(giltza!=1){
            giltza = 1;
            irudiaKendu(dialogo.id);
            dialogo.id = dialogoa_sortu(GILTZA_HARTU);
            }
        }
        else if (PantallaNum == 3) {
            if (erropa != 1) {
                erropa = 1;
                irudiaKendu(dialogo.id);
                dialogo.id = dialogoa_sortu(UNIFORMEA_HARTU);
            }
        }
        else if (PantallaNum == 5) {
            irudiaKendu(dialogo.id);
            dialogo.id = dialogoa_sortu(ARIKETA);
            char str1[50];
            int result1 = 0, result2 = 0;
            srand(time(NULL));
            int num1 = rand() % 10; // Número aleatorio entre 1 y 10
            int num2 = rand() % 10;
            int num3 = rand() % 10;
            int num4 = rand() % 10;
            while (num3==0) {
                num3 = rand() % 10;
           }
            sprintf(str1, "(%d + %d) / %d + %d = ", num1, num2, num3, num4);
            result1 = (num1 + num2) / num3 + num4;
            textuaIdatzi(448, 478, str1);
            pantailaBerriztu();
            while (ebentu != TECLA_RETURN)
            {
                ebentu = ebentuaJasoGertatuBada();
                switch (ebentu)
                {
                case TECLA_0:
                    result2 *= 10;
                    break;
                case TECLA_1:
                    result2 *= 10;
                    result2 += 1;
                    break;
                case TECLA_2:
                    result2 *= 10;
                    result2 += 2;
                    break;
                case TECLA_3:
                    result2 *= 10;
                    result2 += 3;
                    break;
                case TECLA_4:
                    result2 *= 10;
                    result2 += 4;
                    break;
                case TECLA_5:
                    result2 *= 10;
                    result2 += 5;
                    break;
                case TECLA_6:
                    result2 *= 10;
                    result2 += 6;
                    break;
                case TECLA_7:
                    result2 *= 10;
                    result2 += 7;
                    break;
                case TECLA_8:
                    result2 *= 10;
                    result2 += 8;
                    break;
                case TECLA_9:
                    result2 *= 10;
                    result2 += 9;
                    break;
                case 8:
                    result2 /= 10;
                }
                if (ebentu != 0) {
                    irudiaKendu(dialogo.id);
                    dialogo.id = dialogoa_sortu(ARIKETA);
                    sprintf(str1, "(%d + %d) / %d + %d = %d ", num1, num2, num3, num4, result2);
                    textuaIdatzi(448, 478, str1);
                    pantailaBerriztu();
                }
                if (mugitu!=0) {
                    irudiaKendu(dialogo.id);
                    
                }
            }
            if (result1 == result2) {
                irudiaKendu(dialogo.id);
                dialogo.id = dialogoa_sortu(ZUZENA);
                robo = 1;
            }
            else {
                irudiaKendu(dialogo.id);
                dialogo.id = dialogoa_sortu(ERROREA);
            }
        }
        break;
    case 4:
        next = 0;
        posizioa = pantallaAldatu(posizioa, next);
        break;
    }
    return posizioa;
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
    sprite_num = frameIndex + Direction;
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
int kolisioarenDetekzioa(int posX, int posY) {
    int Xmin, Xmax, Ymin, Ymax,bloqueXmin,bloqueXmax,bloqueYmin,bloqueYmax;
    //Jokalariaren posizioarekiko pertsonaiaren ertzak kalkulatu.
    //Perpektibarengatik pertsonaiaren buruak kolisioak pasatu ahal ditu (Horregatik +30).
    Xmin = posX + ANCHO / 2 - ANCHO_PERSONAJE / 2;
    Ymin = posY + ALTO / 2 - ALTO_PERSONAJE / 2;
    Xmax = Xmin + ANCHO_PERSONAJE;
    Ymax = Ymin + ALTO_PERSONAJE;
    Ymin += 30;
    //Pertsonaia pantailatik atera ez dela zihurtatu.
    if (Xmin > 0 && 
        Ymin > 0 &&
        Xmax < SCREEN_WIDTH && 
        Ymax < SCREEN_HEIGHT) {
            //matrizearen posizioak kalkulatu.
            bloqueXmin = Xmin / TAMANO_BLOQUE;
            bloqueYmin = Ymin / TAMANO_BLOQUE;
            bloqueXmax = Xmax / TAMANO_BLOQUE;
            bloqueYmax = Ymax / TAMANO_BLOQUE;
            //Kolisioa detektatu eta kolisiorik ez dagoen kasuan posizioa eguneratu.
            if (bloqueXmax < COLUMNAS && bloqueYmax < FILAS) {
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
    }
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
