#include <stdio.h>
#include "getnum.h"

int digitSum(unsigned a){
  for (int digit, sum = 0; a != 0; a/10){
    digit = a%10;
    sum += digit;
  }
  return sum
}

int main(){
  unsigned a = abs(getint("Inserte un entero positivo: "));
  printf("La suma de digitos de %d es %d", a, digitSum(a));
}
