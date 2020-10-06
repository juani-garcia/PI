#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getnum.h"
#include "random.h"
#define CANT 4
#define MAX_INT 10
#define CLEAN while( getchar() != '\n' )

int dificultad();
int jugar( char * miPalabra, char * incognita, int intentos, int len );
char * elegirPalabra( char * palabrasGuardadas[] );
char leerIntento();
void mostrarPalabra( char * miPalabra, int len );
int pertenece( char intento, char * incognita, char * miPalabra );

int main(){
  randomize();
  char * palabrasGuardadas[CANT] = {"LATA", "REGLA", "LAPICERA", "ZAPATILLA"};
  char * incognita = elegirPalabra( palabrasGuardadas );
  int len = strlen( incognita );
  char * miPalabra = calloc( len , sizeof(char) );
  int intentos = dificultad();
  int resultado = jugar( miPalabra, incognita, intentos, len );
  if( resultado )
    printf("Ganaste!\n");
  else
    printf("Lo lamento, la palabra era %s\n", incognita );
}

char * elegirPalabra( char * palabrasGuardadas[] ){
  int r = randInt(0, CANT - 1);
  return palabrasGuardadas[r];
}

void mostrarPalabra( char * miPalabra, int len ){
  for( int i = 0; i < len; i++ ){
    if( !miPalabra[i] )
      putchar( '-' );
    else
      putchar( miPalabra[i] );
  }
  putchar('\n');
}

char leerIntento(){
  char c;
  do{
    printf("Ingrese una letra: ");
    c = toupper(getchar());
    CLEAN;
  }while( !isupper(c) );
  return c;
}

int pertenece( char intento, char * incognita, char * miPalabra ){
  int coincidencias = 0;
  for( int i = 0; incognita[i]; i++ )
    if( intento == incognita[i] ){
      miPalabra[i] = intento;
      coincidencias++;
    }
  return coincidencias;
}

int dificultad(){
  int intentos;
  do{
    intentos = getint("Ingrese el nivel de dificultad: " );
  }while( intentos < 1 || intentos > MAX_INT );
  return intentos;
}

int jugar( char * miPalabra, char * incognita, int intentos, int len ){
  int aciertos = 0, esta;
  char c;
  printf("Comenecemos! ");
  while( intentos && aciertos != len ){
    printf("Te quedan %d intentos\n", intentos );
    mostrarPalabra( miPalabra, len );
    c = leerIntento();
    esta = pertenece( c, incognita, miPalabra );
    if( esta ){
      aciertos += esta;
      printf("Correct!\n");
    }else{
      intentos--;
      printf("Error!\n");
    }
  }
  return ( aciertos == len );
}
