#include "zasada_martwa.h"

int zasada_martwa(int **tablica, int r, int c,int *zmienna, int rows, int columns){

	int i;
	int ile_zywych=0;

	if((r-1) >= 0){
		for(i=c-1 ; i < c+2 ; i++){ /* przeszukanie wiersza nad komórką z zawinieciem przy wierszy pierwszym */
			if(i >= 0 && i < columns){
				if(tablica[r-1][i] == 1){
					ile_zywych++;
				}
			}
		}
	} else {
		for(i=c-1 ; i < c+2 ; i++){ 
                        if(i >= 0 && i < columns){
                                if(tablica[rows-1][i] == 1){
                                        ile_zywych++;
                                }
                        }
                }
	}

	if((r+1) < rows){
		for(i=c-1 ; i < c+2 ; i++) { /* przeszukanie wiersza pod komórką z zawinieciem przy ostatnim wierszu */
			if(i >= 0 && i < columns){
				if(tablica[r+1][i] == 1){
					ile_zywych++;
				}
			}
		}
	} else {
		for(i=c-1 ; i < c+2 ; i++) { 
                        if(i >= 0 && i < columns){
                                if(tablica[0][i] == 1){
                                        ile_zywych++;
                                }
                        }
                }
	}
	
	if((c-1) >= 0){
		if(tablica[r][c-1] == 1){	     /* przeszukanie z lewej strony komórki z zawinieciem przy skrajnych lewych wierszach */	 
			ile_zywych++;
		}
	} else {
		if(tablica[r][columns-1] == 1){
			ile_zywych++;
		}
	}

	if((c+1) < columns ){
		if(tablica[r][c+1] == 1){	     /* przeszukanie z prawej strony komórki z zawinieciem przy skrajnych prawych wierszach */
			ile_zywych++;
		}

	} else {
		if(tablica[r][0] == 1){
			ile_zywych++;
		}
	}

	if(ile_zywych == 3){
		*zmienna=1;
	}

	return 0;
}
