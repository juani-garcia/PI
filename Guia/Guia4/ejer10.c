#include <stdio.h>
#include "getnum.h"
#define swap( t, x, y ) { t temp = x; x = y; y = temp; }

int mcd(int a, int b){
  int auxi = 1;
  if( a < b )
    swap(int , a, b)
  while (b){
    auxi = b;
    b = a % b;
    a = auxi;
  }
return a;
}

int main(){
  int a = getint("Ingrese un entero: ");
  int b = getint("Ingrese un entero: ");
  printf("El MCD entre %d y %d es %d\n", a, b, mcd(a, b));
}
