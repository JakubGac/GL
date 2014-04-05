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

void wypisz_info(){

	printf("\n Automat Komórkowy\n\n");

	printf("\t - p - plik z początkową konfiguracją i wielkością siatki \n");
	
	printf("\t - N - liczba generacji do przeprowadzenia \n");
	
	printf("\t - f - wygenerowanie obrazów \n");

	printf("\t - z - zapisanie generacji do pliku. Podaj nazwe pliku \n");

	printf("\t - i - ustal częstotliwość zachowywanych generacji \n\n");	

}
