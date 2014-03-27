#include "read.h"
#include <stdio.h>
#include "automat_komorkowy.h"

/* The Game of Life */

int main ( int argc, char **argv){
	
	int **matrix = readFromFile(argv[1]);

	int r = ReadRows(argv[1]);

	int c = ReadColumns(argv[1]);

	lista l = NULL;
	
	int ilosc_generacji=3;

	automat_komorkowy(matrix,r,c,ilosc_generacji,l);

	return 0;
}
