#include "BigarrenFasea.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "konstanteak.h"
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
int numFrame = 4;
int frame = 0;
int JOKOA_IrudiaSortu(POSIZIOA posizioa, int type, char str[], char str2[]);
int JOKOA_egoera2(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3);
POSIZIOA OztopoMugimendua(POSIZIOA posizioa);
void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2);
POSIZIOA Mugimendua(POSIZIOA posizioa, int ebentu);


EGOERA jokatu2(EGOERA egoera)
{
    int ebentu = 0, bizitzak = 3, bizitzakop, countdown = 120;;
    char str[16], str2[16];
    JOKO_ELEMENTUA jokalaria, oztopoa1, oztopoa2, fondo;
    POSIZIOA aux, aux2, aux3;
    time_t startTime, currentTime;
    time(&startTime);
    do
    {
        jokalaria.pos.x = 64;
        jokalaria.pos.y = 256;
        oztopoa1.pos.x = -192;
        oztopoa1.pos.y = 0;
        oztopoa2.pos.x = -192;
        oztopoa2.pos.y = 0;
        fondo.pos.x = 0;
        fondo.pos.y = 0;

        audioInit();
        loadTheMusic(".\\sound\\Different");
        playMusic();
        sprintf(str, "Tiempo: %d s", countdown);
        sprintf(str2, "Bizitzak: %d ", bizitzak);
        oztopoa1.id = JOKOA_IrudiaSortu(oztopoa1.pos, 1, str, str2);
        oztopoa2.id = JOKOA_IrudiaSortu(oztopoa2.pos, 1, str, str2);
        jokalaria.id = JOKOA_IrudiaSortu(jokalaria.pos, 0, str, str2);
        fondo.id = JOKOA_IrudiaSortu(fondo.pos, -1, str, str2);
        do
        {
            sprintf(str, "Tiempo: %d s", countdown);
            bizitzakop = bizitzak;
            ebentu = ebentuaJasoGertatuBada();
            Sleep(2);

            if (oztopoa1.pos.x <= -192)
            {
                SortuKotxeak(&oztopoa1.pos, &oztopoa2.pos);
            }
            time(&currentTime);
            int elapsedSeconds = difftime(currentTime, startTime);
            countdown = 120 - elapsedSeconds;
            irudiaKendu(oztopoa1.id);
            oztopoa1.id = JOKOA_IrudiaSortu(oztopoa1.pos, 1, str, str2);
            aux2 = OztopoMugimendua(oztopoa1.pos);
            oztopoa1.pos.x = aux2.x;
            oztopoa1.pos.y = aux2.y;

            irudiaKendu(oztopoa2.id);
            oztopoa2.id = JOKOA_IrudiaSortu(oztopoa2.pos, 1, str, str2);
            aux3 = OztopoMugimendua(oztopoa2.pos);
            oztopoa2.pos.x = aux3.x;
            oztopoa2.pos.y = aux3.y;

            irudiaKendu(jokalaria.id);
            jokalaria.id = JOKOA_IrudiaSortu(jokalaria.pos, 0, str, str2);
            aux = Mugimendua(jokalaria.pos, ebentu);
            jokalaria.pos.x = aux.x;
            jokalaria.pos.y = aux.y;



            bizitzak = JOKOA_egoera2(jokalaria.pos, oztopoa1.pos, oztopoa2.pos);
            bizitzak += bizitzakop;
        } while (bizitzak == bizitzakop && countdown != 0);
        printf("Bizitzak %d\n", bizitzak);
        irudiaKendu(jokalaria.id);
        irudiaKendu(oztopoa1.id);
        irudiaKendu(oztopoa2.id);
        irudiaKendu(fondo.id);

        if (bizitzak == 0) {
            egoera = GALDU;
        }
        if (countdown == 0) {
            egoera = IRABAZI;
        }
    } while (egoera == JOLASTEN2);

    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();

    return egoera;
}

int JOKOA_IrudiaSortu(POSIZIOA posizioa, int type, char str[], char str2[])
{
    int id = -1;
    
    switch (type) {
    case 0:
        id = irudiaKargatu(".\\img\\prota_fase2.bmp");
        break;
    case 1:
        id = irudiaKargatu(".\\img\\furgo.bmp");
        break;
    case -1:
 
        id = irudiaKargatu(".\\img\\fondo_care00.bmp");
        break;
    default:
        break;
    }

    pantailaGarbitu();
    irudiaMugitu(id, posizioa.x, posizioa.y);
    irudiakMarraztu();
    textuaIdatzi(10, 10, str);
    textuaIdatzi(900, 10, str2);
    pantailaBerriztu();
    return id;
}

POSIZIOA OztopoMugimendua(POSIZIOA posizioa)
{
    posizioa.x -= 3;
    return posizioa;
}

int JOKOA_egoera2(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3)
{
    int ret = 0;
    if ((posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 192 && posizioa1.y + 99 > posizioa2.y && posizioa1.y < posizioa2.y + 99) || (posizioa1.x + 192 > posizioa3.x && posizioa1.x < posizioa3.x + 192 && posizioa1.y + 99 > posizioa3.y && posizioa1.y < posizioa3.y + 99))
    {
        ret--;
    }
    return ret;
}

void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2)
{
    int i;


    i = rand() % 3;
    if (i == 1)
    {
        posizioa1->x = 1024;
        posizioa1->y = 80;
        posizioa2->x = 1024;
        posizioa2->y = 320 + 64;
    }
    else if (i == 0)
    {
        posizioa1->x = 1024;
        posizioa1->y = 80;
        posizioa2->x = 1024;
        posizioa2->y = 160 + 64;
    }
    else
    {
        posizioa1->x = 1024;
        posizioa1->y = 160 + 64;
        posizioa2->x = 1024;
        posizioa2->y = 320 + 64;
    }
}


POSIZIOA Mugimendua(POSIZIOA posizioa, int ebentu)
{
    if (posizioa.y >= 64 && posizioa.y <= 384)
    {
        switch (ebentu)
        {
        case TECLA_UP:
            posizioa.y -= 6;
            break;
        case TECLA_DOWN:
            posizioa.y += 6;
            break;
        default:
            break;
        }
    }
    if (posizioa.y < 64)
    {
        posizioa.y = 64;
    }
    if (posizioa.y > 384)
    {
        posizioa.y = 384;
    }
    return posizioa;
}