#include <stdlib.h>
#include <stdio.h>

typedef struct node{
  int elem;
  struct node * tail;
}tNode;

typedef tNode * tList;

tList unionList( tList 1, tList2 ){
  if( l1 == NULL && l2 == NULL )
    return NULL; // Termine
  if( l1 == NULL )
    return unionList( l2, l1 ); // Asumo l1 != NULL de aca en mas
  tList new = malloc( sizeof(tNode) ); // Siempre se agrega
  if( l2 == NULL || l1->elem < l2->elem ){
    new->elem = l1->elem;
    new->tail = unionList( l1->tail, l2 )
  }
  else if( l1->elem > l2->elem ){
    new->elem = l2->elem;
    new->tail = unionList( l1, l2->tail );
  }else { // Sabemos en este punto que son iguales
    new->elem = l1->elem;
    new->tail = unionList( l1->tail, l2->tail );
  }
  return new;
}
