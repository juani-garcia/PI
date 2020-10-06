#include <stdio.h>

int bs( int * v, int dim, int n );

int main(){
  int v[] = {1, 2, 3, 4, 5, 6};
  printf("%d\n", bs( v, 6, 323 ));
}

int bs( int * v, int dim, int n ){
  int med = ( dim + 1 ) / 2;
  if( med == 0 )
    return 0;
  else if ( v[med - 1] == n )
    return 1;
  else if( v[med - 1] > n )
    return bs( v + med + 1, med  - 1, n );
  else
    return bs( v, med  - 1, n );
}
