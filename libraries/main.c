#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "read.h"
#include "automat_komorkowy.h"
#include "wypisywanie.h"
#include "przechowywanie.h"
#include "obrazek.h"

/* The Game of Life */

char *napis = 		
		" \n Automat Komórkowy\n\n"
        	"\t - p - plik z początkową konfiguracją i wielkością siatki (np -p dane)\n"
        	"\t - N - liczba generacji do przeprowadzenia (np -N 100)\n"
        	"\t - f - wygenerowanie obrazów, ( np -f tak )\n"
        	"\t - z - zapisanie generacji do pliku. Podaj nazwe pliku (np -z wyniki)\n"
        	"\t - i - ustal częstotliwość zachowywanych generacji (np -i 2)\n\n";

int main ( int argc, char **argv){

	int opt;
	char *fname_in;	
	char *fname_out;
	int r,c;
	int co_ile_generacji = 0;
	int ilosc_generacji;
	int obraz = 0;  /* sprawdzic typ boolean */
	int plik = 0; 

	lista l = NULL;
	
	if(argc < 2 ){
		system("clear");
		printf("%s",napis);
		return -1;
	} else {
		while((opt = getopt (argc, argv, "p:N:f:z:i:")) != -1){
			switch(opt){
			case 'p' :
				fname_in = optarg;
				l = readFromFile(fname_in,l);
				r = ReadRows(optarg); 
				c = ReadColumns(optarg);
				break;
			case 'N' :
				ilosc_generacji = atoi(optarg);
				break;
			case 'f' :
				obraz = 1;
				break;
			case 'z' :
				plik = 1;
				fname_out = optarg;
				break;
			case 'i' :
				co_ile_generacji = atoi(optarg);
				break;
			default:
				printf("napis\b");
				return 0;
			}
		}	
	
	}

	automat_komorkowy(l->tablica_element,r,c,ilosc_generacji,l);
	
	if(plik)	/* zapisywanie generacji do pliku */
		zapisz_generacje_do_pliku(l,r,c,fname_out,co_ile_generacji);
	
	if(obraz)	/* generowanie obrazków */
			generuj_obrazek(l,r,co_ile_generacji);	

	free_lista(l,r);

	return EXIT_SUCCESS;
}
