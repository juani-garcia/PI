#include <stdio.h>
#include "random.h"

int eraseRepeat( int v[], int dim, int dest[] ){
  int newDim = 1;
  dest[0] = v[0];
  for( int i = 0; i < dim - 1; i++){
    if( v[i] != v[i+1] )
      dest[newDim++] = v[i + 1];
  }
  return newDim;
}

int main(){
  int v[] = {1, 1, 1, 2, 2, 3, 4, 5, 6, 6, 7, 8, 8, 9, 23, 23, 23, 32};
  int dim = sizeof(v) / sizeof(v[0]);
  int dest[dim];
  int newDim = eraseRepeat( v, dim, dest );
  printVec( dest, newDim );
}
