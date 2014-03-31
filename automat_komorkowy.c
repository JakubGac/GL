#include <stdio.h>
#include <stdlib.h>
#include "automat_komorkowy.h"
#include "zasada_zywa.h"
#include "zasada_martwa.h"

int automat_komorkowy(int **tablica, int r, int c,int ilosc_generacji,lista l){

	int i;
	
	int **nowa_generacja;

	int **tablica_pomocnicza;

	nowa_generacja = (int**)malloc(sizeof(int*) * r);
		for(i=0 ; i < r ; i++)
			nowa_generacja[i] = (int*)malloc(sizeof(int) * c);

	tablica_pomocnicza = (int**)malloc(sizeof(int*) * r);
		for(i=0 ; i < r ; i++)
			tablica_pomocnicza[i] = (int*)malloc(sizeof(int) * c);

	for(i=0 ; i < ilosc_generacji ; i++){
		
		nowa_generacja = skopiuj(tablica,nowa_generacja,r,c);

		tablica_pomocnicza = skopiuj(tablica,tablica_pomocnicza,r,c);

		nowa_generacja = generacja(tablica,r,c,tablica_pomocnicza);

		tablica = skopiuj(nowa_generacja,tablica,r,c);
	
		l = zapisz_generacje(l,tablica,r,c); 
	}

	return 0;
}

int generacja(int **tablica, int r, int c, int **tablica_pomocnicza){

	int i,j;

	for(i = 0 ; i  < r ; i++){
		for(j = 0 ; j < c ; j++){
			if ( tablica[i][j] == 1){	/* komórka żywa */
				zasada_zywa(tablica,i,j,&(tablica_pomocnicza[i][j]),r,c);
			} else { 			/*komórka martwa */
				zasada_martwa(tablica,i,j,&(tablica_pomocnicza[i][j]),r,c);
			}                        
		}
	}

	return tablica_pomocnicza;
}

lista zapisz_generacje(lista l, int **tablica,int r, int c){

	int i;

	if( l == NULL){
		lista next = malloc(sizeof * next);
		next->tablica= (int**)malloc(sizeof(int*) * r);
			for(i=0 ; i < r ; i++)
				next->tablica[i] = (int*)malloc(sizeof(int) * c);
		next->tablica = skopiuj(tablica,next->tablica,r,c);
		next->next=NULL;
		return next;
	} else {
		l->next=zapisz_generacje(l->next,tablica,r,c);
		return l;
	}
}

int skopiuj(int **tablica, int **nowa_tablica,int r, int c){

	int i,j;

	for(i=0 ; i < r ; i++){
		for(j=0 ; j < c ; j++)
			nowa_tablica[i][j] = tablica[i][j];
	}

	return nowa_tablica;
}

void wypisz(int **tablica){

	int i,j;

	for(i=0 ; i < 10 ; i++){
		for(j=0 ; j < 10 ; j++)
			printf(" %d ",tablica[i][j]);
		printf("\n");
	}
	printf("\n");
}

void wypisz_listee(lista l){

	while(l != NULL){
		wypisz(l->tablica);
		l=l->next;
	}

}
