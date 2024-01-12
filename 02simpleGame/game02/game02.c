
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


// Variables globales para animación
int numFrames = 6;  // Número total de imágenes en la secuencia
int frameIndex = 0; // Índice actual de la imagen en la secuencia
int PantallaNum = 1;
void sarreraMezuaIdatzi();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
JOKO_ELEMENTUA jokalaria, fondoa;
int pantallaoff = 0;

int mapa[FILAS][COLUMNAS] = {
    
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
   
};
void jokoaAurkeztu(void)
{
  int ebentu = 0;

  sarreraMezuaIdatzi();
  do
  {
    ebentu = ebentuaJasoGertatuBada();
  } while (ebentu != TECLA_RETURN);
  pantailaGarbitu();
  pantailaBerriztu();
}

void sarreraMezuaIdatzi()
{
  pantailaGarbitu();
  textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
  pantailaBerriztu();
}

EGOERA jokatu(void) 
{
  int mugitu = 0;
  int facing = BEHERA;
  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  POSIZIOA aux;
  jokalaria.pos.x = 160;
  jokalaria.pos.y = 160;
  //Uint32 time01 = SDL_GetTicks(), time02;
  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();

  fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
  jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu);
  do {
    Sleep(5);
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
        PantallaNum=Interaktuatu(jokalaria.pos, PantallaNum);
    default:
        mugitu = 0;
        
        break;
    }
   
    if (mugitu!=0) {
        irudiaKendu(jokalaria.id);
       jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu,facing, jokalaria.pos);
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
    char* FONDO_PATH= FONDO01;

    switch (PantallaNum)
    {
    case 1: 
        FONDO_PATH = FONDO01;
        break;
    case 2:
        FONDO_PATH = FONDO02;
        break;
    }
    fondoId = irudiaKargatu(FONDO_PATH);
    irudiaMugitu(fondoId, 0,0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoId;

}
int Interaktuatu(POSIZIOA posizioa, int pantallaNum) {
    int ebentu = 0;
    
    int bloqueX = posizioa.x / TAMANO_BLOQUE;
    int bloqueY = posizioa.y / TAMANO_BLOQUE;
    if (mapa[bloqueY][bloqueX] == 2) {
        //Cambiar mapa
        printf("X=%d, Y=%d\n", bloqueX, bloqueY);

         
                PantallaNum++;

                fondoa.id = JOKOA_fondoaIrudiaSortu(PantallaNum);
             
      
        return pantallaNum;

    }
    
}
int JOKOA_jokalariaIrudiaSortu(int mugitu,int facing, POSIZIOA posizioa) 
{
  int martzianoId = -1;
  char image_PATH[250] = JOKOA_PLAYER_IMAGE_DOWN_00;
  int Direction=33;
 

  if(facing != Direction){
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
        NewPosY = posizioa.y - 3;
        break;
    case BEHERA:
        NewPosY = posizioa.y + 3;
        break;
    case ESKUMA:
        NewPosX = posizioa.x + 3;
        break;
    case EZKERRA:
        NewPosX = posizioa.x - 3;
        break;
    default:
        break;
    }
    NewPosY += ALTO/ 2 + 10;
    NewPosX += ANCHO / 2;
    if (NewPosX >= 0 && NewPosY >= 0) {
        int bloqueX = NewPosX / TAMANO_BLOQUE;
        int bloqueY = NewPosY / TAMANO_BLOQUE;
        NewPosY -= ALTO/2 + 10;
        NewPosX -= ANCHO / 2;
        if (bloqueX < COLUMNAS && bloqueY < FILAS) {
            if (mapa[bloqueY][bloqueX] == 0 || mapa[bloqueY][bloqueX] == 2) {
                posizioa.x = NewPosX;
                posizioa.y = NewPosY;
                printf("X=%d, Y=%d\n", bloqueX, bloqueY);
            }
      
            else{
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
  id=BUKAERA_irudiaBistaratu();
  do 
  {
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA));
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

