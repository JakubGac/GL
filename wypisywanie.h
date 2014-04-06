#ifndef _WYPISYWANIE_H
#define _WYPISYWANIE_H

#include "przechowywanie.h"

void zapisz_generacje_do_pliku(lista l, int r, int c, char *fname);

void zapisz_generacje_do_pliku_co_ile(lista l, int r, int c, char *fname,int co_ile);

void wypisz_info();

#endif
