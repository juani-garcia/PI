#define DIM 3
#include <stdio.h>

int simAsim( int mat[][DIM] );

int main(){
  int mat[DIM][DIM] = {{0, 0, -1}, {0, 0, 0}, {1, 0, 0}};
  printf("%d\n", simAsim( mat ));
}

int simAsim( int mat[][DIM] ){
  int sim = 1, asim = 1;
  for( int i = 1; i < DIM && (sim || asim); i++ )
    for( int j = 0; j <= i && (sim || asim); j++ ){
      if( mat[i][j] != mat[j][i] )
        sim = 0;
      if( mat[i][j] != -mat[j][i] )
        asim = 0;
    }
  if( sim == 1 )
    return 1;
  if( asim == 1 )
    return -1;
  return 0;
}
