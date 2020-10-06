#include <stdio.h>

int dot( int * v1, int *v2, int dim );

int main(){
  int v1[] = {3, 2, 1 };
  int v2[] = {1, 7, 3};
  printf("%d\n", dot( v1, v2, 3 ));
}

int dot( int * v1, int *v2, int dim ){
  if( !dim )
    return 0;
  return *v1 * *v2 + dot( v1 + 1, v2 + 1, dim - 1 );
}
