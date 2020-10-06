#define isdigit(letra)  (((letra >= 'a') && (letra <= 'z')) || \
                         ((letra >= 'A') && (letra <= 'Z')))
#include <stdio.h>

int main(){
  printf("Ingrese un caracter: ");
  int c = getchar();
  if (isdigit(c))
    printf("Esto es una letra\n");
  else printf("Esto no es una letra\n");
}
