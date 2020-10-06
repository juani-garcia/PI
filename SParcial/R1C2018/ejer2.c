#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
typedef elemType* vecType;

int compare( elemType e1, elemType e2 );
void swap( elemType * e1, elemType * e2 );
void ordenar( vecType v, size_t dim );

int main(){
  int v[] = {8, 3, 4, 5, 7, 2, 44, 7, 2};
  for( int i = 0; i < 9; i++ )
    printf("%d %s", v[i], i == 8? "\n" : "" );
  ordenar( v, 9 );
  for( int i = 0; i < 9; i++ )
    printf("%d %s", v[i], i == 8? "\n" : "" );
}

int compare( elemType e1, elemType e2 ){
  if( e1 % 2 == 0 && e2 % 2 == 0 )
    return e1 - e2;
  if( e1 % 2 == 1 && e2 % 2 == 1 )
    return e1 - e2;
  if( e1 % 2 == 0 && e2 % 2 == 1 )
    return -1;
  return 1;
}

void swap( elemType * e1, elemType * e2 ){
  elemType temp = *e2;
  *e2 = *e1;
  *e1 = temp;
}

void ordenar( vecType v, size_t dim ){
  int min; // En min guardo el INDICE del MENOR
  for( int i = 0; i < dim - 1; i++ ){
    min = i;
    for( int j = i + 1; j < dim; j++ ){
      if( compare( v[j], v[min]) < 0 ) // v[j] va antes que v[min]
        min = j;
    }
    swap( &v[i], &v[min] );
  }
}
