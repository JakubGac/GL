#include <stdio.h>
#include "zasada_zywa.h"
#include "zasada_martwa.h"
#include "read.h"

int automat_komorkowy(Matrix * matrix){

	int ir,ic;

	for(ir=0 ; ir < matrix->r; ir++){
		for(ic=0 ; ic < matrix->c ; ic++){
			if(matrix->data[ir][ic] == 1){
				ZasadaZywa(matrix->data[ir][ic]);
			}
			else {
				ZasadaMartwa(matrix->data[ir][ic]);
			}
		}
	}
	
	return 0;		
}

