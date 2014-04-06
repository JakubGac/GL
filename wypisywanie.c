#include <stdio.h>
#include "automat_komorkowy.h"

void zapisz_generacje_do_pliku(lista l, int r, int c, char *fname){

	int i,j;

	FILE * out = fopen(fname,"w");

	while( l != NULL){
		for(i=0 ; i < r ; i++){
			for(j=0 ; j < c ; j++)
				fprintf(out," %d ",l->tablica_element[i][j]);
			fprintf(out,"\n");
		}
		fprintf(out,"\n");
		
		l = l->next;
	}
}

void zapisz_generacje_do_pliku_co_ile(lista l, int r, int c, char *fname,int co_ile){

        int i,j;

        FILE * out = fopen(fname,"w");

        while( l != NULL){
                for(i=0 ; i < r ; i++){
                        for(j=0 ; j < c ; j++)
                                fprintf(out," %d ",l->tablica_element[i][j]);
                        fprintf(out,"\n");
                }
                fprintf(out,"\n");

		for(i=0 ; i < co_ile ; i++)
                	l = l->next;
        }
}

