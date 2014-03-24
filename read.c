#include "read.h"
#include <stdio.h>
#include <stdlib.h>

Matrix * readFromFile(char * fname){

	int r,c;
	int ir,ic;
	FILE * file = fopen(fname,"r");
	Matrix * matrix = NULL;
	
	/* wczytywanie danych do Matrix-a */

	if(file != NULL){			
		fscanf(file,"%d %d",&r,&c);
		matrix = CreateMatrix(r,c);
		if(matrix != NULL){
			for(ir=0 ; ir < r ; ir++){
				for(ic=0 ; ic < c ; ic++){
					fscanf(file,"%d",&(matrix->data[ir][ic]));
				}
			}
		} else 
			printf(" Wystapil blad w trakcie tworzenia macierza");
	} else 
		printf(" Wystapil blad w trakcie odczytu pliku ");

	fclose(file);
	
	return matrix;
}

Matrix * CreateMatrix(int r, int c){

	int i;

	Matrix * matrix = (Matrix *) malloc(sizeof(Matrix));

	if (matrix != NULL) {
		matrix->r = r;
		matrix->c = c;
		matrix->data=(int**)malloc(sizeof(int*) * r);
		for(i=0 ; i < r ; i++){
			matrix->data[i] = (int*)malloc(sizeof(int) * c);
		}
	}

	return matrix;
}

void PrintMatrix(Matrix *matrix){
	
	int i,j;

	for(i=0 ; i < matrix->r ; i++){
		for(j=0 ; j < matrix->c ; j++)
			printf(" %d ",matrix->data[i][j]);
		printf("\n");
	} 
	printf("\n");
}
