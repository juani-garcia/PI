#define COLS 3
#include <stdio.h>

void sumaxEl( int mat[][COLS], int filas, int salida[] );
int primas( int mat1[][COLS], int fils1, int mat2[][COLS], int fils2 );
int sonMatricesPrimas( int mat1[][COLS], int fils1, int mat2[][COLS], int fils2 );

int main(){
  int mat1[3][COLS] = { {3, -9, 4}, {1, 3, 5}, {3, 7, -8} };
  int mat2[2][COLS] = { {1, 1, 1}, {0, 2, 4} };
  printf("%d\n", sonMatricesPrimas( mat2, 2, mat1, 3));
}

void sumaxEl( int mat[][COLS], int filas, int salida[] ){
  for( int i = 0; i < filas; i++ )
    for( int j = 0; j < COLS; j++ )
      salida[j] += mat[i][j];
}

int primas( int mat1[][COLS], int fils1, int mat2[][COLS], int fils2 ){
  int sumaFilas[COLS] = {0};
  sumaxEl( mat2, fils2, sumaFilas);
  for( int i = 0, iguales = 0; i < fils1; i++ ){
    for( int j = 0; j < COLS; j++ )
      iguales += ( mat1[i][j] == sumaFilas[j] );
    if( iguales == COLS )
      return 1;
  }
  return 0;
}

int sonMatricesPrimas( int mat1[][COLS], int fils1, int mat2[][COLS], int fils2 ){
  if( primas( mat1, fils1, mat2, fils2 ) )
    return 1;
  if( primas( mat2, fils2, mat1, fils1 ) )
    return 2;
  return 0;
}
