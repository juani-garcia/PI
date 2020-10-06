#include <stdio.h>
#include <stdlib.h>
char * copiaN( const char* s, int n );

int main(){
  char * t = copiaN("hola como estas", 22 );
  printf("%s\n", t );
  free(t);
}

char * copiaN( const char* s, int n ){
  char * t;
  if( ( t = malloc( n + 1 ) ) == NULL )
    return NULL;
  int i;
  for( i = 0; s[i] && i <= n; i++ )
    t[i] = s[i];
  t[i] = 0;
  t = realloc( t, i );
  return t;
}
