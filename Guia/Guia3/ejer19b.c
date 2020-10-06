#include <stdio.h>
#include "getnum.h"
#define delta 0.000000001

int main(){
  double num = getdouble("Ingrese un numero: "), real;
  int cant = 0, nat;
  nat = (int) num;
  real = num - nat;

  for(int i = nat; i != 0; i /= 10){
    if( i % 10 == 5)
      cant++;
  }
  for(float j = real; j > delta; j *= 10, j = j - (int)(j)){
    if((int)(j*10) == 5)
      cant++;
  }

  printf("%d\n", cant);
}
