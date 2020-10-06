#include "multiADT.h"
#define ALL 1
#define BLOCK 10

typedef struct node{
  elemType elem;
  size_t cant;
  struct node * tail;
}node;

typedef struct multiSetCDT{
  node * first;
  size_t size;
}multiSetCDT;

multiSetADT newMultiSet(){
  return calloc( 1, sizeof(multiSetCDT));
}

static node * addRec( node * list, elemType elem, int * cant){
  int c;
  if( list == NULL || ( c = compare( elem, list->elem )) < 0 ){
    node * new = malloc( sizeof(node) );
    new->elem = elem;
    new->cant = 1;
    new->tail = list;
    return new;
  }
  if( c == 0 ){
    *cant = ++list->cant;
    return list;
  }
  list->tail = addRec( list->tail, elem, cant );
  return list;
}

size_t add( multiSetADT set, elemType elem ){
  int cant = 1;
  set->first = addRec( set->first, elem, &cant );
  if( cant == 1 )
    set->size++;
  return cant;
}

size_t count(const multiSetADT set, elemType elem){
  node * aux = set->first;
  while( aux != NULL ){
    if( aux->elem == elem )
      return aux->cant;
    aux = aux->tail;
  }
  return 0;
}

size_t size(const multiSetADT set ){
  return set->size;
}

static node * removeRec( node * list, elemType elem, int * cant, int all ){
  if( list == NULL )
    return list;
  if( compare(list->elem, elem) == 0){
    if( list->cant == 1 || all ){ // hay que borrar el nodo
      node * aux = list->tail;
      free(list);
      *cant = 0;
      return aux;
    }else{ // solo decremento la cantidad
      *cant = --list->cant;
      return list;
    }
  }
  list->tail = removeRec( list->tail, elem, cant, all );
  return list;
}

int removeElem(multiSetADT set, elemType elem){
  int cant = -1;
  set->first = removeRec( set->first, elem, &cant, !ALL );
  if( cant == 0 ) // removio el ultimo elem, tiene que bajar el size
    set->size--;
  if( cant == -1 ) // no encontro elem
    return 0;
  return cant;
}

void removeAll(multiSetADT set, elemType elem){
  int cant = -1;
  set->first = removeRec( set->first, elem, &cant, ALL );
  if( cant == 0 )
    set->size--;
}

elemType * minElements(const multiSetADT set, int * dim){
  elemType * v = NULL;
  node * aux = set->first;
  int max = 0;
  while( aux != NULL ){ // hallo la CANTIDAD del elemento mas repetido
    if( aux->cant > max )
      max = aux->cant;
    aux = aux->tail;
  }
  int i = 0;
  aux = set->first;
  while( aux != NULL ){
    if( aux->cant < max ){
      if( i % BLOCK == 0 ){
        v = realloc( v, (i + BLOCK) * sizeof(elemType));
      }
      v[i++] = aux->elem;
    }
    aux = aux->tail;
  }
  v = realloc( v, i * sizeof(elemType));
  *dim = i;
  return v;
}
