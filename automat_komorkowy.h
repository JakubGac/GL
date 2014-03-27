#ifndef _AUOTMAT_KOMORKOWY_H
#define _AUOTMAT_KOMORKOWY_H

typedef struct l {
		int **tablica;
		struct l * next;
} *lista;

int automat_komorkowy(int **tablica, int r, int c,int ilosc_generacji,lista l);

int generacje(int **tablica,int r, int c);

int zapisz_generacje(lista l, int **tablica);

int kopiuj_generacje(int **tablica, int r, int c);

#endif 
