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


int numFrames = 6;  // Número total de imágenes en la secuencia
int frameIndex = 0; // Índice actual de la imagen en la secuencia
int PantallaNum = 0;
void sarreraMezuaIdatzi();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
JOKO_ELEMENTUA jokalaria, fondoa, dialogo;
int robo = 0;
int next = -1;
POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum);
POSIZIOA pantallaAldatu(POSIZIOA posizioa, int next);
int MATRIZ_1[FILAS][COLUMNAS] = {
    //DONE!!
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 2, 2, 3, 1, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}



};
int MATRIZ_2[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 0, 3, 3, 3, 3, 0, 1, 0, 0, 0, 1},
    {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1}



};
int MATRIZ_3[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}



};
int MATRIZ_4[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 1},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}



};
int MATRIZ_5[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1}



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

void sarreraMezuaIdatzi()
{
    pantailaGarbitu();
    textuaIdatzi(225, 200, "ANCHO");
    pantailaBerriztu();
}

EGOERA jokatu(void)
{
    int mugitu = 0;
    int facing = BEHERA;
    EGOERA  egoera = JOLASTEN;
    int ebentu = 0;
    dialogo.id = -1;
    POSIZIOA aux;

    jokalaria.pos.x = 64;
    jokalaria.pos.y = SCREEN_HEIGHT / 2;
    //Uint32 time01 = SDL_GetTicks(), time02;
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    mapakopiatu(PantallaNum);
    fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
    jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu,facing,jokalaria.pos);
    do {
        Sleep(5);
        arkatzKoloreaEzarri(0, 0, 0xFF);
        
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiakMarraztu();
        pantailaBerriztu();
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case TECLA_UP:
            mugitu = GORA;
            facing = GORA;
            break;
        case TECLA_DOWN:
            mugitu = BEHERA;
            facing = BEHERA;
            break;
        case TECLA_RIGHT:
            mugitu = ESKUMA;
            facing = ESKUMA;
            break;
        case TECLA_LEFT:
            mugitu = EZKERRA;
            facing = EZKERRA;
            break;
        case TECLA_SPACE:
            aux = Interaktuatu(jokalaria.pos, PantallaNum);
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
            jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu, facing, jokalaria.pos);
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
    if (PantallaNum == 6) {
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
        


    fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
    mapakopiatu(PantallaNum);
    jokalaria.id = irudiaKargatu(".\\img\\sprite_bmp\\1.bmp");
    
    switch (PantallaNum) {
    case 1:
        posizioa.x = SCREEN_WIDTH/2-64;
        posizioa.y = 192;
        break;
    case 2:
        if (next){
        posizioa.x = SCREEN_WIDTH / 2-64;
        posizioa.y = SCREEN_HEIGHT - 128;
        }
        else {
            posizioa.x = 128;
            posizioa.y = SCREEN_HEIGHT/2-64;
        }
        break;
    case 3:
        if (next) {
            posizioa.x = SCREEN_WIDTH - 128;
            posizioa.y = SCREEN_HEIGHT / 2-64;
        }
        else {
            posizioa.x = SCREEN_WIDTH / 2-64;
            posizioa.y = SCREEN_HEIGHT - 128;
        }
        break;
    case 4:
        if (next) {
            posizioa.x = SCREEN_WIDTH - 64;
            posizioa.y = SCREEN_HEIGHT / 2;
        }
        else{
            posizioa.x = 64;
            posizioa.y = SCREEN_HEIGHT / 2;
        }
        
        break;
    case 5:
        if (next) {
            posizioa.x = SCREEN_WIDTH /2 +128;
            posizioa.y = SCREEN_HEIGHT - 64;
        }
        else {
            posizioa.x = 64;
            posizioa.y = SCREEN_HEIGHT / 2;
        }
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
        dialogo.id = -1;  // Reinicia el identificador del diálogo
    }
}


POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum) {
    int ebentu = 0;
    int NewPosX = posizioa.x, NewPosY = posizioa.y;
    NewPosX += ANCHO / 2;
    NewPosY += ALTO / 2;
    int bloqueX = NewPosX / TAMANO_BLOQUE;
    int bloqueY = NewPosY / TAMANO_BLOQUE;
    NewPosX -= ANCHO / 2;
    NewPosY -= ALTO / 2;
    irudiaKenduDialogo();
    switch (mapa[bloqueY][bloqueX]) {
    case 2:
        if (PantallaNum == 1 && giltza!=1) {
            irudiaKenduDialogo();
            dialogo.id = dialogoa_sortu(ATEA_ITXITA);
        }
        else if (PantallaNum == 3 && erropa != 1) {
            irudiaKenduDialogo();
            dialogo.id = dialogoa_sortu(GILTZA_HARTU);
        }
        
        else if (PantallaNum == 5) {
            if (robo != 1) {
                irudiaKenduDialogo();
                dialogo.id = dialogoa_sortu(ATEA_ITXITA);
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
        if (PantallaNum == 1) {
            if(giltza!=1){
            giltza = 1;
            irudiaKenduDialogo();
            dialogo.id = dialogoa_sortu(GILTZA_HARTU);
            }
        }
        else if (PantallaNum == 2) {
            if (erropa != 1) {
                erropa = 1;
                irudiaKenduDialogo();
                dialogo.id = dialogoa_sortu(UNIFORMEA_HARTU);
            }
        }
        else if (PantallaNum == 4) {


            irudiaKenduDialogo();
            dialogo.id = dialogoa_sortu(NOTA);
            char str1[50];
            int result1 = 0, result2 = 0;
            int num1 = rand() % 10; // Número aleatorio entre 1 y 10
            int num2 = rand() % 10;
            int num3 = rand() % 10;
            int num4 = rand() % 10;
            sprintf(str1, "(%d + %d) / %d + %d", num1, num2, num3, num4);
            result1 = (num1 + num2) / num3 + num4;
            textuaIdatzi(64, 448, str1);
            pantailaBerriztu();
            while (ebentu != TECLA_RETURN)
            {
                ebentu = ebentuaJasoGertatuBada();
                switch (ebentu)
                {
                case TECLA_0:
                    result2 *= 10;
                    result2 += 0;
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

                }

            }


            if (result1 == result2) {
                irudiaKenduDialogo();
                dialogo.id = dialogoa_sortu(ZUZENA);
                robo = 1;
            }
            else {
                irudiaKenduDialogo();
                dialogo.id = dialogoa_sortu(ERROREA);
            }
        
            
        }
        break;
    case 4:
        next = 0;
        posizioa = pantallaAldatu(posizioa, next);
        break;
    }
    
    /*if (mapa[bloqueY][bloqueX] == 2) {
        //Cambiar mapa
        printf("X=%d, Y=%d\n", bloqueX, bloqueY);
         posizioa= pantallaAldatu(posizioa);
    
    }
    else if (mapa[bloqueY][bloqueX] == 3) {
        PantallaNum -= 2;
        posizioa = pantallaAldatu(posizioa);

    }
    */
    return posizioa;


}
int JOKOA_jokalariaIrudiaSortu(int mugitu, int facing, POSIZIOA posizioa)
{
    int martzianoId = -1;
    char image_PATH[250] = JOKOA_PLAYER_IMAGE_DOWN_00;
    int Direction = 33;


    if (facing != Direction) {
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
    }
    frameIndex = frameIndex + Direction;
    snprintf(image_PATH, sizeof(image_PATH), ".\\img\\sprite_bmp\\%d.bmp", frameIndex);
    if (martzianoId == -1) {
        martzianoId = irudiaKargatu(image_PATH);
    }
    frameIndex = frameIndex - Direction;

    irudiaMugitu(martzianoId, posizioa.x, posizioa.y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;

}


POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu) {
    int NewPosX = posizioa.x, NewPosY = posizioa.y;
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
    NewPosX += ANCHO / 2 - ANCHO_PERSONAJE/2;
    NewPosY += ALTO / 2 - ALTO_PERSONAJE/2;
    int NewPosXMax=NewPosX, NewPosYMax=NewPosY;
    NewPosXMax += ANCHO_PERSONAJE;
    NewPosYMax += ALTO_PERSONAJE;

    if (NewPosX > 0 && NewPosY > 0 &&
        NewPosXMax < SCREEN_WIDTH && NewPosYMax < SCREEN_HEIGHT
        ) {
        int bloqueX = NewPosX / TAMANO_BLOQUE;
        int bloqueY = NewPosY / TAMANO_BLOQUE;
        int bloqueXMax = NewPosXMax / TAMANO_BLOQUE;
        int bloqueYMax = NewPosYMax / TAMANO_BLOQUE;
        NewPosX -= ANCHO / 2 - ANCHO_PERSONAJE / 2;
        NewPosY -= ALTO / 2 - ALTO_PERSONAJE / 2;
       
        if (bloqueX < COLUMNAS && bloqueY < FILAS) {
            if (mapa[bloqueY][bloqueX] != 1 && mapa[bloqueYMax][bloqueXMax] != 1 &&
                mapa[bloqueYMax][bloqueX] != 1 && mapa[bloqueY][bloqueXMax] != 1)  {
                posizioa.x = NewPosX;
                posizioa.y = NewPosY;
               
            }
        }

    }

    return posizioa;
}


int  jokoAmaierakoa(EGOERA egoera)
{
    int ebentu = 0, id;
    int idAudioGame;

    loadTheMusic(BUKAERA_SOUND_1);
    if (egoera == IRABAZI) {
        idAudioGame = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame);
    }
    else {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
    }
    id = BUKAERA_irudiaBistaratu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
    audioTerminate();
    irudiaKendu(id);
    return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int BUKAERA_irudiaBistaratu() {
    int id = -1;
    id = irudiaKargatu(BUKAERA_IMAGE);
    irudiaMugitu(id, 200, 200);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
  return id;
}