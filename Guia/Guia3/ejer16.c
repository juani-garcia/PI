#include <stdio.h>
#include "getnum.h"
#include <math.h>

int main(){
  int dec = 0, bin;
  do{
  bin = getint("Ingrese un entero positivo entre 0 y 1024: ");
  }while(bin < 0 || bin > 1023);
  for(int i = 0; bin != 0; bin /= 2, i++){
    if(bin % 2 != 0)
      dec += pow(10,i);
  }
  printf("Equivale a %d en binario\n", dec);
}
