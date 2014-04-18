#include <stdlib.h>
#include "przechowywanie.h"

lista zapisz_generacje(lista l, int **tablica, int r, int c){

        int i,a,b;

        if( l == NULL){

                lista next = malloc(sizeof * next);

                next->tablica_element= (int**)malloc(sizeof(int*) * r);
                        for(i=0 ; i < r ; i++)
                                next->tablica_element[i] = (int*)malloc(sizeof(int) * c);

                for(a=0 ; a < r ; a++){
                        for(b=0 ; b < c ; b++)
                                next->tablica_element[a][b] = tablica[a][b];
                }

                next->next=NULL;
                return next;
        } else {
                l->next=zapisz_generacje(l->next,tablica,r,c);
                return l;
        }
}

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
