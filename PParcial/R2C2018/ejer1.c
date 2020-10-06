#define MAXCOLS 10
#include <stdio.h>

int armaNumero( int array[], int m );
int armaFilas( int mat[][MAXCOLS], int n, int m, int out[] );

int main(){
  int mat[][MAXCOLS] = {{1, 21}, {3, 4}, {5, 6}, {7, -8} };
  int out[4];
  int dim = armaFilas( mat, 4, 2, out );
  for( int i = 0; i < dim; i++ )
    printf("%d ", out[i] );
  putchar('\n');

}

int armaNumero( int array[], int m ){
  int flag = 1, resp = 0;
  for( int i = 0; i < m && flag; i++ ){
    if( array[i] < 0 || array[i] > 9 )
      flag = 0;
    else
      resp = resp * 10 + array[i];
  }
  return flag? resp : -1;
}

int armaFilas( int mat[][MAXCOLS], int n, int m, int out[] ){
  int count = 0, num;
  for( int i = 0; i < n; i++ ){
    num = armaNumero( mat[i], m );
    if( num != -1 )
      out[count++] = num;
  }
  return count;
}
