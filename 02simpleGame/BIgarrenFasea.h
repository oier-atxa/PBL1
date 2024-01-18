
#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"


int JOKOA_IrudiaSortu(POSIZIOA posizioa, int type, char str[], char str2[]);
int JOKOA_egoera2(POSIZIOA posizioa1, POSIZIOA posizioa2, POSIZIOA posizioa3);
POSIZIOA OztopoMugimendua(POSIZIOA posizioa);
void SortuKotxeak(POSIZIOA* posizioa1, POSIZIOA* posizioa2);
POSIZIOA Mugimendua(POSIZIOA posizioa, int ebentu);
EGOERA jokatu2(EGOERA egoera);

#endif