#include <stdlib.h>
#include "multiADT.h"

typedef struct node{
  elemType elem;
  size_t amount;
  struct node * tail;
}node;

typedef struct multiSetCDT{
  node * first;
  node * mostRep;
  size_t size;
}multiSetCDT;

multiSetADT newMultiSet(){
  return calloc( 1, multiSetCDT );
}

static node * addRec( node * list, elemType elem, int * cant, node ** donde ){
  int c;
  if( list == NULL || ( c = compare( elem, list->elem )) < 0 ){
    node * new = malloc( sizeof(node) );
    new->elem  = elem;
    new->amount = *cant = 1;
    new->tail = list;
    *donde = new;
    return new;
  }
  if( c == 0 ){
    *cant = ++list->amount;
    *donde = list;
    return list;
  }
  list->tail = addRec( list->tail, elem, cant, donde );
  return list;
}

size_t add( multiSet set, elemType elem ){
  int cant;
  node * donde;
  set->first = add( set->first, elem, &cant, &donde );
  if( cant == 1 ) // si agregaste un nodo, hay que actualizar el size_t
    set->size++;
  if( cant == 1 && set->mostRep == NULL )
    set->mostRep = donde;
  else if( cant > set->mostRep->amount )
    set->mostRep = donde;
  return cant;
}

size_t count (const multiSetADT set, elemType elem){
  node * aux = set->first;
  while( aux != NULL ){
    if( compare( elem, aux->elem ) == 0 )
      return aux->amount;
    aux = aux->tail;
  }
  return 0;
}

size_t size (const multiSetADT set){
  return set->size;
}

elemType maxElement (const multiSetADT set){
  return set->mostRep->elem;
}

elemType * values (const multiSetADT set){
  elemType * v = malloc( set->size * sizeof(elemType) );
  node * aux = set->first;
  int i = 0;
  while( aux != NULL ){
    v[i++] = aux->elem;
    aux = aux->tail;
  }
  return v;
}
