#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COLS 7
#define FILS 6
#define BLOCK 10
#define EN_RANGO(i, j)  (i >= 0 && i < FILS && j >= 0 && j < COLS)

typedef enum {DER = 0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } tDirec;

typedef struct{
  char * palabra;
  size_t fila;
  size_t columna;
  tDirec direccion;
}tPos;

typedef tPos * tResp;

tResp resolverSopa( char sopa[][COLS], char ** dicc );
int buscaPalabra( tPos * pos, char sopa[][COLS] );

int main(){
  char sopa[FILS][COLS] = {
        {'X', 'X', 'X', 'O', 'X', 'X', 'X'},
        {'A', 'P', 'A', 'C', 'Y', 'Y', 'O'},
        {'Z', 'E', 'Z', 'R', 'Z', 'C', 'X'},
        {'E', 'R', 'R', 'O', 'R', 'X', 'X'},
        {'X', 'R', 'I', 'O', 'I', 'E', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'X'}
    };
    char * dicc[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO",
                     "PERTINAZ", "REA", "RIO", ""};
    tResp res = resolverSopa( sopa, dicc );
    for( int i = 0; res[i].palabra != NULL; i++ )
      printf("{%s, %zu, %zu, %d}\n", res[i].palabra, res[i].fila, res[i].columna, res[i].direccion );
    free( res );
}


int buscaPalabra( tPos * pos, char sopa[][COLS] ){
  int di[] = {0, 0, -1, 1, 1, -1, 1, -1};
  int dj[] = {1, -1, 0, 0, -1, -1, 1, 1};
  int i = pos->fila, j = pos->columna;
  for( int k = 0; pos->palabra[k]; k++ ){
    if( !EN_RANGO(i, j) )
      return 0;
    if( sopa[i][j] != pos->palabra[k])
      return 0;
    i += di[pos->direccion];
    j += dj[pos->direccion];
  }
  return 1;
}

tResp resolverSopa( char sopa[][COLS], char ** dicc ){
  tResp res;
  res = NULL;
  tPos pos;
  pos.palabra = NULL;
  int cant = 0;
  for( int k = 0; dicc[k][0]; k++ ){
    pos.palabra = dicc[k];
    for( int i = 0; i < FILS; i++ ){
      pos.fila = i;
      for( int j = 0; j < COLS; j++){
        pos.columna = j;
        for( int d = 0; d <= D_AB; d++ ){
          pos.direccion = d;
          if(buscaPalabra( &pos, sopa )){
            if( cant % BLOCK == 0 )
              res = realloc(res, (BLOCK + cant) * sizeof(tPos));
            res[cant++] = pos;
          }
        }
      }
    }
  }
  res[cant].palabra = NULL;
  res = realloc( res, cant * sizeof(tPos));
  return res;
}
