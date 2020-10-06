#include <stdio.h>

int sumaPos( int n );

int main(){
  printf("%d\n", sumaPos(123456789) );
}

int sumaPos( int n ){
  if( !n )
    return 0;
  return ( n % 10 ) + sumaPos( n / 10 );
}
