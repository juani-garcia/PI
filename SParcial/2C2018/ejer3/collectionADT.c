#include "collectionADT.h"
#define dequeue

typedef struct node{
  elemType elem;
  struct node * tail;
}node;

typedef struct collectionCDT{
  node * first;
  node * last;
  size_t size;
}collectionCDT;

collectionADT newCollection(){
  return calloc( 1, sizeof( collectionCDT ));
}

unsigned int size (const collectionADT collection){
  return collection->size;
}

static node * create( elemType elem ){
  node * new = malloc( sizeof(node));
  new->elem = elem;
  return new;
}

void enqueue (collectionADT collection, elemType elem){
  node * new = create( elem ); // creo un nodo para agregar al final
  new->tail = NULL;
  if( collection->first == NULL )
    collection->first = new;
  else
    collection->last->tail = new;
  collection->last = new;
  collection->size++;
}

void push( collectionADT collection, elemType elem ){
  node * new = create( elem ); // creo un nodo para agregar al comienzo
  if( collection->last == NULL )
    collection->last = new;
  else
    new->tail  = collection->first;
  collection->first = new;
  collection->size++;
}
