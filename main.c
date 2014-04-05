#include <stdio.h>
#include "read.h"
#include "automat_komorkowy.h"
#include "wypisywanie.h"

/* The Game of Life */

int main ( int argc, char **argv){
	
	if(argc < 2 ){
	
		wypisz_info();

	} else {

		lista l = NULL;

		readFromFile(argv[1]);

		int r = ReadRows(argv[1]);

		int c = ReadColumns(argv[1]);
	
		int ilosc_generacji=20;
	
		automat_komorkowy(matrix,r,c,ilosc_generacji,l);

		zapisz_generacje_do_pliku(l,r,c,argv[2]);

		generuj_obrazek(l,r);	

	}

	return 0;
}
