#include <stdio.h>
#include <string.h>

int esPalindromo( const char * s );
static int esPRec( const char * s, int len );

int main(){
  printf("%d\n", esPalindromo("suguz"));
}

int esPalindromo( const char * s ){
  int len  = strlen(s), res;
  res = esPRec( s, len );
  return res;
}

int esPRec( const char * s, int len ){
  if( len == 0 )
    return 1;
  if( len == 1 )
    return 1;
  return ( s[0] == s[len - 1] ) && esPRec( s + 1, len -2 );
}
