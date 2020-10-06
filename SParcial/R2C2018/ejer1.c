#include <stdlib.h>
#include <stdio.h>

typedef struct node * tList;
typedef struct node{
  int elem;
  struct node * tail;
}node;

tList ordena( tList list );
tList add( tList list, int elem );

int main(){
  tList l = NULL, aux;
  l = add( l, 1 );
  l = add( l, 2 );
  l = add( l, 3 );
  l = add( l, 5 );
  l = add( l, 3 );
  l = add( l, 2 );
  l = add( l, 7 );
  aux = l;
  while( aux != NULL ){
    printf("%d ", aux->elem );
    aux = aux->tail;
  }
  putchar('\n');
  l = ordena( l );
  aux = l;
  while( aux != NULL ){
    printf("%d ", aux->elem );
    aux = aux->tail;
  }
  putchar('\n');
}

tList ordena( tList list ){
  if( list == NULL || list->tail == NULL )
    return list;
  if( list->elem >= list->tail->elem ){ //no respeta orden asc
    node * aux = list->tail->tail;
    free( list->tail );
    list->tail = aux;
    list = ordena( list );
    return list;
  }
  list->tail = ordena( list->tail );
  return list;
}

tList add( tList list, int elem ){
  if( list == NULL ){
    node * new = malloc( sizeof(node) );
    new->elem = elem;
    new->tail = NULL;
    return new;
  }
  list->tail = add( list->tail, elem );
  return list;
}
