#include <stdio.h>
int pertenece( char c, const char * str );
void elimina( char * str1, const char * str2 );

int main(){
  char str[] = "Este es un string muy bonito. Es casi poetico.";
  elimina( str, "aeiou." );
  printf( "%s\n", str );
}

int pertenece( char c, const char * str ){
  int encontre  = 0;
  for( int i = 0; str[i] && !encontre; i++ )
    if( str[i] == c )
      encontre = 1;
  return encontre;
}

void elimina( char * str1, const char * str2 ){
  int agrego = 0;
  for( int i = 0; str1[i]; i++ )
    if( !pertenece( str1[i], str2 ) )
      str1[agrego++] = str1[i];
  str1[agrego] = 0;
}
