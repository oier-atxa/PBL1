
#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

EGOERA jokatu2(EGOERA egoera);
int JOKOA_IrudiaSortu(POSIZIOA posizioa, int type, int rnd);
int JOKOA_egoera2(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3);
POSIZIOA OztopoMugimendua(POSIZIOA posizioa, int Countdown);
void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2);
POSIZIOA Mugimendua(POSIZIOA posizioa, int ebentu);
int gasolinafun(POSIZIOA posizioa1, POSIZIOA posizioa2);
void SortuGasolina(POSIZIOA* posizioa1);

#endif