#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "random.h"
#define LIN 3
#define COL 5
#define BOLILLAS 90
typedef int TipoLinea[5];
typedef TipoLinea TipoCarton[3];

void generarCarton( TipoCarton carton );
void imprimeLinea( TipoLinea linea );
void imprimeCarton( TipoCarton carton );
int sacarBolilla( int bolillero[], size_t * cant );
int buscarBolillas( int bolilla, TipoCarton carton );
int controlarLinea( TipoLinea linea );
int controlarCarton( int bolilla, TipoCarton carton );
int jugar( int bolillero[], TipoCarton carton1, TipoCarton carton2 );
void generarBolillero( int bolillero[] );

int main(){
  randomize();
  TipoCarton carton1, carton2;
  int bolillero[BOLILLAS];
  generarBolillero( bolillero );
  generarCarton( carton1 ); generarCarton( carton2 );
  printf("Jugador 1:\n");
  imprimeCarton(carton1);
  printf("Jugador 2:\n");
  imprimeCarton(carton2);
  int bingo = jugar( bolillero, carton1, carton2 );
  for( int i = 1; i < 3; i++ )
    if( bingo & i )
      printf("El jugador %d hizo bingo!\n", i );
}

void imprimeLinea( TipoLinea linea ){
  putchar('|');
  for( int i = 0; i < COL; i++ ){
    if( linea[i] )
      printf("| %2d |", linea[i] );
    else
      printf("%s", "| XX |");
  }
  putchar('|');
  putchar('\n');
}

void imprimeCarton( TipoCarton carton ){
  for( int i = 0; i < LIN; i++ ){
    imprimeLinea( carton[i] );
  }
}

void generarCarton( TipoCarton carton ){
  int dim = BOLILLAS - 1, r;
  int bolillero[dim];
  for( int i = 0; i <= dim; i++ )
    bolillero[i] = i + 1;

  for( int i = 0; i < LIN; i++ )
    for( int j = 0; j < COL; j++ ){
      r = randInt(0, dim );
      carton[i][j] = bolillero[r];
      bolillero[r] = bolillero[ dim-- ];
    }
}

int sacarBolilla( int bolillero[], size_t * cant ){
  int aux = (*cant) - 1;
  int r = randInt(0, aux);
  int bolilla = bolillero[r];
  bolillero[r] = bolillero[aux];
  (*cant)--;
  return bolilla;
}

int buscarBolillas( int bolilla, TipoCarton carton ){
  for( int i = 0; i < LIN; i++ )
    for( int j = 0; j < COL; j++){
      if( carton[i][j] == bolilla ){
        carton[i][j] = 0;
        return 1;
      }
    }
  return 0;
}

int controlarLinea( TipoLinea linea ){
  for( int i = 0; i < COL; i++ )
    if( linea[i] != 0 )
      return 0;
  return 1;
}

int controlarCarton( int bolilla, TipoCarton carton ){
  int lineas = 0;
  if( buscarBolillas( bolilla, carton ) )
    for( int i = 0; i < LIN; i++ )
      lineas += controlarLinea( carton[i] );
  imprimeCarton( carton );
  return lineas;
}

int jugar( int bolillero[], TipoCarton carton1, TipoCarton carton2 ){
  int bingo = 0, bolilla, huboLinea = 0, lineas1, lineas2;
  size_t cant = BOLILLAS;
  while( !bingo ){
    bolilla = sacarBolilla( bolillero, &cant );
    printf("Salio la bolilla numero %d! ", bolilla );
    printf("Actualizamos los cartones...\nJugador 1:\n");
    lineas1 = controlarCarton( bolilla, carton1 );
    printf("Jugador 2:\n");
    lineas2 = controlarCarton( bolilla, carton2 );

    if( !huboLinea ){
      if( lineas1 > 0 )
        printf("El jugador 1 hizo linea!\n");
      if( lineas2 > 0)
        printf("El jugador 2 hizo linea!\n");
      huboLinea += lineas1 + lineas2;
    }
    //sleep(2);
    bingo = ( lineas1 == LIN ) | ( 2 * (lineas2 == LIN ) );
  }
  return bingo;
}

void generarBolillero( int bolillero[] ){
  for( int i = 0; i < BOLILLAS; i++ )
    bolillero[i] = i + 1;
}
