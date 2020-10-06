#include <ctype.h>
#include <stdio.h>

int bienFormado( const char * s );

int main(){
  printf("%d\n", bienFormado("hola4como4estas5"));
}

int bienFormado( const char * s ){
  if( *s == 0 )
    return 0;
  int partial = bienFormado( s + 1 );
  if( isdigit(*s) )
    return partial == 0? *s - '0' : -1;
  if( isalpha(*s) )
    return partial <= 0? -1 : partial - 1;
  return -1;
}
