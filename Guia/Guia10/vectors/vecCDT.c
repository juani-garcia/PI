#include "vecADT.h"

typedef struct vecCDT{
  elemType * elems;
  char * occ;
  size_t size;
}vecCDT;

vecADT newVector(){
  return calloc( 1, sizeof(vecCDT) );
}

void freeVector( vecADT v ){
  free( v->elems );
  free( v->occ );
  free(v);
}

int put(vecADT v, elemType * elems, size_t dim, size_t index){
  if( v->size <= index + dim ){
    v->elems = realloc( v->elems, (index + dim) * sizeof(elemType ));
    v->occ = realloc( v->occ, (index + dim) * sizeof( char ));
    for( int i = v->size; i < index + dim; i++ )
      v->occ[i] = 0;
    v->size = index + dim;
  }
  int cant;
  for( int i = index, j = 0; j < dim; i++, j++ ){
    if( v->occ[i] == 0 ){
      v->elems[i] = elems[j];
      cant++;
    }
  }
  return cant;
}

int getIdx( vecADT v, elemType elem ){
  for( int i = 0; i < v->size; i++ )
    if( v->elems[i] == elem )
      return i;
  return -1;
}
