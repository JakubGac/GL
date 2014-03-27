#include <stdio.h>
#include "automat_komorkowy.h"
#include <stdlib.h>

int automat_komorkowy(int **tablica, int r, int c,int ilosc_generacji,lista l){

	int i;

	zapisz_generacje(l,tablica);
	
	int **nowa_generacja = kopiuj_generacje(tablica,r,c);

	for(i=0 ; i < ilosc_generacji ; i++){
		int **nastepna_generacja = generacja(nowa_generacja,r,c);
		zapisz_generacje(l,nastepna_generacja);
		nowa_generacja = kopiuj_generacje(nastepna_generacja,r,c);
	}

	return 0;
}

int generacje(int **tablica, int r, int c){

	int i,j;

	for(i = 0 ; i  < r ; i++){
		for(j=0 ; j < c ; j++){
			if ( tablica[i][j] == 1){	/* komórka żywa */
				zasada_zywa(&tablica_nastepna,i,j);
			} else { 			/*komórka martwa */
				zasada_martwa(&tablica_nastepna,i,j);
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
