#include <stdio.h>
#include <stdlib.h>

typedef struct node * tList;
typedef struct node{
  int elem;
  struct node * tail;
}tNode;

void listPrint( tList list );
tList add( tList list, int elem );
tList interseccion( tList, tList );

int main(){
  tList l1 = NULL, l2 = NULL;
  l1 = add(l1, 0);
  l1 = add(l1, 2);
  l1 = add(l1, 4);
  l1 = add(l1, 6);
  l1 = add(l1, 8);
  l1 = add(l1, 10);
  l1 = add(l1, 12);
  l1 = add(l1, 14);
  l1 = add(l1, 16);

  l2  = add(l2, 0);
  l2  = add(l2, 3);
  l2  = add(l2, 6);
  l2  = add(l2, 9);
  l2  = add(l2, 12);
  l2  = add(l2, 15);

  tList l3 = interseccion(l1, l2);
  listPrint(l1);
  listPrint(l2);
  listPrint(l3);
}

void listPrint( tList list ){
  while( list != NULL ){
    printf("%d ", list->elem );
    list = list->tail;
  }
  putchar('\n');
}

tList add( tList list, int elem ){
  if( list == NULL || list->elem > elem ){
    tList new = malloc( sizeof( tNode ));
    new->elem = elem;
    new->tail = list;
    return new;
  }
  if( list->elem == elem )
    return list;
  list->tail = add( list->tail, elem );
  return list;
}

tList interseccion( tList list1, tList list2 ){
  if( list1 == NULL || list2 == NULL )
    return NULL;
  if( list1->elem < list2->elem )
    return interseccion( list1->tail, list2 );
  if( list1->elem > list2->elem )
    return interseccion( list1, list2->tail );
  // Si no es menor ni mayor ---> es igual!
  tList new = malloc(sizeof(tNode));
  new->elem = list1->elem;
  new->tail = interseccion( list1->tail, list2->tail );
  return new;
}
