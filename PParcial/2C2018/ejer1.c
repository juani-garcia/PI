#include <stdio.h>
#define ERROR -1
#define MAXCOLS 10

int armaNum( int array[], int dim );
int maxMatriz( int mat[][MAXCOLS], int n, int m );

int main(){
  int mat[][MAXCOLS] = {{1, 2, 3}, {-4, 5, 6}, {7, 8, 90}};
  printf("%d\n", maxMatriz( mat, 3, 3 ));
}

int armaNum( int array[], int dim ){
  int resp = 0;
  for( int i = 0; i < dim; i++ ){
    if( array[i] < 0 || array[i] > 9 )
      return ERROR;
    resp = 10 * resp + array[i];
  }
  return resp;
}

int maxMatriz( int mat[][MAXCOLS], int n, int m ){
  int max = ERROR, newNumber = 0;
  for( int i = 0; i < n; i++ ){
    newNumber = armaNum( mat[i], m );
    max = ( newNumber > max)? newNumber : max;
  }
  return max;
}
