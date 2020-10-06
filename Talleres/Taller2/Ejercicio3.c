#include <stdio.h>
#include "getnum.h"


int main(){
  unsigned a = abs(getint("Inserte un entero positivo: "));
  int digit, sum;
  digit = sum = 0;
  for (; a != 0; a/=10){
    digit = a%10;
    sum += digit;
  }
  printf("La suma de digitos es %d\n", sum);
}
