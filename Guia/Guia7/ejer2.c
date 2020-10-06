#include "getnum.h"
#include <stdio.h>
#include <math.h>
#define CLEAN while( getchar() != '\n' )
void fromTo( int * entrada, int * salida );
int read( int entrada );
int toBase10( int num, int entrada );
int fromBase10( int num, int salida );

int main(){
  int entrada, salida;
  fromTo( &entrada, &salida );
  int pasar = read(entrada);
  int final = toBase10( pasar, entrada );
  final = fromBase10( final, salida );
  printf("%d(%d) = %d(%d)\n", pasar, entrada, final, salida );
}

void fromTo( int * entrada, int * salida ){
  int cant, aux1, aux2;
  do{
  cant = scanf("<%d>%d", &aux1, &aux2 );
  CLEAN;
  } while( cant != 2 || ( aux1 > 11 || aux1 < 2 || aux2 > 11 || aux2 < 2));
  * entrada = aux1;
  * salida = aux2;
}

int read( int entrada ){
  int num, flag, aux;
  do{
    aux = num  = getint("Ingrese un entero en base %d: ", entrada );
    flag = 0;
    while( aux && !flag ){
      if( aux % 10 >= entrada )
        flag = 1;
      aux /= 10;
    }
  }while(flag);
  return num;
}

int toBase10( int num, int entrada ){
  int res = 0;
  for( int i = 0; num; num /= 10, i++ ){
    res = res + (num % 10) * pow(entrada, i);
  }
  return res;
}

int fromBase10( int num, int salida ){
  int res = 0;
  for( int i = 0; num; num /= salida, i++ )
    res = res + (num % salida) * pow(10, i);
  return res;
}
