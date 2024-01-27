#ifndef GAME10_H
#define GAME10_H
#include "ourTypes.h"
void menua();
void jokoaAurkeztu(void);
EGOERA jokatu(void);
int EbentuakJaso(int ebentu);
POSIZIOA Interaktuatu(POSIZIOA posizioa, int pantallaNum, int mugitu);
int dialogoa_sortu(char* DIALOGO_PATH);
void irudiaKenduDialogo();
POSIZIOA pantailaAldatu(POSIZIOA posizioa, int next);
int JOKOA_fondoaIrudiaSortu(int PantallaNum);
void mapakopiatu(int PantallaNum);
POSIZIOA PertsonaiaKolokatu(POSIZIOA posizioa, int next);
int auzazkoEkuazioaSortu(int num[], char str1[]);
int ErantzunaIdatzi(int num[], char str1[]);
void ErantzunaZuzenadenKalkulatu(int erantzuna1, int erantzuna2);
int JOKOA_jokalariaIrudiaSortu(int mugitu, POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int mugitu);
int kolisioarenDetekzioa(int posX, int posY);
void JokalariarenErtzakKalkulatu(int posX, int posY, int* Xmin, int* Ymin, int* Xmax, int* Ymax);
int PantallarenBarruanDago(int Xmin, int Ymin, int Xmax, int Ymax);
void MatrizarenPosizioaKalkulatu(int Xmin, int Ymin, int Xmax, int Ymax, int* bloqueXmin, int* bloqueYmin, int* bloqueXmax, int* bloqueYmax);
int KolisioaDetektatu(int bloqueXmin, int bloqueYmin, int bloqueXmax, int bloqueYmax);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
void azalpena(int ebentu);
#endif