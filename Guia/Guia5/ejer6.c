#include <stdio.h>
#include "getnum.h"

int toLower( int c ){
  if ( c >= 'A' && c <= 'Z') return c - 'A' + 'a';
  else return c;
}

int toUpper( int c ){
  if ( c >= 'a' && c <= 'z') return c - 'a' + 'A';
  else return c;
}

int next( int c ){
  return c + 1 ;
}

int circle( int c ){
  if( c == 'Z' ) return 'A';
  if( c == 'z' ) return 'a';
  if( (c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z' )) return c+1;
  else return c;

}

int main(){
  printf("Ingrese un caracter: ");
  int c = getchar();
  printf("Que desea hacer? Presione 1 para pasarlo a minuscula, 2\n");
  printf("para pasarlo a mayuscula, 3 para imprimir el siguiente \n");
  printf("caracter o 4 para imprimir el siguiente en forma circular\n");
  int opt;
  do{
  opt = getint("");
  } while ( opt < 1 || opt > 4);
  switch (opt){
    case 1:
      putchar(toLower(c)); break;
    case 2:
      putchar(toUpper(c)); break;
    case 3:
      putchar(next(c)); break;
    case 4:
      putchar(circle(c));
  }
  putchar('\n');
}
