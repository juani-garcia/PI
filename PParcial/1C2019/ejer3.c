#include <stdio.h>
#define DIM 10
int esAscendente( int mat[][DIM], int dim, int vec[] );

int main(){
  int mat[DIM][DIM] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
  int vec[DIM*DIM];
  int n = esAscendente( mat, 3, vec);
  for( int i = 0; i < n; i++ )
    printf( "%d ", vec[i] );
  putchar('\n');
}

int esAscendente( int mat[][DIM], int dim, int vec[] ){
  int agrego = 0, asciende = 1;
  vec[agrego++] = mat[0][0];
  for( int i = 0; i < dim && asciende; i++ )
    for( int j = 0; j < dim && asciende; j++ ){
      if( i + j ){
        if( mat[i][j] < mat[i][j - 1] || mat[j][i] < mat[j][i-1] )
          asciende = 0;
        if( asciende && (agrego == 0 || vec[agrego-1] != mat[i][j]))
          vec[agrego++] = ( mat[i][j] < mat[j][i] ? mat[i][j] : mat[j][i]);
        }
    }
  return agrego * asciende;
}
