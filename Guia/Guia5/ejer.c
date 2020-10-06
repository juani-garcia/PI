#include <stdio.h>
#include "getnum.h"

double round( double x, int pos ){
  int digit = x * pow(10, pos);
  if (digit < 5)
    return ( (int)(x * pow(10, pos)) / pow(10, pos));
  else
    return ( (int)(x * pow(10, pos)) / pow(10, pos)) + pow(10, -pos);
}

int main(){
  double num = getfloat("Ingrese un numero: ");
  int pos = getint("Ingrese la posicion a redondear: ");
  printf("%.5f\n", round( num, pos ));
}
