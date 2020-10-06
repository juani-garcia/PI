#include <stdio.h>

int main(){
  int edad = 25;
  float longitud = 185.654;
  char letra = 'Z';

  printf("Edad = %-5d\n", edad);
  printf("Edad = %10d\n", edad);
  printf("Long = %-10.2f\n", longitud);
  printf("El ascii de Z = %8d\n", letra);
  printf("El ascii de z = %8d\n", letra + 'a'-'A');

}
