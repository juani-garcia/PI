#include <stdio.h>
#include "getnum.h"

int main(){
  int a = getint("Ingrese un entero: ");
  printf("%d\n", a>>1);
}
