#include "listADT.h"

typedef struct node{
  elemType elem;
  node * tail;
}node;

typedef struct listCDT{
  node * first;
  node * current;
  size_t size;
}listCDT;

static node * addBeforeR( node * list, elemType elem, elemType newElem, int * pude){
  if( list == NULL ){
    return list;
  }
  if( compare(list->elem, elem) == 0 ){ // encontre donde agregar!
    node * new = malloc( sizeof(node) );
    new->elem = newElem;
    new->tail = list;
    *pude = 1;
    return new;
  }
  list->tail = addBeforeR( list->tail, elem, newElem, pude );
  return list;
}

int addBefore( listADT list, elemType elem, elemType new ){
  int pude = 0; // en principio no agrega nada
  list->first = addBeforeR( list->first, elem, new, &pude );
  if( pude )
    list->size++;
  return pude;
}

static node * addAfterR( node * list, elemType elem, elemType newElem, int * pude){
  if( list == NULL ){
    return list;
  }
  if( compare(list->elem, elem) == 0 ){ // encontre donde agregar!
    node * new = malloc( sizeof(node) );
    new->elem = newElem;
    new->tail = list->tail;
    list->tail = new;
    *pude = 1;
    return list;
  }
  list->tail = addAfterR( list->tail, elem, newElem, pude );
  return list;
}

int addAfter( listADT list, elemType elem, elemType new ){
  int pude = 0; // en principio no agrega nada
  list->first = addBeforeR( list->first, elem, new, &pude );
  if( pude )
    list->size++;
  return pude;
}

static node * removeLastR( node * list, elemType elem, int * found ){
  if( list == NULL )
    return list;
  list->tail = removeLastR( list->tail, elem, found );
  if( !(*found) && compare( list->elem, elem) == 0 ){
    node * aux = list->tail;
    free(list);
    *found = 1 // si aparece de nuevo no vuelve a entrar al if
    return aux;
  }
  return list;
}

void removeLast( listADT list, elemType elem ){
  int found = 0;
  list->first = removeLastR( list->first, elem, &found );
}
