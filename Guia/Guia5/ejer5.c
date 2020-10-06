#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#define EPSILON 0.0001

double potencia ( double base, int exp ){
  if( (base < EPSILON && base > -EPSILON) && exp == 0)
    return -1;

  long accum = 1;
  for( int i = 0; i < abs(exp); i++)
    accum *= base;

  if ( exp < 0 ) return 1.0 / accum;
  else return accum;
}

int main(){
  double base = getfloat("Ingrese una base:");
  int exp = getint("Ingrese un exponente:");
  printf("%.3f^%d = %.10f\n", base, exp , potencia (base, exp));
}
