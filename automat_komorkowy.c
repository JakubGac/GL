#include <stdio.h>
#include <stdlib.h>
#include "automat_komorkowy.h"
#include "zasada_zywa.h"
#include "zasada_martwa.h"
#include "read.h"

int automat_komorkowy(int **tablica, int r, int c,int ilosc_generacji,lista l){

	int i;
	
	int **nowa_generacja;

	zapisz_generacje(l,tablica);

	for(i=0 ; i < ilosc_generacji ; i++){
		PrintMatrix(tablica,r,c);
		nowa_generacja = kopiuj_generacje(tablica,r,c);
		nowa_generacja = generacja(tablica,r,c);
		tablica = kopiuj_generacje(nowa_generacja,r,c);
		zapisz_generacje(l,tablica);
	}

	return 0;
}

int generacja(int **tablica, int r, int c){

	int i,j;

	for(i = 1 ; i  < r-1 ; i++){
		for(j = 1 ; j < c-1 ; j++){
			if ( tablica[i][j] == 1){	/* komórka żywa */
				zasada_zywa(tablica,i,j,&(tablica[i][j]));
			} else { 			/*komórka martwa */
				zasada_martwa(tablica,i,j,&(tablica[i][j]));
			}                        
		}
	}

	return tablica;
}

int zapisz_generacje(lista l, int **tablica){
	
	if( l == NULL){
		lista next = malloc(sizeof * next);
		next->tablica=tablica;
		next->next=NULL;
		return next;
	} else {
		l->next=zapisz_generacje(l,tablica);
		return l;
	}

	return 0;
}

int kopiuj_generacje(int **tablica,int r,int c){
	
	int i,j;

	int **generacja;

	generacja = (int**)malloc(sizeof(int*) * r);
		for(i=0 ; i < r ; i++)
			generacja[i] = (int*)malloc(sizeof(int) * c);

 	for(i=0 ; i < r ; i++){
		for(j=0 ; j < r ; j++)
			generacja[i][j]=tablica[i][j];
	}

	return generacja;
}
