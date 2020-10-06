#include <stdio.h>
#include "random.h"
#define FILAS 20
#define COLS 20

void estrellas( int m[][COLS], int filas, int cols ){
  int avg;
  for( int i = 1; i < filas - 1; i++ ){
    for( int j = 1; j < cols - 1; j++ ){
      avg = (m[i][j]+m[i][j-1]+m[i][j+1]+m[i-1][j]+m[i-1][j-1]+m[i-1][j+1]+m[i+1][j]+m[i+1][j-1]+m[i+1][j+1]) / 9;
      printf("%s ", avg > 10? "1" : "0" );
    }
  putchar('\n');
  }
}

void generaMat( int mat[][COLS] ){
  for( int i = 0; i < FILAS; i++)
    llenarInt( 0, 20, mat[i], COLS);
}


int main(){
  randomize();
  int mat[FILAS][COLS];
  generaMat( mat );
  estrellas( mat, FILAS , COLS );
 }
