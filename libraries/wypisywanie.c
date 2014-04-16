#include <stdio.h>
#include "automat_komorkowy.h"

int zapisz_generacje_do_pliku(lista l, int r, int c, char *fname, int co_ile){

	int i,j;

	FILE * out;

	char filename[128];

	sprintf(filename,"file/%s.txt",fname);

	out = fopen(filename, "w");

	l=l->next;

	while( l != NULL){
		for(i=0 ; i < r ; i++){
			for(j=0 ; j < c ; j++)
				fprintf(out," %d ",l->tablica_element[i][j]);
			fprintf(out,"\n");
		}
		fprintf(out,"\n");
	
		if(co_ile){ /* wypisuje wtedy tylko "co ktores" generacje */
			for(i=0 ; i < co_ile ; i++){
                        	if(l->next != NULL)
                                	l = l->next;
                       		else
                                	return -1;
               		}
	
		} else {
			l = l->next;
		}
	}

	return 0;
}
