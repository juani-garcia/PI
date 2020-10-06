#include <ctype.h>
#include <stdio.h>
#define VOC 5
#define EXITO 0
#define ERROR 1

int eliminaVoc( char str[], int vocales[][VOC], int n );
int vocNum( char c );

int main(){
  char str[] = "las buenas ideas escasean";
  int vocales[20][VOC];
  int out = eliminaVoc( str, vocales, 5 );
  printf("%d %s\n", out, str );
}

int eliminaVoc( char str[], int vocales[][VOC], int n ){
  int count[VOC] = {0}, flag = EXITO, agrego = 0, i = 0, vocal;
  for(; str[i] && !flag; i++ ){
    vocal = vocNum( str[i] );
    if( !(vocal + 1 ) )
      str[agrego++] = str[i];
    else{
      if( count[vocal] < n - 1 )
        vocales[count[vocal]++][vocal] = i;
      else{
        flag = ERROR;
        i--;
      }
    }
  }
  for(; str[i]; i++ )
    str[agrego++] = str[i];
  str[agrego] = 0;

  for( int j = 0; j < VOC; j++ )
    vocales[count[j]][j] = -1;

  return flag;
}


int vocNum( char c ){
  switch( toupper(c) ){
    case 'A':
      return 0;
    case 'E':
      return 1;
    case 'I':
      return 2;
    case 'O':
      return 3;
    case 'U':
      return 4;
    default:
      return -1;
  }
}
