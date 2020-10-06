#include <stdio.h>
#include "getnum.h"

int main(){
  int a = getint("Ingrese un entero a: ");
  int b = getint("Ingrese un entero b: ");
  printf("El promedio es %.1f\n", (a + b)/2.0);
  printf("La suma es %d\n", a + b );
  printf("El mayor es %d\n", a > b? a : b);
  printf("El menor es %d\n", a < b? a : b);
  printf("%s", a == b? "Son iguales\n" : "No son iguales\n");
}
