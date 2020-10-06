#include <stdio.h>
#include <stdlib.h>

typedef struct node * tList;
typedef struct node{
  int elem;
  struct node * tail;
}tNode;

tList elimina( tList );
void printList( tList );
tList addRep( tList, int );
tList eliminaRep( tList );

int main(){
  tList list = NULL;
  list = addRep(list, 1);
  list = addRep(list, 2);
  list = addRep(list, 3);
  list = addRep(list, 1);
  list = addRep(list, 1);
  list = addRep(list, 5);
  list = addRep(list, 1);
  list = addRep(list, 4);
  list = addRep(list, 3);
  list = addRep(list, 3);
  list = addRep(list, 1);
  list = addRep(list, 1);
  printList( list );
  list = eliminaRep( list );
  printList( list );
}

void printList( tList list ){
  tList aux = list;
  while( aux != NULL ){
    printf("%d ", aux->elem );
    aux = aux->tail;
  }
  putchar('\n');
}

tList addRep( tList list, int elem ){
  if( list == NULL || list->elem > elem ){
    tList new = malloc( sizeof( tNode ));
    new->elem = elem;
    new->tail = list;
    return new;
  }
  list->tail = addRep( list->tail, elem );
  return list;
}

tList eliminaRep( tList list ){
  if( list == NULL || list->tail == NULL )
    return list;
  if( list->elem == list->tail->elem ){
    tList aux = list->tail;
    free(list);
    aux = eliminaRep( aux );
    //return aux;
  }
  list->tail = eliminaRep( list->tail );
  return list;
}
