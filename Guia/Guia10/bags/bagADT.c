#include "bagADT.h"

typedef struct node{
  elemType elem;
  size_t cant;
  struct node * tail;
}node;

typedef struct bagCDT{
  node * first;
}bagCDT;

bagADT newBag(){
  return calloc(1, sizeof(bagCDT));
}

static void freeRec( node * list ){
  if( list == NULL )
    return;
  freeRec( list->tail );
  free( list );
}

void freeBag( bagADT bag ){
  freeRec( bag->first );
  free(bag);
}

node * addRec( node * list, elemType elem, size_t * cant ){
  if( list == NULL ){
    node * new = malloc(sizeof(node) );
    new->elem = elem;
    new->cant = *cant = 1;
    new->tail = NULL;
    return new;
  }
  if( cmp(elem, list->elem) == 0 ){
    (list->cant)++;
    *cant = list->cant;
    return list;
  }
  list->tail = addRec(list->tail, elem, cant );
  return list;
}

size_t add( bagADT bag, elemType elem ){
  size_t cant;
  bag->first = addRec( bag->first, elem, &cant );
  return cant;
}

size_t countRec( node * list, elemType elem ){
  if( list == NULL )
    return 0;
  if( cmp(list->elem, elem) == 0 )
    return list->cant;
  return countRec( list->tail, elem );
}

size_t count(const bagADT bag, elemType elem){
  return countRec( bag->first, elem );
}

static size_t sizeRec( node * list ){
  if( list == NULL )
    return 0;
  else return 1 + sizeRec( list->tail );
}

size_t size(const bagADT bag){
  return sizeRec( bag->first );
}

elemType mostPopular( bagADT bag ){
  node * it = bag->first, * max = bag->first;
  while( it != NULL ){
    if( it->cant > max->cant ){
      max = it;
    }
    it = it->tail;
  }
  return max->elem;
}
