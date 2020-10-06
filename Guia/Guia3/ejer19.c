#include <stdio.h>
#include "getnum.h"

int main(){
  int cant = 0, num, digit;
  num = getint("Ingrese un entero: ");
  for(int i = num; i != 0; i /= 10){
    digit = i % 10;
    if(digit == 5)
      cant++;
  }
  printf("%d tiene %d 5s\n", num, cant);
}
