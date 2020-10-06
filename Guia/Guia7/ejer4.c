#include <stdio.h>
#include <ctype.h>
#include "random.h"
#define LETRAS 'z' - 'a' + 1

void crearAlfabeto( char * clave );
void codificar( const char * clave, char * msj );
void decodificar( const char * clave, char * msj );
int buscar( char c, const char * clave );

int main(){
  randomize();
  char clave[LETRAS + 1];
  char msj[] = "Hola como estas?";
  crearAlfabeto( clave );
  printf("%d\n", buscar('A', clave ) );
  clave[ LETRAS ] = 0;
  codificar( clave, msj );
  printf("%s\n%s\n", clave, msj );
  decodificar( clave, msj );
  printf("%s\n", msj );
}

void crearAlfabeto( char * clave ){
  int r, aux;
  for( int i = 0; i < LETRAS; i++ ){
    clave[i] = 'A' + i;
    r = randInt(0, i);
    aux = clave[r];
    clave[r] = clave[i];
    clave[i] = aux;
  }
}

int buscar( char c, const char * clave ){
  if( !isalpha( c = toupper(c) ) ){
    return -1;
  }
  int i = 0;
  while( c != clave[i++] );
  return i - 1;
}

void codificar( const char * clave, char * msj ){
  for( int i = 0; *(msj + i); i++ )
    if( isalpha( *(msj + i ) ) )
      *(msj + i) = *( clave + toupper( *( msj + i ) ) - 'A' ) ;
}

void decodificar( const char * clave, char * msj ){
  for( int i = 0; msj[i]; i++ )
    if( isalpha(msj[i]) )
      msj[i] = 'A' + buscar( msj[i], clave );
}
