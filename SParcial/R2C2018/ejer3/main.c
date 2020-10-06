#include "listADT.h"
#include <assert.h>
#include <stdio.h>

int main(){
  listADT l = newList();
  add( l, 1 );
  add( l, 1 );
  add( l, 4 );
  add( l, 6 );
  add( l, 1 );
  add( l, 2 );
  add( l, 7 );
  add( l, 8 );
  add( l, 19 );
  add( l, 10 );
  add( l, -1 );
  toBegin( l );
  toBeginAsc( l );
  while( hasNext(l) )
    printf("%d->", next(l));
  printf("NULL\n");
  while( hasNextAsc(l) )
    printf("%d->", nextAsc(l));
  printf("NULL\n");
}
