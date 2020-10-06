#include <stdio.h>
#include <ctype.h>
#define LETRAS 'Z' - 'A' + 2
int leer( int Mayus[], int Minus[] );
void imprimir( int Mayus[], int Minus[], int noLetra);

int main(){
  int Mayus[LETRAS] = {0};
  int Minus[LETRAS] = {0};
  int noLetra = leer( Mayus, Minus );
  imprimir( Mayus, Minus, noLetra );
}

int leer( int Mayus[], int Minus[] ){
  int c, noLetra = 0;
  while( (c = getchar() ) != EOF ){
    if( islower(c) ){
      Minus[ c - 'a' ]++;
      Minus[ LETRAS - 1 ]++;
    }else if( isupper(c) ){
      Mayus[ c - 'A' ]++;
      Mayus[ LETRAS - 1 ]++;
    }else
      noLetra++;
  }
  return noLetra;
}

void imprimir( int Mayus[], int Minus[], int noLetra){
  putchar('\n');
  printf("Habia %d letras\n", Mayus[ LETRAS - 1 ] + Minus[ LETRAS - 1 ] );
  printf("De las cuales %d eran M y %d eran m\n", Mayus[LETRAS - 1], Minus[LETRAS - 1] );
  printf("%d caracteres no eran letras\n", noLetra );
  for( int i = 0; i < LETRAS - 1; i++ )
    if( Mayus[i] + Minus[i] )
      printf("La %c aparecio %d veces\n", 'A' + i, Mayus[i] + Minus[i] );
  putchar('\n');
}
