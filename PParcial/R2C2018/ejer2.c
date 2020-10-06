#include <stdio.h>
#include <ctype.h>

int validate( char c, int n );
void eliminaN( char * str, char c, int n );

int main(){
  char str[] = "La calle esta dura";
  eliminaN( str, 'l', 3 );
  printf("%s\n", str );
}

int validate( char c, int n ){
  return( isalpha(c) && n >= 0 );
}

void eliminaN( char * str, char c, int n ){
  if( !validate( c, n ) )
    return;

  int invalido = -1, agrego = 0;
  for( int i = 0; str[i]; i++ ){
    if( i > invalido ){
      if( toupper(str[i]) == toupper( c ) )
        invalido = i + n;
      else
        str[agrego++] = str[i];
    }
  }
  str[agrego] = 0;
}
