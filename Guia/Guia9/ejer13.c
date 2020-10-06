#include <stdio.h>

int balance( const char * s );

int main(){
  printf("%d\n", balance("((()()())()()"));
}

int balance( const char * s ){
  if( *s == 0 ) return 0;
  int siguiente = balance( s + 1 );
  if( *s == ')' )
    return siguiente > 0? siguiente : siguiente - 1;
  else
    return siguiente + 1;
}
