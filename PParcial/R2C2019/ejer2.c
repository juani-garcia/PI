#include <stdio.h>
#define N 4
#define M 4

int armaFilas( int mat[][M], int vec[] );
int armaNum( int array[] );

int main(){
  int mat[N][M] = { {1, 2, 30, 4}, {5, 6, 7, -8}, {9, 8, 7, 6}, {5, 4, 3, 2} };
  int vec[N];
  int dim = armaFilas( mat, vec );
  for( int i = 0; i < dim; i++ )
    printf( "%d ", vec[i] );
  putchar('\n');
}

int armaNum( int array[] ){
  int sum = 0;
  for( int i  = 0; i < M; i++ ){
    if( array[i] < 0 || array[i] > 9 )
      return -1;
    else
      sum = 10 * sum + array[i];
  }
  return sum;
}

int armaFilas( int mat[][M], int vec[] ){
  int newDim = 0, num;
  for( int i = 0; i < N; i++ ){
    num = armaNum( mat[i] );
    if( num + 1 )
      vec[ newDim++ ] = num;
  }
  return newDim;
}
