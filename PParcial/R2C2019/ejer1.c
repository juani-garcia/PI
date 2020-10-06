#include <stdio.h>
int pertenece( char c, const char * str );
void elimina( char * str );

int main(){
  char str[] = "1234567890987654321";
  elimina( str );
  printf("%s\n", str );
}

int pertenece( char c, const char * str ){
  int esta = 0;
  for( int i = 0; str[i] && !esta; i++ )
    if( str[i] == c )
      esta = 1;
  return esta;
}

void elimina( char * str ){
  int agrego = 0;
  for( int i = 0; str[i]; i++ ){
    if( !pertenece( str[i], str + i + 1 ) )
      str[agrego++] = str[i];
  }
  str[agrego] = 0;
}
