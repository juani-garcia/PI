#include <stdlib.h>

typedef struct node{
  int elem;
  struct node * node;
}node;
typedef node * tList;

tList resta( tList l1, tList l2 ){
  if( l1 == NULL )
    return NULL;
  if( l2 == NULL || l1->elem < l2->elem ){
    tList new = malloc( sizeof(node) );
    new->elem = l1->elem;
    new->tail = resta( l1->tail, l2 );
    return new;
  }
  if( l2->elem < l1->elem )
    return resta( l1, l2->tail );
  return resta( l1->tail, l2->tail );
}
