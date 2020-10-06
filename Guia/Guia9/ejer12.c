#include <stdio.h>

int balance( const char * s );

int main(){
  printf("%d\n", balance(")()()()("));
}

int balance( const char * s ){
  if( *s == 0 )
    return 0;
  if( *s == '(' )
    return balance( s + 1 ) + 1;
  if( *s == ')' )
    return balance( s + 1 ) - 1;
  return balance( s + 1 );
}
