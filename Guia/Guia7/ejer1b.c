#include <stdio.h>
char * strncpy( char s[], const char * t, int n );

int main(){
  char s[] = "Hola como estas?";
  char *t = strncpy(s, "1234567", 4 );
  printf("%s\n", t);
}

char * strncpy( char s[], const char * t, int n ){
  char * aux = s;
  while( * t && n-- ){
    *(s++) = *(t++);
  }
  *(s) = 0;
  return aux;
}
