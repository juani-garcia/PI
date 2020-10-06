#include <stdio.h>
#define Mayus 'A'-'a'

int main(){
  printf("Ingrese un caracter: ");
  int a = getchar();
  if (('a'<=a && a<='z'))
    printf("%c\n", a + Mayus);
  else{
    if (('A'<=a && a<='Z'))
      printf("%c\n", a);
    else
      printf("El caracter ingresado no es una letra\n");
  }
}
