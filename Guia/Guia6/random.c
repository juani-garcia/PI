#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

double
randNormalize(void) {
	return rand() / ( (double) RAND_MAX + 1);
}

int
randInt(int izq, int der) {
	// return rand() % (der - izq + 1) + izq;
	return (int)(randNormalize() * (der - izq + 1) + izq);
}

double
randReal(double izq, double der) {
	return (randNormalize() * (der - izq) + izq);
}

void
randomize(void) {
	srand((int)time(NULL));
}

void llenarInt( int max, int min, int dest[], int dim){
  for ( int i = 0; i < dim; i++ ){
    dest[i] = randInt(max, min);}
}

void llenar( int dest[], int dim ){
  for ( int i = 0; i < dim; i++ ){
    dest[i] = rand();}
}

void llenarReal( double max, double min, double dest[], int dim){
  for ( int i = 0; i < dim; i++ ){
    dest[i] = randReal(max, min);}
}

void printVec( int v[], int dim){
	for( int i = 0; i < dim; i++)
		printf("%2d ", v[i]);
	putchar('\n');
}
