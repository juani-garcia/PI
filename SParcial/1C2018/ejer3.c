#include <stdlib.h>
#include <stdio.h>
#define BLOCK 10

typedef int elemType;
typedef elemType * tVec;
typedef int (*pfun) (elemType, elemType);

int cmp( elemType e1, elemType e2 );
elemType * diferencia( const elemType * v1, const elemType * v2, size_t dim1,
                       size_t dim2, int (*cmp) (elemType, elemType),
                       size_t *newDim );

int main(){
  int v1[] = {100, 101, 102, 103};
  int v2[] = {1, 2};
  int dim;
  int * v3 = diferencia( v1, v2, 5, 2, cmp, &dim );
  for( int i = 0; i < dim; i++ )
    printf("%d ", v3[i]);
  putchar('\n');
  free(v3);
}

int cmp( elemType e1, elemType e2 ){
  return e1 - e2;
}

elemType * diferencia( const elemType * v1, const elemType * v2, size_t dim1,
                       size_t dim2, int (*cmp) (elemType, elemType),
                       size_t *newDim ){
  elemType * v3 = NULL;
  *newDim = 0;
  int i = 0, j = 0, c, flag = 1;
  while( i < dim1 ){
    if( *newDim % BLOCK == 0 )
      v3 = realloc( v3, (BLOCK + *newDim) * sizeof(elemType));
    if( j == dim2 ){
      v3[(*newDim++)] = v1[i++];
      flag = 0;
    } //Sabemos de aca en adelante que hay valores de v2
    if( flag ){
      c = cmp( v1[i], v2[j] );
      if( c == 0 ){
        i++; j++;
      }
      else if( c < 0 )
        j++;
      else{
        v3[(*newDim)++] = v1[i++];
      }
    }
  }
  v3 = realloc( v3, *newDim * sizeof( elemType ));
  return v3;
}
