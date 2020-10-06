#include <stdlib.h>
#include <stdio.h>

typedef struct node * tList;

typedef struct node{
  int elem;
  struct node * tail;
}node;

tList elimina( tList l, int (*crit)(int) ){
  if( l== NULL )
    return NULL;
  if( crit(l->elem) ){
    tList aux = l->tail;
    free(l);
    aux = elimina( aux, crit );
    return aux;
  }
  else{
    l->tail = elimina( l->tail, crit );
    return l;
  }
}

int esPar( int n ){
  return n % 2 == 0;
}

int
main(void)
{
node * node5 = malloc(sizeof(*node5));
node5->elem = 6;
node5->tail = NULL;
node * node4 = malloc(sizeof(*node4));
node4->elem = 5;
node4->tail = node5;
node * node3 = malloc(sizeof(*node3));
node3->elem = 4;
node3->tail = node4;
node * node2 = malloc(sizeof(*node2));
node2->elem = 3;
node2->tail = node3;
node * node1 = malloc(sizeof(*node1));
node1->elem = 1;
node1->tail = node2;
tList res = elimina (node1, esPar);
while(res != NULL) {
printf("%d -> ", res->elem);
res = res->tail;
}
printf("NULL\n");
}
