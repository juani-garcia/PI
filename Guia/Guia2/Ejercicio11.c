#include <stdio.h>

int main(){
  int a, b;
  a = getchar();
  b = getchar();
  printf("El mayor ascii es de %c\n", (a>b? a : b));
}
