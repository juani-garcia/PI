#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <limits.h>

int main(){
  int bin, digit, dec = 0, flag = 0;
  do { bin = getint("Ingrese un binario: ");
  } while(bin < 0);
  for(int n = 0; bin != 0; bin /= 10, n++){
    digit = bin % 10;
    if(digit != 0 && digit != 1){
      printf("El entero ingresado no representa un numero binario\n");
      flag = 1;
      break;
    }
    dec += digit * pow(2,n);
  }
  if(flag != 1)
  printf("El binario ingresado equivale a %d en decimal\n", dec);
}
