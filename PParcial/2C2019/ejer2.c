#include <stdio.h>
void dejaUno( char * str );

int main(){
  char str[] = "aaaaaaabbbbbbbbbbcccccc       c";
  dejaUno( str );
  printf("%s\n", str );
}

void dejaUno( char * str ){
  int agrego = 0;
  for( int i = 0; str[i]; i++ )
    if( str[i] != str[i + 1] )
      str[agrego++] = str[i];
  str[agrego] = 0;
}
