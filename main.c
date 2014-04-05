#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "automat_komorkowy.h"
#include "wypisywanie.h"
#include "przechowywanie.h"
#include "obrazek.h"

/* The Game of Life */

int main ( int argc, char **argv){
	
	if(argc < 2 ){
	
		wypisz_info();

	} else {
	
		lista l = NULL;

		l = readFromFile(argv[1],l);

		int r = ReadRows(argv[1]);

		int c = ReadColumns(argv[1]);
	
		int ilosc_generacji=300;

		automat_komorkowy(l->tablica_element,r,c,ilosc_generacji,l);

		zapisz_generacje_do_pliku(l,r,c,argv[2]);

		generuj_obrazek(l,r);	

	}

	return 0;
}
