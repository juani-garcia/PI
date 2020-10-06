#include <stdio.h>
#include "getnum.h"
int main(){
  int lado = getint("Ingrese un entero: ");
  int count1 = 0;
  while(count1 < lado){
    int count2 = 0;
    while(count2 < lado){
      printf(" * ");
      count2++;
    }
    printf("\n");
    count1++;
  }
}
