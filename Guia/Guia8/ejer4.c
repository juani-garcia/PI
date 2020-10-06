#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#define SALIO( X, Y, R ) ( X*X + Y*Y > R*R )

typedef struct{
  int x;
  int y;
}tipoPunto;

tipoPunto nuevoPunto( tipoPunto * anterior );

int main(){
  randomize();
  size_t t = 0, r = 100000;
  tipoPunto punto = {0, 0};
  while( !SALIO( punto.x, punto.y, r ) ){
    //printf("x: %2d\ty: %2d\n", punto.x, punto.y);
    punto = nuevoPunto( &punto );
    t++;
  }
  printf("t   R   R/t\n");
  printf("%lu  %lu  %.3f\n", t, r, (double)r/t );
}

tipoPunto nuevoPunto( tipoPunto * anterior ){
  tipoPunto nuevo;
  nuevo = *anterior;
  int r = randInt(1, 4);
  switch( r ){
    case 1:
      nuevo.x++;
      break;
    case 2:
      nuevo.x--;
      break;
    case 3:
      nuevo.y++;
      break;
    case 4:
      nuevo.y--;
      break;
  }
  return nuevo;
}
