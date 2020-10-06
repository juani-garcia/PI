#include <stdio.h>
#define TO_LOWER( c ) c = ( ( c >= 'A' && c <= 'Z')? c -'A' + 'a' : c )

int main(){
  char c = 'A';
  putchar( TO_LOWER(c) );
  putchar(' ');
  putchar( TO_LOWER(c) );
  putchar('\n');
}
