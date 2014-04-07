#include <stdlib.h>
#include "przechowywanie.h"

void free_matrix(int **tablica,int r){

	int i;

	for(i=0 ; i < r ; i++)
		free(tablica[i]);
	
	free(tablica);
}

void free_lista(lista l, int r){

	while( l != NULL){
		free_matrix(l->tablica_element,r);
		l=l->next;
	}
}
