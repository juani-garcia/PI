#include <stdio.h>
#include <string.h>
int strend( const char * s, const char * t );

int main(){
  int val = strend("Juajuajuajuajuajuajuas", "jua");
  printf("%d\n", val );
}

int strend( const char * s, const char * t ){
  int lens = strlen(s), lent = strlen(t), flag  = 1;

  if( lens < lent )
    flag = 0;

  while( flag && lent )
    if( *(s + lens--) != *(t + lent--) )
      flag = 0;

  return flag;
}
