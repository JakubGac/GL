#include "read.h"
#include "automat_komorkowy.h"
#include <stdio.h>
#include <stdlib.h>

int readFromFile(char * fname,lista l){

	int r,c;
	int ir,ic;
	int i;
	FILE * file = fopen(fname,"r");
	int **matrix;

	/* wczytywanie danych do matrix-a */

	if(file != NULL){			
		
		fscanf(file,"%d %d",&r,&c);
		
		matrix = (int**)malloc(sizeof(int*) * r);
			for(i=0 ; i < r ; i++)
				matrix[i] = (int*)malloc(sizeof(int) * c);

		if(matrix != NULL){
			for(ir=0 ; ir < r ; ir++){
				for(ic=0 ; ic < c ; ic++){
					fscanf(file,"%d",&(matrix[ir][ic]));
				}
			}
		} else 
			printf(" Wystapil blad w trakcie tworzenia macierza");
	} else 
		printf(" Wystapil blad w trakcie odczytu pliku ");

	l = zapisz_generacje(l,matrix,r,c);

	fclose(file);
	
	return 0;
}

int ReadRows(char *fname){

	int r;

	FILE * file = fopen(fname,"r");

	fscanf(file,"%d",&r);

	fclose(file);

	return r;
}

int ReadColumns(char *fname){

	int c,r;

	FILE * file = fopen(fname,"r");

	fscanf(file,"%d %d",&r,&c);

	fclose(file);

	return c;
}

