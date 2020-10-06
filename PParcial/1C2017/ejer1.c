#include <stdio.h>
#define COLS 3

int sumaVecinos( int mat[][COLS], int filas, int cols, int i, int j );
int encuentraValle( int mat[][COLS], int valles[][COLS], int filas, int cols );

int main(){
  int mat[][COLS] = { { 1, 2, 0 }, { 0, 9, 1 }, { 3, 1, 1 } };
  int valles[3][3] = {0};
  encuentraValle( mat, valles, 3, 3 );
  for( int i = 0; i < 3; i++ ){
    for( int j = 0; j < 3; j++ )
      printf("%d  ", valles[i][j] );
    putchar('\n');
  }
}

int sumaVecinos( int mat[][COLS], int filas, int cols, int i, int j ){
  int sum  = 0;
  for( int n = i - 1; n < i + 2 ; n++ )
    for( int m = j - 1; m < j + 2; m++ )
      if( n >= 0 && m >= 0 && n <= filas && m <= cols )
        sum += mat[n][m];
  return (sum - mat[i][j]);
}

int encuentraValle( int mat[][COLS], int valles[][COLS], int filas, int cols ){
  int count = 0, sum;
  for( int i = 0; i < filas; i++ )
    for( int j = 0; j < cols; j++ ){
      sum = sumaVecinos( mat, filas, cols, i, j );
      if( mat[i][j] == sum ){
        count++;
        valles[i][j] = 1;
      }
    }
  return count;
}
