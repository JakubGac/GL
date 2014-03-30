#ifndef _AUOTMAT_KOMORKOWY_H
#define _AUOTMAT_KOMORKOWY_H

typedef struct l {
		int **tablica;
		struct l * next;
} *lista;

int automat_komorkowy(int **tablica, int r, int c,int ilosc_generacji,lista l);

int generacje(int **tablica,int r, int c, int tablica_pomocnicza);

lista zapisz_generacje(lista l, int **tablica);

int skopiuj(int **tablica, int **nowa_tablica, int r, int c);

void wypisz(int **tablica);

void wypisz_listee(lista l);

#endif 
