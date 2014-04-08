#include <stdlib.h>
#include <stdio.h>
#include "obrazek.h"
#include "przechowywanie.h"

int t1[801][801];
int t2[100][100];

int generuj_obrazek(lista l, int r,int co_ile){

	int i=0;
	int j,k;

	while(l != NULL){

		for(j=0 ; j < 801 ; j++){
			for(k=0 ; k < 801 ; k++)
				t1[j][k]=0;
		}

		for(j=0 ; j < 100 ; j++){
			for(k=0 ; k < 100 ; k++)
				t2[j][k]=0; 
		}

		wypisywanie(l->tablica_element,r,i);

		if(co_ile){ /* jezeli tak to tworze tylko "co ktores" obrazki */
			for(j=0 ; j < co_ile ; j++){
                        	if(l->next != NULL)
                                	l=l->next;
                       		else
                                	return -1;
               		}
		} else {
			l=l->next;
		}

		i++;
	} 

	return 0;
	 
}

void oznacz(int k, int l, int x, int n) {

	int i,j,a,b;

	for (i = k * x + 1, a = 1; a < x && i < 801; a++, i++){
		for (j = l * x + 1, b = 1; b < x && j < 801; b++, j++)
			t1[i][j] = 2;
	}
}



void generuj(int x, int n){

	int i, j;

	for (i = 0; i < 801; i += x){
		for (j = 0; j < 801; j++){
			t1[i][j] = 1; 
			t1[j][i] = 1;
		}
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (t2[i][j])
				oznacz(i, j, x, n);
		}
	}
}



int skala(int n){

	if (800.0 / n == 800 / n)
		return 800 / n;
	else
		return 800 / n + 1;
}

int wypisywanie(int **tabka,int n,int ktora_generacja){

	int i,j,x;
	char nazwa_pliku[128];
	FILE * fp;

	sprintf(nazwa_pliku,"image/%d.ppm",ktora_generacja);

	fp = fopen(nazwa_pliku, "wb"); /* b - binary mode  */

	fprintf(fp, "P6\n%d %d\n255\n", 800, 800);

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			t2[i][j] = tabka[i][j];
		}
	}

	x = skala(n); /* obliczenie proporcij */

	generuj(x, n); /* generowanie siatki */

	/* KOLOROWANIE */

	for (i = 1; i < 801; i++){
		for (j = 1; j < 801; j++){

			static unsigned char color[3];

			switch(t1[i][j]){

				case 1:
					color[0] = 0;
					color[1] = 0; 
					color[2] = 0; 
					break;
				case 2:                                                           
					color[0] = 0;
					color[1] = 119; 
					color[2] = 255; 
					break;
				default:
					color[0] = 240;
					color[1] = 255;  
					color[2] = 255;
			}
			
			fwrite(color, 1, 3, fp);
		}
	}

	fclose(fp);

	return EXIT_SUCCESS;
}
