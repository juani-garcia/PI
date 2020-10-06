#include <stdio.h>
#include "random.h"
#define COLS 100
#define FILAS 100

void transpose( int mat[][COLS], int dim ){
  int triangulo = 1, temp;
  for( int i = 1; i < dim; i++, triangulo++ )
    for( int j = 0; j < triangulo; j++ ){
      temp = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;
    }
}

int main(){
  randomize();
  int filas  = 3;
  int cols = 3;
  int mat[FILAS][COLS];
  for( int i = 0; i < filas; i++)
    llenarInt( 0, 25, mat[i], cols);

  for( int i =0; i < filas; i++)
    printVec( mat[i], cols);

  transpose( mat, filas );
  putchar('\n');

  for( int i = 0; i < filas; i++)
    printVec( mat[i], cols);
}
