#include <stdio.h>
#include "getnum.h"
int main(){
  int lado = getint("Ingrese un entero: ");
  for(int count = 1; count <= lado*lado; count++){
    if(count%lado == 0)
      printf(" *\n");
    else
      printf(" * ");
  }
}
