#include <stdlib.h>
#include <stdio.h>

typedef struct node * tList;
typedef struct node{
  int elem;
  struct node * tail;
}tNode;

tList removeIf( tList list, int (*fun) (int) );
tList inter( tList l1, tList l2 );
tList add( tList list, int elem );
int pares( int n );

int main(){
  tList l1 = NULL, aux, l2, l3;
  l1 = add( l1, 1 );
  l1 = add( l1, 1 );
  l1 = add( l1, 1 );
  l1 = add( l1, 3 );
  l1 = add( l1, 4 );
  l1 = add( l1, 1 );
  l1 = add( l1, 5 );
  l1 = add( l1, 6 );
  l1 = add( l1, 5 );
  l1 = add( l1, 7 );
  l1 = add( l1, 5 );
  aux = l1;
  while( aux != NULL ){
    printf("%d->", aux->elem );
    aux = aux->tail;
  }
  printf("NULL\n");
  l2 = removeIf( l1, pares );
  aux = l2;
  while( aux != NULL ){
    printf("%d->", aux->elem );
    aux = aux->tail;
  }
  printf("NULL\n");
  l3 = inter( l1, l2 );
  aux = l3;
  while( aux != NULL ){
    printf("%d->", aux->elem );
    aux = aux->tail;
  }
  printf("NULL\n");
}


tList removeIf( tList list, int (*fun) (int) ){
  if( list == NULL )
    return list;
  if( fun(list->elem) ){
    tList aux = list->tail;
    free(list);
    return removeIf( aux, fun );
  }
  list->tail = removeIf( list->tail, fun );
  return list;
}

tList inter( tList l1, tList l2 ){
  if( l1 == NULL || l2 == NULL ) //Ambos deben ser no nulos
    return NULL;
  if( l1->elem < l2->elem )
    return inter( l1->tail, l2 );
  if( l1->elem > l2->elem )
    return inter( l1, l2->tail );
  tList new = malloc( sizeof(tNode)); // Son iguales! --> agrego
  new->elem = l1->elem;
  new->tail = inter( l1->tail, l2->tail );
  return new;
}

tList add( tList list, int elem ){
  if( list == NULL || elem < list->elem ){
    tList new = malloc( sizeof(tNode) );
    new->elem = elem;
    new->tail= list;
    return new;
  }
  if( elem > list->elem )
    list->tail = add( list->tail, elem );
  return list;
}

int pares( int n ){
  return n % 2 == 0;
}
