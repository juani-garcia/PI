#include <stdio.h>
#include <stdlib.h>
#define BLOCK 10
typedef int (*fun) (int) ;

int * interseccion( int * v1, size_t dim1, int * v2, size_t dim2, fun crit, int * newDim );
int belongs( int elem, int * v, int dim );
int esPar( int n );

int main(){
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int u[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int dim;
  int * w = interseccion( v, 10, u, 10, esPar, &dim );
  for( int i = 0; i < dim; i++ )
    printf("%d ", w[i] );
  putchar('\n');
}

int * interseccion( int * v1, size_t dim1, int * v2, size_t dim2, fun crit, int * newDim ){
  int * res = NULL;
  *newDim = 0;
  for( int i = 0; i < dim1; i++ ){
    if( crit(v1[i]) && belongs( v1[i], v2, dim2) ){ // Esta en ambos y cumple --> agrego
      if( *newDim % BLOCK == 0 )
        res = realloc( res, (*newDim + BLOCK) * sizeof(int) );
      res[(*newDim)++] = v1[i];
    }
  }
  res = realloc( res, *newDim * sizeof(int) );
  return res;
}

int belongs( int elem, int * v, int dim ){
  for( int i = 0; i < dim; i++ )
    if( elem == v[i] )
      return 1;
  return 0;
}

int esPar( int n ){
  return n % 2 == 0;
}
