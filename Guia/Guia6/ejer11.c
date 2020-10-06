#include <stdio.h>
#include "random.h"
#define FILAS 100
#define COLS 100

void swapRows( int mat[][COLS], int cols, int a, int b ){
  int temp;
  for( int i = 0; i < cols; i++ ){
    temp = mat[a][i];
    mat[a][i] = mat[b][i];
    mat[b][i] = temp;
  }
}

void order( int mat[][COLS], int filas, int cols, int key ){
  int flag = 1;
  while( flag ){
    flag = 0;
    for( int i = 0; i < filas - 1; i++ ){
      if ( mat[i][key] > mat[i + 1][key] ){
        swapRows( mat, cols, i, i +1 );
        flag = 1;
      }
    }
  }
}



int main(){
  randomize();
  int filas  = 4;
  int cols = 4;
  int mat[FILAS][COLS];
  for( int i = 0; i < filas; i++)
    llenarInt( 0, 25, mat[i], cols);

  for( int i =0; i < filas; i++)
    printVec( mat[i], cols);

  order( mat, filas, cols, 0 );
  putchar('\n');

  for( int i = 0; i < filas; i++)
    printVec( mat[i], cols);
}
