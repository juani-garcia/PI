#include <stdio.h>
#include "random.h"

int intersect( int v1[], int dim1, int v2[], int dim2, int res[]){
  int iguales = 0, newDim = 0;
  for( int i = 0; i < dim1; i++, iguales = 0 ){
    for( int j = 0; j < dim2; j++ )
      if( v1[i] == v2[j] && !iguales ){
        iguales = 1;
      }
    if( iguales )
      res[newDim++] = v1[i];
  }
  return newDim;
}

int intrOrd( int v1[], int dim1, int v2[], int dim2, int res[]){
  
}

int main(){
  int v1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int v2[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
  int intr[100] ;
  int dim = intersect( v1, 10, v2, 10, intr);
  printVec( intr, dim );
}
