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

int Frame = 0;

EGOERA jokatu2(EGOERA egoera)
{
    int ebentu = 0, bizitzak = 3, bizitzakop, countdown = 120, countdeath, denbora = 120, Framee = 0, elapsedSeconds, random1 = 0, random2 = 1, gasolinavar = 10, countgas, cocheround = 0, CountdownReal = 120;
    char str[16], str2[16], str3[16];
    JOKO_ELEMENTUA jokalaria, oztopoa1, oztopoa2, fondo, gasolina, erlojua;
    POSIZIOA aux, aux2, aux3, aux4, aux5;
    time_t startTime, currentTime;
    time(&startTime);

    srand(time(NULL));
    audioInit();

    playMusic(loadTheMusic(".\\sound\\accion.wav"));

    do
    {
        jokalaria.pos.x = 64;
        jokalaria.pos.y = 246;
        oztopoa1.pos.x = -300;
        oztopoa1.pos.y = 0;
        oztopoa2.pos.x = -300;
        oztopoa2.pos.y = 0;
        fondo.pos.x = 0;
        fondo.pos.y = 0;
        gasolina.pos.x = -192;
        gasolina.pos.y = 500;
        erlojua.pos.x = -192;
        erlojua.pos.y = 500;

        countdeath = CountdownReal;
        countgas = CountdownReal;




        sprintf(str2, "Bizitzak: %d ", bizitzak);

        oztopoa1.id = JOKOA_IrudiaSortu(oztopoa1.pos, 1, random1);
        oztopoa2.id = JOKOA_IrudiaSortu(oztopoa2.pos, 1, random2);
        jokalaria.id = JOKOA_IrudiaSortu(jokalaria.pos, 0, 0);
        fondo.id = JOKOA_IrudiaSortu(fondo.pos, -1, 0);
        gasolina.id = JOKOA_IrudiaSortu(gasolina.pos, 2, 0);
        erlojua.id = JOKOA_IrudiaSortu(erlojua.pos, 3, 0);
        do
        {
            gasolinavar = CountdownReal + 15 - countgas;
            Framee++;
            if (Framee % 3 == 1) {
                Frame = (Frame + 1) % 7;
            }
            sprintf(str, "Tiempo: %d s", countdown);
            sprintf(str3, "Gasolina: %d s", gasolinavar);
            bizitzakop = bizitzak;
            ebentu = ebentuaJasoGertatuBada();
            Sleep(4);

            if (oztopoa1.pos.x <= -192 && countdeath - 1 > CountdownReal) {
                SortuKotxeak(&oztopoa1.pos, &oztopoa2.pos);
                random1 = rand() % 3;
                random2 = rand() % 3;
                cocheround++;
            }

            else if (oztopoa1.pos.x >= 510 && oztopoa1.pos.x <= 520 && cocheround % 2 == 1)
                SortuGasolina(&gasolina.pos);

            else if (oztopoa1.pos.x >= 510 && oztopoa1.pos.x <= 520 && cocheround % 2 == 0)
                SortuGasolina(&erlojua.pos);

            time(&currentTime);
            elapsedSeconds = difftime(currentTime, startTime);
            countdown = denbora - elapsedSeconds;
            CountdownReal = 120 - elapsedSeconds;

            aux = Mugimendua(jokalaria.pos, ebentu);
            aux2 = OztopoMugimendua(oztopoa1.pos, countdown);
            aux3 = OztopoMugimendua(oztopoa2.pos, countdown);
            aux4 = OztopoMugimendua(gasolina.pos, countdown);
            aux5 = OztopoMugimendua(erlojua.pos, countdown);

            jokalaria.pos = aux;
            oztopoa1.pos = aux2;
            oztopoa2.pos = aux3;
            gasolina.pos = aux4;
            erlojua.pos = aux5;

            pantailaGarbitu();
            irudiaKendu(oztopoa1.id);
            irudiaKendu(oztopoa2.id);
            irudiaKendu(jokalaria.id);
            irudiaKendu(fondo.id);
            irudiaKendu(gasolina.id);
            irudiaKendu(erlojua.id);

            fondo.id = JOKOA_IrudiaSortu(fondo.pos, -1, 0);
            oztopoa1.id = JOKOA_IrudiaSortu(oztopoa1.pos, 1, random1);
            oztopoa2.id = JOKOA_IrudiaSortu(oztopoa2.pos, 1, random2);
            jokalaria.id = JOKOA_IrudiaSortu(jokalaria.pos, 0, 0);
            gasolina.id = JOKOA_IrudiaSortu(gasolina.pos, 2, 0);
            erlojua.id = JOKOA_IrudiaSortu(erlojua.pos, 3, 0);
            irudiakMarraztu();
            textuaIdatzi(10, 10, str);
            textuaIdatzi(900, 10, str2);
            textuaIdatzi(460, 10, str3);
            pantailaBerriztu();

            bizitzak = JOKOA_egoera2(jokalaria.pos, oztopoa1.pos, oztopoa2.pos);
            if (gasolinafun(jokalaria.pos, gasolina.pos))
            {
                countgas = CountdownReal;
                gasolina.pos.x = -192;
                gasolina.pos.y = 500;
                playSound(loadSound(".\\sound\\0124.wav"));
            }
            else if (erlojufun(jokalaria.pos, erlojua.pos))
            {
                denbora -= 5;
                erlojua.pos.x = -192;
                erlojua.pos.y = 500;
                playSound(loadSound(".\\sound\\0124.wav"));
            }
            bizitzak += bizitzakop;
            if (gasolinavar == 0) {
                bizitzak--;
            }

        } while (bizitzak == bizitzakop && countdown >= 0 && gasolinavar != 0);

        printf("Bizitzak %d\n", bizitzak);
        irudiaKendu(jokalaria.id);
        irudiaKendu(oztopoa1.id);
        irudiaKendu(oztopoa2.id);
        irudiaKendu(fondo.id);
        irudiaKendu(erlojua.id);

        pantailaGarbitu();
        pantailaBerriztu();

        if (bizitzak == 0)
            egoera = GALDU;

        else if (countdown <= 0)
            egoera = IRABAZI;

    } while (egoera == JOLASTEN2);
    egoera = dilema(egoera);
    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();

    return egoera;
}

int JOKOA_IrudiaSortu(POSIZIOA posizioa, int id, int rnd)
{
    char str[30];

    switch (id) {
    case 0:
        id = irudiaKargatu(".\\img\\Kotxea0.bmp");
        break;
    case 1:
        sprintf(str, ".\\img\\Kotxea%d.bmp", rnd);
        id = irudiaKargatu(str);
        break;
    case 2:
        id = irudiaKargatu(".\\img\\gasolina.bmp");
        break;
    case 3:
        id = irudiaKargatu(".\\img\\Erlojua.bmp");
        break;
    case -1:
        sprintf(str, ".\\img\\0%d.bmp", Frame);
        id = irudiaKargatu(str);
        break;
    default:
        break;
    }
    irudiaMugitu(id, posizioa.x, posizioa.y);
    return id;
}

POSIZIOA OztopoMugimendua(POSIZIOA posizioa, int Countdown)
{
    float ratio = 1 + (120 - Countdown) / 240.0;
    posizioa.x -= (5.0 * ratio);
    return posizioa;
}

int JOKOA_egoera2(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3)
{
    int ret = 0;
    if ((posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 192 && posizioa1.y + 82 > posizioa2.y && posizioa1.y < posizioa2.y + 82) || (posizioa1.x + 192 > posizioa3.x && posizioa1.x < posizioa3.x + 192 && posizioa1.y + 82 > posizioa3.y && posizioa1.y < posizioa3.y + 82))
    {
        ret--;
    }
    return ret;
}

void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2)
{
    int i;

    i = rand() % 6;
    switch (i)
    {
    case 0:

        posizioa1->x = 1024;
        posizioa1->y = 92;
        posizioa2->x = 1024;
        posizioa2->y = 390;
        break;

    case 1:

        posizioa1->x = 1024;
        posizioa1->y = 92;
        posizioa2->x = 1024;
        posizioa2->y = 246;
        break;

    case 2:

        posizioa1->x = 1024;
        posizioa1->y = 246;
        posizioa2->x = 1024;
        posizioa2->y = 390;
        break;

    case 3:

        posizioa1->x = 1024;
        posizioa1->y = 92;
        break;
    case 4:

        posizioa1->x = 1024;
        posizioa1->y = 246;
        break;
    case 5:

        posizioa1->x = 1024;
        posizioa1->y = 390;
        break;
    }
}


POSIZIOA Mugimendua(POSIZIOA posizioa, int ebentu)
{
    if (posizioa.y >= 86 && posizioa.y <= 396)
    {
        switch (ebentu)
        {
        case TECLA_UP:
            posizioa.y -= 10;
            break;
        case TECLA_DOWN:
            posizioa.y += 10;
            break;
        default:
            break;
        }
    }
    if (posizioa.y < 92)
        posizioa.y = 92;

    if (posizioa.y > 396)
        posizioa.y = 396;

    return posizioa;
}

int gasolinafun(POSIZIOA posizioa1, POSIZIOA posizioa2) {
    int ret = 0;

    if (posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 42 && posizioa1.y + 82 > posizioa2.y && posizioa1.y < posizioa2.y + 61)
    {
        ret = 1;
    }
    return ret;
}

int erlojufun(POSIZIOA posizioa1, POSIZIOA posizioa2) {
    int ret = 0;

    if (posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 52 && posizioa1.y + 82 > posizioa2.y && posizioa1.y < posizioa2.y + 80)
    {
        ret = 1;
    }
    return ret;
}
void SortuGasolina(POSIZIOA* posizioa1)
{
    int i;

    i = rand() % 3;
    posizioa1->x = 1024;
    switch (i)
    {
    case 0:

        posizioa1->y = 80;
        break;

    case 1:

        posizioa1->y = 224;
        break;

    case 2:

        posizioa1->y = 384;

        break;
    }
}
EGOERA dilema(EGOERA egoera) {
    int fondoId, ebentu, fondoActualId;
    int dilemaid;
    if (egoera == GALDU) {
        fondoId = irudiaKargatu(".\\img\\moricion.bmp");
    }
    else {
        fondoId = irudiaKargatu(".\\img\\dilema.bmp");
        dilemaid = irudiaKargatu(".\\img\\erabakia.bmp");
        irudiaMugitu(dilemaid, 162, SCREEN_HEIGHT / 2 + 64);
    }
    
    irudiaMugitu(fondoId, 0, 0);
  
    irudiakMarraztu();
    pantailaBerriztu();
    SDL_Delay(2000);
    fondoActualId = fondoId;
    int teclaPresionada = 0;

    do {
        ebentu = ebentuaJasoGertatuBada();

        if (egoera == IRABAZI) {
            switch (ebentu) {
            case TECLA_1:
                if (!teclaPresionada) {
                    irudiaKendu(fondoActualId);
                    fondoActualId = irudiaKargatu(".\\img\\te quedas el dinero.bmp");
                    irudiaMugitu(fondoActualId, 0, 0);
                    dilemaid = irudiaKargatu(".\\img\\dilema_1_1.bmp");
                    irudiaMugitu(dilemaid, 162, SCREEN_HEIGHT / 2 + 64);
                    irudiakMarraztu();
                    pantailaBerriztu();
                    teclaPresionada = 1;
                    while (ebentu != TECLA_RETURN) {
                        {
                            ebentu = ebentuaJasoGertatuBada();
                        }
                    }
                    dilemaid = irudiaKargatu(".\\img\\dilema_1_2.bmp");
                    irudiaMugitu(dilemaid, 162, SCREEN_HEIGHT / 2 + 64);
                }
                break;
            case TECLA_2:
                if (!teclaPresionada) {
                    fondoActualId = irudiaKargatu(".\\img\\final bueno.bmp");
                    irudiaMugitu(fondoActualId, 0, 0);
                    dilemaid = irudiaKargatu(".\\img\\dilema_2_1.bmp");
                    irudiaMugitu(dilemaid, 162, SCREEN_HEIGHT / 2 + 64);
                    irudiaMugitu(fondoActualId, 0, 0);
                    irudiakMarraztu();
                    pantailaBerriztu();
                    teclaPresionada = 1;
                    while (ebentu != TECLA_RETURN) {
                        {
                            ebentu = ebentuaJasoGertatuBada();
                        }
                    }
                    dilemaid = irudiaKargatu(".\\img\\dilema_2_2.bmp");
                    irudiaMugitu(dilemaid, 162, SCREEN_HEIGHT / 2 + 64);
                }
                break;
            default:
                break;
            }
             irudiakMarraztu();
                    pantailaBerriztu();
        }

       
    } while (egoera == IRABAZI);

    irudiaKendu(fondoActualId);
}