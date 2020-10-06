#include <stdio.h>

int ack( int m, int n );

int main(){
  printf("%d\n", ack(2, 10));
}

int ack( int m, int n ){
  if( !m )
    return n + 1;
  else if( !n )
    return ack( m - 1, 1 );
  else
    return ack( m - 1, ack( m, n - 1 ) );
}
