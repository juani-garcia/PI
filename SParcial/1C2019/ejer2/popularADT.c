#include "popularADT.h"
#include <stdlib.h>
#define BLOCK 10

typedef elemType * tVec;

typedef struct popularSetCDT{
  tVec elems;
  size_t size;
  size_t current;
}popularSetCDT;

popularSetADT newPopularSet(){
  return calloc( 1, sizeof(popularSetCDT));
}

size_t add(popularSetADT popularSet, elemType elem){
  for( int i = 0 ; i < popularSet->size; i++ )
    if( compare( popularSet->elems[i], elem) == 0 )
      return 0;
  if( popularSet->size % BLOCK == 0 )// Me estoy quedando sin espacio
    popularSet->elems = realloc( popularSet->elems, (BLOCK + popularSet->size)*sizeof(elemType) );
  popularSet->elems[popoularSet->size] = elem;
  popularSet->size++;
  return 1;
}

size_t size(popularSetADT popularSet){
  return popularSet->size;
}

void toBegin(popularSetADT popularSet){
  popularSet->current = 0;
}

int hasNext(popularSetADT popularSet){
  return popularSet->current < popularSet->size;
}

elemType next(popularSetADT popularSet){
  if( hasNext(popularSet)){
    elemType aux = popularSet->elems[popularSet->current];
    popularSet->current++;
    return aux;
  }
  exit(1);
}

static void swap( elemType * e1, elemType * e2 ){
  elemType aux = *e1;
  *e1 = *e2;
  *e2 = aux;
}

elemType * get(popularSetADT popularSet, elemType elem){
  elemType * copy;
  int i, found = 0; // Guardo el index
  for( i = 0; i < popularSet->size && !found; i++ ){
    if( compare(elem, popularSet->elems[i]) == 0 ) // Lo encontre
      found = 1;
  }
  if( !found )
    return NULL;
  else{
    copy = &popularSet->elems[i];
    if( i > 0 )
      swap( &popularSet->elems[i], &popularSet->elems[i-1]) // Swapeo
    return copy;
  }

}
