#ifndef _PRZECHOWYWANIE_H
#define _PRZECHOWYWANIE_H

typedef struct l {
		int **tablica_element;
		struct l * next;
} * lista;

lista zapisz_generacje(lista l, int **tablica, int r, int c);

void free_matrix(int **tablica, int r);

void free_lista(lista l, int r);

#endif
