#include <stdlib.h>
#include "moveToFrontADT.h"

typedef struct node{
  elemType elem;
  struct node * tail;
}node;

typedef struct moveToFrontCDT{
  node * first;
  node * current;
  size_t size;
}moveToFrontCDT;

moveToFrontADT newMoveToFront(){
  return calloc( 1, sizeof(moveToFrontCDT));
}

static node * addRec( node * list, elemType elem, int * agrego ){
  if( list == NULL ){
    node * new = malloc( sizeof(node) );
    new->elem = elem;
    new->tail = NULL;
    *agrego = 1; // Actualizo el puntero para aumentar el size
    return new;
  }
  if( compare(elem, list->elem) == 0 ) // Esta repetido
    return list;
  list->tail = addRec( list->tail, elem, agrego );
  return list;
}

size_t add(moveToFrontADT moveToFront, elemType elem){
  int agrego = 0; // En principio no agrego nada
  moveToFront->first = addRec( moveToFront->first, elem, &agrego );
  moveToFront->size += agrego;
  return agrego;
}

size_t size(moveToFrontADT moveToFront){
  return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront){
  moveToFront->current = moveToFront->first;
}

int hasNext(moveToFrontADT moveToFront){
  moveToFront->current != NULL;
}

elemType next(moveToFrontADT moveToFront){
  if( hasNext(moveToFront) ){
    elemType aux = moveToFront->current->elem;
    moveToFront->current = moveToFront->current->tail;
    return aux;
  }
  exit(1);
}

static node * getRec( node * list, elemType elem, node ** donde, int * found ){
  if( list == NULL || list->tail == NULL )
    return list;
  if( compare(list->tail->elem, elem) == 0){
    *donde = list->tail; // Quiero en donde el sig de donde estoy parado
    *found = 1; // Lo encontre
    list->tail = list->tail->tail // Salteo el nodo que guarde
    return list;
  }
  list->tail = getRec( list->tail, elem, donde, found );
  return list;
}

elemType * get(moveToFrontADT moveToFront, elemType elem){
  elemType * copy;
  int found = 0; // En principio no esta
  moveToFront->first = getRec( moveToFirst->first, elem, &donde, &found )
  if( found = 1 ){
    copy = malloc( sizeof(elemType) );
    *copy = donde->elem;
    donde->tail = moveToFirst->first;
    moveToFirst->first = donde;
  }else{
    if( moveToFirst->size == 1 ){ // Hay uno solo, devuelvo ese
      copy = malloc( sizeof(elemType) );
      *copy = moveToFirst->elem;
    }else
      copy = NULL;
  }
  return copy;
}
