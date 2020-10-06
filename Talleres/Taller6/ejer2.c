#include <stdio.h>
#include <stdlib.h>
#define BLOCK 10

char * supervector();

int main(){
  char * str;
  str = supervector();
  printf("\nEscribiste: ");
  printf("%s\n", str );
  free(str);
}

char * supervector(){
  printf("Escriba un string de cualquier tamanio: \n");
  char * str; int c, i = 0;
  str = NULL;
  while( (c = getchar() ) != EOF ){
    if( i % BLOCK == 0 )
      str = realloc( str, i + BLOCK );
    str[i++] = c;
  }
  str = realloc( str, i + 1 );
  str[i] = 0;
  return str;
}
