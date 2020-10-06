#include "sets.h"

typedef struct node{
  elemType head;
  struct node * tail;
}node;

typedef struct setCDT{
  struct node * first;
}setCDT;

setADT newSet(){
  return calloc( 1, sizeof(setCDT));
}

static void freeRec( node * list ){
  if( list == NULL )
    return;
  freeRec( list->tail );
  freeRec( list );
}

void freeSet( setADT set ){
  freeRec( set->first );
  free( set );
}

static node * addRec( node * list, elemType elem, int * put ){
  if( list == NULL ){
    node * new = malloc( sizeof(node));
    new->head = elem;
    new->tail = NULL;
    *put = 1;
    return new;
  }
  if( list->head == elem )
    return list;
  list->tail = addRec(list->tail, elem, put);
  return list;
}

int add( setADT set, elemType elem ){
  int put = 0;
  set->first = addRec( set->first, elem, &put );
  return put;
}

static node * deleteRec( node * list, elemType elem, int * erased ){
  if( list == NULL )
    return list;
  if( list->head == elem ){
    node * aux = list->tail;
    free( list );
    *erased = 1;
    return aux;
  }
  list->tail = deleteRec( list->tail, elem, erased );
  return list;
}

int delete( setADT set, elemType elem ){
  int erased = 0;
  set->first = deleteRec( set->first, elem, &erased );
  return erased;
}

int isEmpty( setADT set ){
  return set->first == NULL;
}

setADT unionSet( setADT s1, setADT s2 ){
  setADT s3 = newSet();
  node * aux1 = s1->first, * aux2 = s2->first;
  while( aux1 != NULL ){
    add(s3, aux1->head);
    aux1 = aux1->tail;
  }
  while( aux2 != NULL ){
    add(s3, aux2->head);
    aux2 = aux2->tail;
  }
  return s3;
}

int belongs( setADT set, elemType elem ){
  int flag = 0;
  node * aux = set->first;
  while( aux != NULL && !flag ){
    flag = cmp(elem, aux->head) == 0;
    aux = aux->tail;
  }
  return flag;
}

setADT intersection( setADT s1, setADT s2 ){
  setADT s3 = newSet();
  node * aux = s1->first;
  while( aux != NULL ){
    if( belongs( s2, aux->head ))
      add( s3, aux->head );
    aux = aux->tail;
  }
  return s3;
}

setADT substraction( setADT s1, setADT s2 ){
  setADT s3 = newSet();
  node * aux = s1->first;
  while( aux != NULL ){
    if( !belongs( s2, aux->head ))
      add( s3, aux->head );
    aux = aux->tail;
  }
  return s3;
}
