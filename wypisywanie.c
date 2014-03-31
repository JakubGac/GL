#include <stdio.h>
#include "automat_komorkowy.h"

void zapisz_generacje_do_pliku(lista l, FILE * out, int r, int c){

	int i,j;

	while( l != NULL){
		
		for(i=0 ; i < r ; i++){
			for(j=0 ; j < c ; j++)
				fprintf(out," %d ",l->tablica[i][j]);
			fprintf(out,"\n");
		}
	
		fprintf(out,"\n");

		l = l->next;
	}
}
