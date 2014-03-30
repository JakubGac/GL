#include <stdio.h>
#include "read.h"
#include "automat_komorkowy.h"
#include "wypisywanie.h"

/* The Game of Life */

int main ( int argc, char **argv){
	
	int **matrix = readFromFile(argv[1]);

	int r = ReadRows(argv[1]);

	int c = ReadColumns(argv[1]);

	lista l = NULL;
	
	int ilosc_generacji=3;

	l = zapisz_generacje(l,matrix);

	wypisz_listee(l);
	
	automat_komorkowy(matrix,r,c,ilosc_generacji,l);

	printf("po\n");

	wypisz_listee(l);

	int i,j;

/*	while(l != NULL){
		for(i=0 ; i < r ; i++){
			for(j=0 ; j < c ; j++)
				printf(" %d ",l->tablica[i][j]);
			printf("\n");	
		}
		printf("\n");
		l=l->next;
	}
*/
	return 0;
}
