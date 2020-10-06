#include <stdio.h>
#include "getnum.h"
#include <math.h>
#include <stdlib.h>
int lugar (int num, int pos);

#define LENGTH(n)  (( int ) ceil ( log10( abs( n ) )))

int main(){
  long boleto, esCapicua=1;
  boleto = getint("Ingrese un número: ");
  int Len = LENGTH(boleto);

  for (int j = 1; j <= (Len/2); j++)
    if ( lugar(boleto, j) != lugar(boleto, Len - j + 1 )) {
      esCapicua = 0;
      break;
    }

  printf("El boleto %ses capicúa\n",(esCapicua)? "":"no ");
  return esCapicua;
}

int lugar( int num, int pos ){
  return (num / (int)pow(10, pos-1)) % 10;
}
