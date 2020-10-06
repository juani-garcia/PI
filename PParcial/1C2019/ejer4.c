#include <stdio.h>
void corchetes( char * str );

int main(){
    char str[] = "#(Este texto esta entre corchetes#)";
    printf( "%s\n", str );
    corchetes( str );
    printf( "%s\n", str );
}

void corchetes( char * str ){
  int agrego = 0;
  for( int i = 0; str[i]; i++ ){
    if( str[i] == '#' && str[i+1] == '(' ){
      str[agrego++] = '[';
      i++;
    }else if( str[i] == '#' && str[i+1] == ')' ){
      str[agrego++] = ']';
      i++;
    }else
      str[agrego++] = str[i];
  }
  str[agrego] = 0;
}
