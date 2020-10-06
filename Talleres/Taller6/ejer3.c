#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 7

int obtenerAprobados( char * nombres[], int tam, int notas[], char * aprobados[] );

int main(){
  char * nombres[TAM] = {"Ana", "Rosa", "Juan", "Pedro", "Pepe", "Matias", "Jero" };
  int notas[] = {1, 8, 3, 6, 3, 4, 10, 7};
  char * aprobados[TAM];
  int dim  = obtenerAprobados( nombres, TAM, notas, aprobados );
  for( int i = 0; i < dim; i++ )
    printf("%s\n", aprobados[i] );
  for( int i = 0; i < dim; i++ )
    free( aprobados[i] );
}

int obtenerAprobados( char * nombres[], int tam, int notas[], char * aprobados[] ){
  int dim = 0;
  for( int i = 0; i < tam; i++ ){
    if( notas[i] > 4 ){
      aprobados[dim] = malloc( strlen(nombres[i] + 1));
      strcpy( aprobados[dim], nombres[i] );
      dim ++;
    }
  }
  return dim;
}
