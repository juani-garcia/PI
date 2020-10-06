#define ANCHO 5
#define ALTO 6
#include <stdio.h>

int valido( int i, int j );
int promedio( int mat[][ANCHO], int fila, int col, int w );
void suavizar( int mat[][ANCHO], int w, int res[][ANCHO] );

int main(){
  int bmp[][ANCHO] = {{10, 10, 20, 23, 24}, {10, 12, 18, 25, 23},
  {12, 14, 18, 26, 22}, {12, 14, 19, 20, 22},
  {13, 16, 19, 20, 22}, {14, 14, 19, 21, 23} };
  int res[ALTO][ANCHO];
  suavizar( bmp, 3, res);
  for( int i = 0; i < ALTO; i++){
    for( int j = 0; j < ANCHO; j++)
      printf("%d ", res[i][j]);
    putchar('\n');
  }

}

int valido( int i, int j ){
  return ( i >= 0 && j >=0 && i < ALTO && j < ANCHO );
}

int promedio( int mat[][ANCHO], int fila, int col, int w ){
  int despl = w/2, sum  = 0, cant = 0;
  for( int i = fila - despl; i <= fila + despl; i++ )
    for( int j = col -despl; j <= col + despl; j++ )
      if( valido(i, j)){
        cant++;
        sum += mat[i][j];
      }
  return sum / cant;
}

void suavizar( int mat[][ANCHO], int w, int res[][ANCHO] ){
  for( int i = 0; i < ALTO; i++ )
    for( int j = 0; j < ANCHO; j++ )
      res[i][j] = promedio( mat, i, j, w );
}
