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
    //Aldagaiak deklaratu
    int ebentu = 0, bizitzak = 3, bizitzakop, countdown = 80, countdeath, denbora = 120, Framee = 0, random1 = 0, random2 = 1, gasolinavar = 10, countgas, cocheround = 0, CountdownReal = 120;
    char str[32], str2[32], str3[32];

    //Elementuak deklaratu
    JOKO_ELEMENTUA jokalaria, oztopoa1, oztopoa2, fondo, gasolina, erlojua;
    time_t startTime;
    //Denbora hasieratu
    time(&startTime);

    //Ausazko zenbakiak hasiertatu
    srand(time(NULL));

    soinuaHasieratu();

    do
    {
        elementuakHasieratu(&jokalaria, &oztopoa1, &oztopoa2, &fondo, &gasolina, &erlojua);

        //Kontagailuak hasieratu
        countdeath = CountdownReal;
        countgas = CountdownReal;

        irudiGuztiakSortu(&jokalaria, &oztopoa1, &oztopoa2, &fondo, &gasolina, &erlojua, random1, random2);

        //Pantailan agertuko den testua karaktere kate batean sartu
        sprintf(str2, "Bizitzak: %d ", bizitzak);

        do
        {
            Sleep(1);
            ebentu = ebentuaJasoGertatuBada();
            denboraKudeatu(&startTime, &countdown, &CountdownReal, denbora);

            //Pantailan agertuko diren testuak karaktere kateetan sartu
            sprintf(str, "Denbora: %d s", countdown);
            sprintf(str3, "Gasolina: %d s", gasolinavar);

            //Gasolina aldagaia kalkulatu
            gasolinavar = CountdownReal + 15 - countgas;

            //Fondoa hiru iterazioro aldatzeko
            Framee++;
            if (Framee % 3 == 1) {
                Frame = (Frame + 1) % 7;
            }
            gertaerakKudeatu(&oztopoa1, &oztopoa2, &gasolina, &erlojua, &jokalaria, &random1, &random2, &cocheround, &countgas, &CountdownReal, &countdeath, &denbora);
            bizitzakKudeatu(&bizitzak, &bizitzakop, gasolinavar, jokalaria.pos, oztopoa1.pos, oztopoa2.pos);
            posizioakEguneratu(&jokalaria, &oztopoa1, &oztopoa2, &gasolina, &erlojua, ebentu, countdown);
            grafikoGuztiak(jokalaria, oztopoa1, oztopoa2, fondo, gasolina, erlojua, random1, random2, str, str2, str3);

        } while (bizitzak == bizitzakop && countdown >= 0 && gasolinavar != 0);

        irudiGuztiakKendu(oztopoa1.id, oztopoa2.id, jokalaria.id, fondo.id, gasolina.id, erlojua.id);
        pantailaGarbitu();

        //Egoeraren kudeaketak
        if (bizitzak == 0)
            egoera = GALDU;
        else if (countdown <= 0)
            egoera = IRABAZI;

    } while (egoera == JOLASTEN2);
    //Fasea amaitu
    toggleMusic();
    audioTerminate();
    pantailaGarbitu();

    return egoera;
}

int JOKOA_IrudiaSortu(POSIZIOA* posizioa, int id, int rnd)
{
    char str[30];

    //Elementu bakoitzeko irudi desberdin bat izateko
    switch (id) {
    case 0:
        //Jokalariaren autoa kargatu
        id = irudiaKargatu(".\\img\\Kotxea0.bmp");
        break;
    case 1:
        //Ausaz oztopoen auto kolorea kargatzeko
        sprintf(str, ".\\img\\Kotxea%d.bmp", rnd);
        id = irudiaKargatu(str);
        break;
    case 2:
        //Gasolina bidoia kargatu
        id = irudiaKargatu(".\\img\\gasolina.bmp");
        break;
    case 3:
        //Arezko erlojua kargatu
        id = irudiaKargatu(".\\img\\Erlojua.bmp");
        break;
    case -1:
        //Fondoaren irudi desberdinak kargatzeko
        sprintf(str, ".\\img\\0%d.bmp", Frame);
        id = irudiaKargatu(str);
        break;
    default:
        break;
    }
    //Irudiak posizop berrira mugitu
    irudiaMugitu(id, posizioa->x, posizioa->y);
    return id;
}

POSIZIOA OztopoMugimendua(POSIZIOA posizioa, int Countdown)
{
    //Abiadura eta geratzen den denbora alderantziz proportzionalak izateko
    float ratio = 1 + (120 - Countdown) / 240.0;
    //Posizio berriaren kalkulua
    posizioa.x -= (5.0 * ratio);
    return posizioa;
}


void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2)
{
    int i;

    //0-5erako balioak dituen ausazko zenbakia sortu
    i = rand() % 6;

    //Konbinazio posibleetako bat aukeratu eta posizioak aldatu
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
    //Teklak detektatzerakoan posizioa aldatu
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

    //hitboxaren detekzioa
    if (posizioa.y < 92)
        posizioa.y = 92;

    else if (posizioa.y > 396)
        posizioa.y = 396;

    return posizioa;
}

int Talka(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3, int mota) {

    //Boolean
    int ret = 0;

    //Gasolina
    if (mota == 0) {
        //Gasolinarekin talka dektatu
        if (posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 42 && posizioa1.y + 82 > posizioa2.y && posizioa1.y < posizioa2.y + 61)
        {
            ret = 1;
        }
    }
    //Autoa
    if (mota == 1)
    {
        //Autoarekin talka dektatu
        if ((posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 192 && posizioa1.y + 82 > posizioa2.y && posizioa1.y < posizioa2.y + 82) || (posizioa1.x + 192 > posizioa3.x && posizioa1.x < posizioa3.x + 192 && posizioa1.y + 82 > posizioa3.y && posizioa1.y < posizioa3.y + 82))
        {
            ret++;
        }
    }
    //Erlojua
    if (mota = 2)
    {
        //Erlojuarekin talka dektatu
        if (posizioa1.x + 192 > posizioa2.x && posizioa1.x < posizioa2.x + 52 && posizioa1.y + 82 > posizioa2.y && posizioa1.y < posizioa2.y + 80)
        {
            ret = 1;
        }
    }
    return ret;
}
void SortuGasolina(POSIZIOA* posizioa1)
{
    int i;

    //0-2rako balioak dituen ausazko zenbakia sortu
    i = rand() % 3;

    //x ardatzeko posizioa aldatu
    posizioa1->x = 1024;

    //Konbinazio posibleetako bat aukeratu eta posizioa aldatu
    switch (i)
    {
    case 0:

        posizioa1->y = 96;
        break;

    case 1:

        posizioa1->y = 232;
        break;

    case 2:

        posizioa1->y = 384;

        break;
    }
}
EGOERA dilema(EGOERA egoera) {
    int fondoId, ebentu = 0;
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
    if (egoera==GALDU)
    {
        while (ebentu != TECLA_RETURN) 
        {
            ebentu = ebentuaJasoGertatuBada();
        }
    }


    while (egoera == IRABAZI) {
        ebentu = ebentuaJasoGertatuBada();
            switch (ebentu) {
            case TECLA_1:

                irudiaKendu(fondoId);
                fondoId = irudiaKargatu(".\\img\\te quedas el dinero.bmp");
                irudiaMugitu(fondoId, 0, 0);
                dilemaid = dilemaSortu(".\\img\\dilema_2_1.bmp");
                while (ebentu != TECLA_RETURN)
                {
                    ebentu = ebentuaJasoGertatuBada();
                }
                ebentu = 0;
                irudiaKendu(dilemaid);
                dilemaid = dilemaSortu(".\\img\\dilema_2_2.bmp");
                while (ebentu != TECLA_RETURN)
                {
                    ebentu = ebentuaJasoGertatuBada();
                }
                egoera = BUKATU;
                break;
            case TECLA_2:
                fondoId = irudiaKargatu(".\\img\\final bueno.bmp");
                irudiaMugitu(fondoId, 0, 0);
                irudiaKendu(dilemaid);
                dilemaid = dilemaSortu(".\\img\\dilema_1_1.bmp");
                
                irudiakMarraztu();
                pantailaBerriztu();
                while (ebentu != TECLA_RETURN)
                {
                    ebentu = ebentuaJasoGertatuBada();
                }
                ebentu = 0;
                irudiaKendu(dilemaid);
                dilemaid = dilemaSortu(".\\img\\dilema_1_2.bmp");
                while (ebentu != TECLA_RETURN)
                {
                    ebentu = ebentuaJasoGertatuBada();
                }
                egoera = BUKATU;
                break;
            default:
                break;
            }
        


    } ;

    irudiaKendu(fondoId);
}
int dilemaSortu(char str[]) {
    int dilemaid;
    dilemaid = irudiaKargatu(str);
    irudiaMugitu(dilemaid, 162, SCREEN_HEIGHT / 2 + 64);
    irudiakMarraztu();
    pantailaBerriztu();
    return dilemaid;
}
void elementuakHasieratu(JOKO_ELEMENTUA* jokalaria, JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* fondo, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua) {
    //Jokalariaren autoa eta fondoa izan ezik, elementuak eskutatuta hasieratu
    jokalaria->pos.x = 64;
    jokalaria->pos.y = 246;
    oztopoa1->pos.x = -300;
    oztopoa1->pos.y = 0;
    oztopoa2->pos.x = -300;
    oztopoa2->pos.y = 0;
    fondo->pos.x = 0;
    fondo->pos.y = 0;
    gasolina->pos.x = -192;
    gasolina->pos.y = 500;
    erlojua->pos.x = -192;
    erlojua->pos.y = 500;
}
void soinuaHasieratu(void) {
    //Audioa hasieratu
    audioInit();

    //Muska kargatu
    loadTheMusic(".\\sound\\accion.wav");

    //Musika hasi
    playMusic();
}
void irudiGuztiakSortu(JOKO_ELEMENTUA* jokalaria, JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* fondo, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua, int random1, int random2) {
    //Irudiak sortu
    fondo->id = JOKOA_IrudiaSortu(&(fondo->pos), -1, 0);
    oztopoa1->id = JOKOA_IrudiaSortu(&(oztopoa1->pos), 1, random1);
    oztopoa2->id = JOKOA_IrudiaSortu(&(oztopoa2->pos), 1, random2);
    jokalaria->id = JOKOA_IrudiaSortu(&(jokalaria->pos), 0, 0);
    gasolina->id = JOKOA_IrudiaSortu(&(gasolina->pos), 2, 0);
    erlojua->id = JOKOA_IrudiaSortu(&(erlojua->pos), 3, 0);
}
void irudiGuztiakKendu(int id1, int id2, int id3, int id4, int id5, int id6) {
    //Irudiak ezabatu
    irudiaKendu(id1);
    irudiaKendu(id2);
    irudiaKendu(id3);
    irudiaKendu(id4);
    irudiaKendu(id5);
    irudiaKendu(id6);
}
void textuGuztiakIdatzi(char str[], char str2[], char str3[]) {
    //Testuak idatzi
    textuaIdatzi(10, 10, str);
    textuaIdatzi(700, 10, str2);
    textuaIdatzi(360, 10, str3);
}
void grafikoGuztiak(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA fondo, JOKO_ELEMENTUA gasolina, JOKO_ELEMENTUA erlojua, int random1, int random2, char str[], char str2[], char str3[]) {
    //Grafikoen kudeaketa orokorra
    pantailaGarbitu();
    irudiGuztiakKendu(oztopoa1.id, oztopoa2.id, jokalaria.id, fondo.id, gasolina.id, erlojua.id);
    irudiGuztiakSortu(&jokalaria, &oztopoa1, &oztopoa2, &fondo, &gasolina, &erlojua, random1, random2);
    irudiakMarraztu();
    textuGuztiakIdatzi(str, str2, str3);
    pantailaBerriztu();
}

void posizioakEguneratu(JOKO_ELEMENTUA* jokalaria, JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua, int ebentu, int countdown)
{
    //Mugimendua kalkulatu eta posizioa aldatu
    jokalaria->pos = Mugimendua(jokalaria->pos, ebentu);
    oztopoa1->pos = OztopoMugimendua(oztopoa1->pos, countdown);
    oztopoa2->pos = OztopoMugimendua(oztopoa2->pos, countdown);
    gasolina->pos = OztopoMugimendua(gasolina->pos, countdown);
    erlojua->pos = OztopoMugimendua(erlojua->pos, countdown);

}
void denboraKudeatu(time_t* startTime, int* countdown, int* CountdownReal, int denbora) {
    //Denboraren kudeaketa orokorra, time.h liburutegia erabiliz
    time_t currentTime;

    //Denbora detektatu
    time(&currentTime);

    //Igarotako denbora kalkulatu
    int elapsedSeconds = difftime(currentTime, *startTime);

    //Geratzen den denbora kalkulatu
    *countdown = denbora - elapsedSeconds;
    *CountdownReal = 120 - elapsedSeconds;
}
void bizitzakKudeatu(int* bizitzak, int* bizitzakop, int gasolinavar, POSIZIOA jokalariapos, POSIZIOA oztopoa1pos, POSIZIOA oztopoa2pos) {
    //Bizitza kopurua gorde
    *bizitzakop = *bizitzak;

    //Autoekin talka detektatu
    *bizitzak = Talka(jokalariapos, oztopoa1pos, oztopoa2pos, 1);

    //Bizitza kopuru berria kalkulatu
    *bizitzak = *bizitzakop - *bizitzak;

    //Erregai gabe geratzea detektau
    if (gasolinavar == 0) {
        (*bizitzak)--;
    }
}

void gertaerakKudeatu(JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua, JOKO_ELEMENTUA* jokalaria, int* random1, int* random2, int* cocheround, int* countgas, int* CountdownReal, int* countdeath, int* denbora) {
    // Auto berri bat behar den detektatu
    if (oztopoa1->pos.x <= -192 && (*countdeath - 1) > *CountdownReal) {

        //Autoak sortu
        SortuKotxeak(&(oztopoa1->pos), &(oztopoa2->pos));

        //Autoen kolorea definitu
        *random1 = rand() % 3;
        *random2 = rand() % 3;

        //Autoen ronda kopurua kalkulatu
        (*cocheround)++;
    }
    // Gasolina bidoi berri bat behar den detektatu
    if (oztopoa1->pos.x >= 510 && oztopoa1->pos.x <= 520 && (*cocheround) % 2 == 1) {

        //Gasolina bidoia sortu
        SortuGasolina(&(gasolina->pos));
    }
    // Erloju berri bat behar den detektatu
    if (oztopoa1->pos.x >= 510 && oztopoa1->pos.x <= 520 && (*cocheround) % 2 == 0) {

        //Erlojua sortu
        SortuGasolina(&(erlojua->pos));
    }

    // Gasolina bidoiarekin talka detektatu
    if (Talka(jokalaria->pos, gasolina->pos, oztopoa2->pos, 0)) {

        //Gasolina bidoiarekin talka egindako momentua gorde
        *countgas = *CountdownReal;

        //Gasolina desagerrarazi
        gasolina->pos.x = -192;
        gasolina->pos.y = 500;        
    }
    // Verificar colisión con reloj
    if (Talka(jokalaria->pos, erlojua->pos, oztopoa2->pos, 2)) {

        //Denbora murriztu
        *denbora -= 5;

        //Erlojua desagerrarazi
        erlojua->pos.x = -192;
        erlojua->pos.y = 500;
    }
}