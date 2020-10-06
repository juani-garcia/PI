#include <stdio.h>
#include <ctype.h>
#define LETRAS 'Z' -'A' + 1

void imprime( int Mayus[], int Minus[], int reng );
int read( int Mayus[], int Minus[] );

int main(){
  int Mayus[LETRAS] = {0}, Minus[LETRAS] = {0}, reng;
  reng = read( Mayus, Minus );
  putchar('\n');
  imprime( Mayus, Minus, 4 );
}

int read( int Mayus[], int Minus[] ){
  int reng = 0, c;
  while( ( c = getchar()) != EOF ){
    if( isupper(c) )
      Mayus[ c - 'A' ]++;
    if( islower(c) )
      Minus[ c - 'a' ]++;
    if( c == '\n' )
      reng++;
  }
  return (reng + 1);
}

void imprime( int Mayus[], int Minus[], int reng ){
  for( int i = 0; i < LETRAS; i++ )
    if( Mayus[i] + Minus[i] )
      printf("%c: %d (%d / %d)\n", i + 'A', Mayus[i] + Minus[i], Mayus[i], Minus[i]);
  printf( "Renglones: %d\n", reng );
}
