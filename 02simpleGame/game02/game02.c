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

//frame index %num frames  0 1 2 3 0 1 2 
// Variables globales para animación
int numFrames = 6;  // Número total de imágenes en la secuencia
int frameIndex = 0; // Índice actual de la imagen en la secuencia
int PantallaNum = 0;
void sarreraMezuaIdatzi();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
JOKO_ELEMENTUA jokalaria, fondoa;
int pantallaoff = 0;
POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum);
POSIZIOA pantallaAldatu(POSIZIOA posizioa);
int MATRIZ_1[FILAS][COLUMNAS] = {
    //DONE!!
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}



};
int MATRIZ_2[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 2 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}



};
int MATRIZ_3[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}



};
int MATRIZ_4[FILAS][COLUMNAS] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1}



};

int mapa[FILAS][COLUMNAS];

int mapakopiatu(int PantallaNum) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            switch (PantallaNum) {
            case 1:
                mapa[i][j] = MATRIZ_1[i][j];
                printf("%d", mapa[i][j]);
                break;
            case 2:
                mapa[i][j] = MATRIZ_2[i][j];
                printf("%d", mapa[i][j]);
                break;
            case 3:
                mapa[i][j] = MATRIZ_3[i][j];
                printf("%d", mapa[i][j]);
                break;
            case 4:
                mapa[i][j] = MATRIZ_4[i][j];
                printf("%d", mapa[i][j]);
                break;
        }
            printf(", ");

        }
        printf("\n");
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
    POSIZIOA aux;

    jokalaria.pos.x = 64;
    jokalaria.pos.y = SCREEN_HEIGHT / 2;
    //Uint32 time01 = SDL_GetTicks(), time02;
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    mapakopiatu(PantallaNum);
    fondoa.id = JOKOA_fondoaIrudiaSortu();
    jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu);
    do {
        Sleep(50);
        pantailaGarbitu();
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
    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria) {
    EGOERA  ret = JOLASTEN;

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

    }
    fondoId = irudiaKargatu(FONDO_PATH);
    irudiaMugitu(fondoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    printf("aldatuta %s %d\n", FONDO_PATH, PantallaNum);
    return fondoId;

}
POSIZIOA pantallaAldatu(POSIZIOA posizioa) {


    irudiaKendu(fondoa.id);
    if (PantallaNum < 4)
    {
        PantallaNum++;
    }


    fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
    mapakopiatu(PantallaNum);
    jokalaria.id = irudiaKargatu(".\\img\\Sprite\\1.bmp");
    printf("X=%d y=%d \n", posizioa.x, posizioa.y);
    switch (PantallaNum) {
    case 1:
        posizioa.x = SCREEN_WIDTH/2;
        posizioa.y = 192;
        break;
    case 2:
        posizioa.x = SCREEN_WIDTH / 2;
        posizioa.y = SCREEN_HEIGHT - 64;
        break;
    case 3:
        posizioa.x = SCREEN_WIDTH - 64;
        posizioa.y = SCREEN_HEIGHT / 2;
        break;
    case 4:
        posizioa.x = SCREEN_WIDTH - 64;
        posizioa.y = SCREEN_HEIGHT / 2;
        break;

    }
    printf("X=%d y=%d \n", posizioa.x, posizioa.y);
    irudiaMugitu(jokalaria.id, posizioa.x, posizioa.y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return posizioa;

}


POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum) {
    int ebentu = 0;
    int NewPosX = posizioa.x, NewPosY = posizioa.y;
    NewPosX += ANCHO / 2;
    NewPosY -= ALTO / 2;
    int bloqueX = NewPosX / TAMANO_BLOQUE;
    int bloqueY = NewPosY / TAMANO_BLOQUE;
    NewPosX -= ANCHO / 2;
    NewPosY += ALTO / 2;
    if (mapa[bloqueY][bloqueX] == 2) {
        //Cambiar mapa
        printf("X=%d, Y=%d\n", bloqueX, bloqueY);
         posizioa= pantallaAldatu(posizioa);
    
    }
    else if (mapa[bloqueY][bloqueX] == 3) {
        PantallaNum -= 2;
        posizioa = pantallaAldatu(posizioa);
    }
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
        NewPosY -= (ALTO_PERSONAJE/2 + 5);
        break;
    case BEHERA:
        NewPosY += (ALTO_PERSONAJE/2 + 5);
        break;
    case ESKUMA:
        NewPosX += (ANCHO_PERSONAJE/2 + 5);
        break;
    case EZKERRA:
        NewPosX -= (ANCHO_PERSONAJE/2 + 5);
        break;
    default:
        break;
    }
    NewPosX += ANCHO / 2;
    NewPosY -= ALTO / 2;
    if (NewPosX >= 0 && NewPosY >= 0) {
        int bloqueX = NewPosX / TAMANO_BLOQUE;
        int bloqueY = NewPosY / TAMANO_BLOQUE;
        switch (mugitu) {
           case GORA:
            NewPosY = NewPosY + ALTO_PERSONAJE/2 + ALTO / 2;
            NewPosX -= ANCHO / 2;
            break;
           case BEHERA:
            NewPosY = NewPosY - ALTO_PERSONAJE/2 + ALTO / 2;
            NewPosX -= ANCHO / 2;
            break;
           case ESKUMA:
            NewPosX = NewPosX - ANCHO_PERSONAJE/2 - ANCHO / 2;
            NewPosY += ALTO / 2;
            break;
           case EZKERRA:
            NewPosX = NewPosX + ANCHO_PERSONAJE/2 - ANCHO / 2;
            NewPosY += ALTO / 2;
            break;
           default:
            break;
        }
        if (bloqueX < COLUMNAS && bloqueY < FILAS) {
            if (mapa[bloqueY][bloqueX] == 0 || mapa[bloqueY][bloqueX] == 2 || mapa[bloqueY][bloqueX] == 3)  {
                posizioa.x = NewPosX;
                posizioa.y = NewPosY;
                printf("X=%d, Y=%d\n", bloqueX, bloqueY);
            }

            else {
                printf("X=%d, Y=%d\n", bloqueX, bloqueY);
                printf("%d\n", mapa[bloqueY][bloqueX]);
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