#include <stdio.h>
#include "random.h"
#define DIM 100

int eraseRep( int v[], int dim, int dest[] ){
  int newDim = 0, flag = 1;
  for( int i = 0; i < dim; i++, flag = 1){
    for( int j = 0; j < newDim; j++)
      if( v[i] == dest[j] ){
        flag = 0;
        break;
      }
    if( flag ){
      dest[newDim++] = v[i];
    }
  }
  return newDim;
}

int main(){
  int v[] = {1, 2, 3, 4, 2, 3, 4, 1, 5, 2};
  int dim = sizeof(v)/sizeof(v[0]);
  int dest[dim];
  int newDim = eraseRep( v, dim, dest);
  printVec( dest, newDim);

}
