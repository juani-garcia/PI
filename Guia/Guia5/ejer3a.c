#include <stdio.h>
#include "getnum.h"
#include <math.h>
#include <stdlib.h>
int lugar (int num, int pos);

#define LENGTH(n)  (( int ) ceil ( log10( abs( n ) )))

int main(){
  int boleto, esCapicua=1;
  int j;

  do{
  boleto = getint("Ingrese un número de 5 dígitos: ");
  } while ( LENGTH(boleto) != 5 );

  for (j=1; j<=2; j++) {
    if ( lugar(boleto, j) != lugar(boleto,5-j+1)) {
      esCapicua=0;
      break;
    }
  }
  printf("El boleto %ses capicúa\n",(esCapicua)? "":"no ");
  return 0;
}

int lugar( int num, int pos ){
  return (num / (int)pow(10, pos-1)) % 10;
}
