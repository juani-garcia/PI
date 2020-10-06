#include <stdio.h>

int sumaVec( int * v, int dim );

int main(){
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("%d\n", sumaVec( v, sizeof(v) / sizeof(v[0])));
}

int sumaVec( int * v, int dim ){
  if( !dim )
    return 0;
  return *v + sumaVec( v + 1, dim - 1);
}
