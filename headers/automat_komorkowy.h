#ifndef _AUOTMAT_KOMORKOWY_H
#define _AUOTMAT_KOMORKOWY_H

#include "przechowywanie.h"

void generacje(int **tablica,int r, int c, int tablica_pomocnicza);

int automat_komorkowy(int **tablica,int r, int c,int ilosc_generacji,lista l);

#endif 
