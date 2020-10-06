#include <stdio.h>
#include "getnum.h"

int divisorSum( int n ){
  int sum = 0;
  for( int i = 1; i < (n / 2) + 1; i++)
    if( n % i == 0 )
      sum += i;
  return sum;
}

int amigos( int num1, int num2 ){
  if ( divisorSum(num1) == num2 && divisorSum(num2) == num1 )
    return 1;
  else
    return 0;
}


int main(){
  int a = getint("Ingresar entero: ");
  int b = getint("Ingresar entero: ");
  printf("%d\n", amigos(a, b));
}
