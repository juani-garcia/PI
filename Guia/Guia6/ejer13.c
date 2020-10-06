#include <stdio.h>
#include "random.h"
#define COLS 100

int linearCom( int dim, const int matA[][COLS], const int matB[][COLS], int row, int col ){
  int sum = 0;
  for( int i = 0; i < dim; i++ ){
      sum += matA[row][i] * matB[i][col];
    }
  return sum;
}

void matProduct( int dim, const int matA[][COLS], const int matB[][COLS], int matC[][COLS]){
  for( int i = 0; i < dim; i++ )
    for ( int j = 0; j < dim; j++ ){
      matC[i][j] = linearCom( dim, matA, matB, i, j );
    }
}


int main(){
  const int matA[][COLS] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
  const int matB[][COLS] = { {521, 612,999}, {743, 768, 432}, {32, 445, 12} };
  int matC[3][COLS];
  matProduct( 3, matA, matB, matC );
  for( int i = 0; i < 3; i++ )
    printVec( matC[i], 3);
}
