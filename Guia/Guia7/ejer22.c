#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK 10
char ** aprobados( char nombres[][10], int * notas );
void libera( char** aprob );

int main(){
  char nombres[][10] = {"Juan", "Jorge", "Agus", "Fini", ""};
  int notas[] = { 7, 3, 6, 8 };
  char ** aprob = aprobados( nombres, notas );
  for( int i = 0; *aprob[i]; i++ )
    printf("%s\n", aprob[i] );
  libera( aprob );
}

char ** aprobados( char nombres[][10], int * notas ){
  char ** arr = NULL;
  int cant = 0;
  for( int i = 0; *nombres[i]; i++ ){
    if( cant % BLOCK == 0 )
      arr = realloc( arr, BLOCK * sizeof(char*));
    if( notas[i] >= 4 ){
      arr[cant] = malloc( strlen(nombres[i]) + 1 );
      strcpy( arr[cant++], nombres[i] );
    }
  }
  arr = realloc( arr, ( cant + 1 )* sizeof(char*));
  arr[cant] = "";
  return arr;
}

void libera( char** aprob ){
  for( int i = 0; *aprob[i]; i++ )
    free(aprob[i]);
  free(aprob);
}
