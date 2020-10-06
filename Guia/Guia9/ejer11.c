#include <stdio.h>
#define DIM 5

void negar( int mat[][DIM], int fil, int col );
void negarRec( int mat[][DIM], int fil, int col, int hor, int vert );

int main(){
  int mat[][DIM] = { {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1} };
  for( int i = 0; i < DIM; i++){
    for( int j = 0; j < DIM; j++)
      printf("%d ", mat[i][j]);
    putchar('\n');
  }
  putchar('\n');
  negar( mat, 2, 2 );
  for( int i = 0; i < DIM; i++){
    for( int j = 0; j < DIM; j++)
      printf("%d ", mat[i][j]);
    putchar('\n');
  }
}

void negar( int mat[][DIM], int fil, int col ){
  if( fil < 0 || col < 0 || fil >= DIM || col >= DIM || DIM == 0 )
    return;
  mat[fil][col] = !mat[fil][col];
  negarRec( mat, fil + 1, col + 1, 1, 1 );
  negarRec( mat, fil + 1, col -1 , 1, -1 );
  negarRec( mat, fil - 1, col + 1, -1, 1 );
  negarRec( mat, fil - 1, col - 1, -1, -1 );
  return;
}

void negarRec( int mat[][DIM], int fil, int col, int hor, int vert ){
  if( fil < 0 || col < 0 || fil >= DIM || col >= DIM )
    return;
  mat[fil][col] = !mat[fil][col];
  negarRec( mat, fil + hor, col + vert, hor, vert );
}
