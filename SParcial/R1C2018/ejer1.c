#include <stdio.h>
int orden( int * v, size_t dim );

int main(){
  int v1[] = {1, 2, 3, 4, 5};
  int v2[] = {5, 4, 3, 2, 1};
  int v3[] = {1, 4, 2, 2, 5};
  printf("%d %d %d\n", orden(v1, 5), orden(v2, 5), orden(v3, 5));
}

int orden( int * v, size_t dim ){
  if( dim == 0 || dim == 1 )
    return 0;
  if( dim == 2 ){
    if( v[0] < v[1])
      return 1;
    if( v[0] > v[1])
      return -1;
    return 0;
  }
  int ord = orden( v + 1, dim - 1 );
  if( v[0] < v[1] )
    return ord == 1? ord : 0;
  if( v[0] > v[1] )
    return ord == -1? ord : 0;
  return 0;
}
