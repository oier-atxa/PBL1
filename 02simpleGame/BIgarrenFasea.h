
#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

EGOERA jokatu2(EGOERA egoera);
int JOKOA_IrudiaSortu(POSIZIOA* posizioa, int id, int rnd);
POSIZIOA OztopoMugimendua(POSIZIOA posizioa, int Countdown);
int Talka(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3, int mota);
void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2);
POSIZIOA Mugimendua(POSIZIOA posizioa, int ebentu);
void SortuGasolina(POSIZIOA* posizioa1);
EGOERA dilema(EGOERA egoera);
void elementuakHasieratu(JOKO_ELEMENTUA* jokalaria, JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* fondo, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua);
void soinuaHasieratu(void);
void irudiGuztiakSortu(JOKO_ELEMENTUA* jokalaria, JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* fondo, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua, int random1, int random2);
void irudiGuztiakKendu(int id1, int id2, int id3, int id4, int id5, int id6);
void textuGuztiakIdatzi(char str[], char str2[], char str3[]);
void grafikoGuztiak(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA fondo, JOKO_ELEMENTUA gasolina, JOKO_ELEMENTUA erlojua, int random1, int random2, char str[], char str2[], char str3[]);
void posizioakEguneratu(JOKO_ELEMENTUA* jokalaria, JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua, int ebentu, int countdown);
void denboraKudeatu(time_t* startTime, int* countdown, int* CountdownReal, int denbora);
void bizitzakKudeatu(int* bizitzak, int* bizitzakop, int gasolinavar, POSIZIOA jokalariapos, POSIZIOA oztopoa1pos, POSIZIOA oztopoa2pos);
void gertaerakKudeatu(JOKO_ELEMENTUA* oztopoa1, JOKO_ELEMENTUA* oztopoa2, JOKO_ELEMENTUA* gasolina, JOKO_ELEMENTUA* erlojua, JOKO_ELEMENTUA* jokalaria, int* random1, int* random2, int* cocheround, int* countgas, int* CountdownReal, int* countdeath, int* denbora);
int dilemaSortu(char str[]);
#endif

