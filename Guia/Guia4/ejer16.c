#define DIVISOR(a, b)  ( (a) % (b) == 0)
#include <stdio.h>
#include "getnum.h"

int main(){
  int a = getint("Ingrese un entero: ");
  int b = getint("Ingrese un entero: ");
  printf("%d %s es divisor de %d\n", b, DIVISOR(a,b)? "" : "no", a);
}
