#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "konstanteak.h"
#include <stdio.h>
#include <windows.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define JOKOA_SOUND ".\\sound\\132TRANCE_02.wav"
#define JOKOA_PLAYER_IMAGE_UP ".\\img\\sprite_up.bmp"
#define JOKOA_PLAYER_IMAGE_DOWN ".\\img\\sprite_down.bmp"
#define JOKOA_PLAYER_IMAGE_RIGHT ".\\img\\sprite_right.bmp"
#define JOKOA_PLAYER_IMAGE_LEFT ".\\img\\sprite_left.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\terminator.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"

void sarreraMezuaIdatzi();
int JOKOA_jokalariaIrudiaSortu(int mugitu);
void JOKOA_lerroHBatMargotu(int x, int y, int x1, int y1);
void JOKOA_lerroVBatMargotu(int x, int y, int x1, int y1);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();

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
  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA jokalaria;
  POSIZIOA aux;
  jokalaria.pos.x = 200;
  jokalaria.pos.y = 200;
  //Uint32 time01 = SDL_GetTicks(), time02;
  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();
  jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu);
  do {
    Sleep(2);
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
    default:
        mugitu = 0;
        break;
    }
    if (mugitu!=0) {
        irudiaKendu(jokalaria.id);
       jokalaria.id = JOKOA_jokalariaIrudiaSortu(mugitu);
      aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos, mugitu);
      jokalaria.pos.x = aux.x;
      jokalaria.pos.y = aux.y;
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

int JOKOA_jokalariaIrudiaSortu(int mugitu) 
{
  int martzianoId = -1;
  char* image_PATH=JOKOA_PLAYER_IMAGE_DOWN;
  switch (mugitu)
  {
  case GORA:
      image_PATH = JOKOA_PLAYER_IMAGE_UP;
      break;
  case BEHERA:
      image_PATH = JOKOA_PLAYER_IMAGE_DOWN;
      break;
  case EZKERRA:
      image_PATH = JOKOA_PLAYER_IMAGE_LEFT;
      break;
  case ESKUMA:
      image_PATH = JOKOA_PLAYER_IMAGE_RIGHT;
      break;
  default:
      break;
  }
  if (martzianoId == -1) {
      martzianoId = irudiaKargatu(image_PATH);
  }
      
  
  irudiaMugitu(martzianoId, 10, 239);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return martzianoId;

}


POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu) {
    
    switch (mugitu)
    {
    case GORA:
        posizioa.y -= 5;
        break;
    case BEHERA:
        posizioa.y += 5;
        break;
    case ESKUMA:
        posizioa.x += 5;
        break;
    case EZKERRA:
        posizioa.x -= 5;
        break;
    default:
        break;
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

