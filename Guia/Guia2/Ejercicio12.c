#include <stdio.h>

int main(){
  printf("Ingrese un caracter: ");
  int a = getchar();
  printf("El caracter %c %ses una letra\n", a, (('a'<=a && a<='z') || ('A'<=a && a<='Z'))? "" : "no ");
}
