#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	double* vecteur;
	vecteur=malloc(1024*sizeof(double));
	double* vecteur2;
	vecteur2=malloc(1024*sizeof(double));
	
	srand(time(NULL));
	
	for(int i=0;i<1024;i++) vecteur[i]= ( (double)rand() * 100 ) / (double)RAND_MAX;
	for(int i=0;i<1024;i++) vecteur2[i]= ( (double)rand() * 100 ) / (double)RAND_MAX;
	
	for(int i=0;i<1024;i++) printf("%.2f\n", vecteur[i]);
	
	return 0;
}

