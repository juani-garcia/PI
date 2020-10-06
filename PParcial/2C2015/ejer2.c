#include <stdio.h>
#define MAXCOLS 10
int esMagica( int mat[][MAXCOLS], int dim );

int main(){
  int mat[3][MAXCOLS] = {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
  printf( "%d\n", esMagica( mat, 3 ) );
}

int esMagica( int mat[][MAXCOLS], int dim ){
  int diag1 = 0, diag2 = 0, sumaCol = 0, sumaFil = 0;
  for( int i = 0; i < dim; i++ ){
    diag1 += mat[i][i];
    diag2 += mat[i][dim - 1 - i];
  }
  if( diag1 != diag2 )
    return 0;

  for( int j = 0; j < dim; j++, sumaFil = sumaCol  = 0 ){
    for( int k = 0; k < dim; k++ ){
      sumaFil += mat[j][k];
      sumaCol += mat[k][j];
    }

    if( sumaCol != diag1 || sumaFil != diag2 ){
      return 0;
    }
  }
  return diag1;
}
