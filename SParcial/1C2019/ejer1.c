#include <stdio.h>
#include <stdlib.h>

typedef struct tNode * tList;

typedef struct tNode{
  int elem;
  struct tNode * tail;
}tNode;

tList removeOdd( tList list );
tList removeRepeated( tList list );
tList add( tList list, int elem );

int main(){
  tList l = NULL, aux;
  l = add( l, 1 );
  l = add( l, 1 );
  l = add( l, 1 );
  l = add( l, 3 );
  l = add( l, 4 );
  l = add( l, 1 );
  l = add( l, 5 );
  l = add( l, 6 );
  l = add( l, 5 );
  l = add( l, 7 );
  l = add( l, 5 );
  aux = l;
  while( aux != NULL ){
    printf("%d->", aux->elem );
    aux = aux->tail;
  }
  printf("NULL\n");
  l = removeRepeated( l );
  aux = l;
  while( aux != NULL ){
    printf("%d->", aux->elem );
    aux = aux->tail;
  }
  printf("NULL\n");
  l = removeOdd( l );
  aux = l;
  while( aux != NULL ){
    printf("%d->", aux->elem );
    aux = aux->tail;
  }
  printf("NULL\n");
}

tList removeOdd( tList list ){
  if( list == NULL || list->tail == NULL )
    return list;
  tList aux = list->tail->tail; // Me quedo con el prox del prox
  free( list->tail );
  list->tail = aux;
  list->tail = removeOdd( list->tail );
  return list;
}

tList removeRepeated( tList list ){
  if( list == NULL || list->tail == NULL ) // Esta vacia o llegue al final
    return list;
  if( list->elem == list->tail->elem ){ // Nodo repetido, lo saco
    tList aux = list->tail;
    free( list );
    aux = removeRepeated( aux );
    return aux;
  }
  list->tail = removeRepeated( list->tail );
  return list;
}

tList add( tList list, int elem ){
  if( list == NULL || elem < list->elem ){
    tList new = malloc( sizeof(tNode) );
    new->elem = elem;
    new->tail= list;
    return new;
  }
  list->tail = add( list->tail, elem );
  return list;
}
