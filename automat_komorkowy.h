#ifndef _AUOTMAT_KOMORKOWY_H
#define _AUOTMAT_KOMORKOWY_H

typedef struct l {
		int **tablica_element;
		struct l * next;
} *lista;

int  automat_komorkowy(int **tablica, int r, int c,int ilosc_generacji,lista l);

int generacje(int **tablica,int r, int c, int tablica_pomocnicza);

int alokacja_pamieci(int **tablica, int r, int c);

lista zapisz_generacje(lista l, int **tablica,int r, int c);

int skopiuj(int **tablica, int **nowa_tablica, int r, int c);

#endif 
