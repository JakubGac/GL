#include <stdio.h>
#include <stdlib.h>
#include "automat_komorkowy.h"
#include "zasada_zywa.h"
#include "zasada_martwa.h"
#include "przechowywanie.h"

void generacja(int **tablica, int r, int c, int **tablica_pomocnicza){

	/* funkcja pracuje na podstawie tablicy "tablica", natomiast zmienia 
	wartośći w tablicy "tablica_pomocnicza" */

        int i,j;

        for(i = 0 ; i  < r ; i++){
                for(j = 0 ; j < c ; j++){
                        if ( tablica[i][j] == 1){       /* komórka żywa */
                                zasada_zywa(tablica,i,j,&(tablica_pomocnicza[i][j]),r,c); 
				/* przekazuje do funkcji zasada_zywa określoną komórkę z jej wartością */
                        } else {                        /* komórka martwa */
                                zasada_martwa(tablica,i,j,&(tablica_pomocnicza[i][j]),r,c);
				/* przekazuje do funkcji zasada_martwa określoną komórkę z jej wartością */
                        }
                }
        }
}

int automat_komorkowy(int **tablica,int r, int c,int ilosc_generacji,lista l){

        int i,a,b;

	/* "tablica" - tablica zawierająca zawsze najnowszą generacje
	   "nowa_tablica" - tablica pomocnicza */

        int **nowa_generacja = (int**)malloc(sizeof(int*) * r); /* alokuje pamięć dla tablicy pomocniczej */
                for(i=0 ; i < r ; i++)
                        nowa_generacja[i] = (int*)malloc(sizeof(int) * c);

        for(i=0 ; i < ilosc_generacji ; i++){ /* przeprowadzam zadaną ilość generacji */

                for(a=0 ; a < r ; a++){ /* przepisuje wartość aktualnej generacji do tablicy pomocniczej */
                        for(b=0 ; b < c ; b++)
                                nowa_generacja[a][b] = tablica[a][b];
                }

                generacja(tablica,r,c,nowa_generacja);  /* przeprowadzam generacje, nowa generacja jest 
							zapisywana w tablicy "nowa_generacja" */
                for(a=0 ; a < r ; a++){		/* przepisuje nowe wartośći do tablicy "tablica" */
                        for(b=0 ; b < c ; b++)
                                tablica[a][b] = nowa_generacja[a][b];
                }

                l = zapisz_generacje(l,tablica,r,c); /* zapisuje generacje do listy */
        }

        free_matrix(nowa_generacja,r); /* po przeprowadzeniu wszystkich generacji zwalniam
					pamięć tablicy pomocniczej */
        return 0;
}
