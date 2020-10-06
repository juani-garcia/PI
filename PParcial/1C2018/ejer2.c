#include <stdio.h>
#include <ctype.h>
#define LETRAS ( 'Z' - 'A' + 1 )

void letras( const char * input, char * outuput );
void crearString( int abc[], char * output );

int main(){
  char * str = "Abracadabra pata de cabra";
  char output[LETRAS + 1];
  letras( str, output );
  printf("%s\n", output );
}

void letras( const char * input, char * output ){
  int abc[LETRAS] = {0};
  for( int i = 0; input[i]; i++ ){
    char c = toupper( input[i] );
    if( isalpha(c) )
      abc[ c- 'A' ] = 1;
  }
  crearString( abc, output );
}

void crearString( int abc[], char * output ){
  int agrego = 0;
  for( int i = 0; i < LETRAS; i++ )
    if( abc[i] )
      output[agrego++] = 'A' + i;
  output[agrego] = 0;
}
