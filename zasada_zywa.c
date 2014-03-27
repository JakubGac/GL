#include "zasada_zywa.h"
#include "read.h"

int Zasada_Zywa(int **tablica, int r, int c){

	int i,j;
	int ile_zywych=0;

	for(i=r-1 ; i < c+2 ; i++){ /* przeszukanie wiersza nad komórką */
		if(tablica[r-1][i] == 1){
			ile_zywych++;
		}  	
	}

	for(i=r+1 ; i < c+2 ; i++) { /* przeszukanie wiersza pod komórką */
		if(tablica[r+1][i] == 1){
			ile_zywych++;
		}
	}

	if(tablica[r][c-1]){	     /* przeszukanie z lewej strony komórki */	 
		ile_zywych++;
	}
	
	if(tablica[r][c+2]){	     /* przeszukanie z prawej strony komórki */
		ile_zywych++;
	}

	if(ile_zywych == 2 || ile_zywych == 3){
		tablica[r][c]=1;
	} else {
		tablica[r][c]=0;
	}

	return tablica;

}
