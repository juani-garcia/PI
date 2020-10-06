#define MAXCOLS 3
#include <stdio.h>

int escalable( int mat[][MAXCOLS], int filas, int cols );
int sumaFila( int mat[][MAXCOLS], int cols, int i);
int sumaCol( int mat[][MAXCOLS], int filas, int j );

int main(){
  int mat[4][MAXCOLS] = { {1, 1, 1}, {1, 1, 2}, {1, 0, 2}, {2, 2, 2} };
  printf("%d\n", escalable( mat, 4, 3 ));
}

int escalable( int mat[][MAXCOLS], int filas, int cols ){
  int flag = 1, anterior = sumaFila( mat, cols, 0 ), siguiente;
  for( int i = 1; i < filas && flag; i++ ){
    siguiente = sumaFila( mat, cols, i );
    if( siguiente != anterior + 1 )
      flag = 0;
    anterior = siguiente;
  }

  anterior = sumaCol( mat, filas, 0 );
  for( int j = 1; j < cols && flag; j++ ){
    siguiente = sumaCol( mat, filas, j );
    if( siguiente != anterior + 1 )
      flag = 0;
    anterior = siguiente;
  }
  return flag;
}

int sumaFila( int mat[][MAXCOLS], int cols, int i){
  int sum = 0;
  for( int k = 0; k < cols; k++ )
    sum += mat[i][k];
  return sum;
}

int sumaCol( int mat[][MAXCOLS], int filas, int j ){
  int sum = 0;
  for( int k = 0; k < filas; k++ )
    sum += mat[k][j];
  return sum;
}
