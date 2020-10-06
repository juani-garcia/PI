#include <stdio.h>
#include "getnum.h"

int main(){
  int a ,b;
  a = getint("Ingrese un entero a: ");
  b = getint("Ingrese un entero b: ");
  printf("%d %ses un multiplo de %d\n", a, (a%b == 0? "" : "no "), b);
}
