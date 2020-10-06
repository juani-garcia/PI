#include <stdio.h>
#include <string.h>

void invertRec( const char * s, char * t, int );
void invert( const char * s, char * t);

int main(){
  char inv[20] = {0};
  invert("PI es muy dificil", inv );
  printf("%s\n", inv );
}

void invertRec( const char * s, char * t, int len ){
  if( *s == 0 )
    return;
  invertRec( s + 1, t, len - 1);
  t[len - 1] = *s;
}

void invert( const char * s, char * t ){
  int len  = strlen(s);
  invertRec( s, t, len );
}
