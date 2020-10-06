#include <stdio.h>
#include "getnum.h"


int main(){
  do{
  double b = getfloat("Inserte un numero: ");
  } while ( b <= 0);
  unsigned a = b;
  int digit, sum;
  digit = sum = 0;
  for (; a != 0; a/=10){
    digit = a%10;
    sum += digit;
  }
  printf("La suma de digitos enteros es %d\n", sum);
}
