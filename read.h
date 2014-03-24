#ifndef _READ_H
#define _READ_H

typedef struct _Matrix {
		int r,c;
		int **data;
} Matrix; 

Matrix * readFromFile(char * fname); 

Matrix * CreateMatrix(int r, int c);

void PrintMatrix(Matrix * matrix);

#endif
