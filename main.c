#include "read.h"
#include <stdio.h>

/* The Game of Life */

int main ( int argc, char **argv){

	Matrix * matrix = readFromFile(argv[1]);

	automat_komorkowy(matrix);	

	PrintMatrix(matrix);
		
	return 0;
}
