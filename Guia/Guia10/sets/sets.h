#ifndef sets_h
#define sets_h

#include <stdlib.h>

typedef struct setCDT * setADT;

typedef int elemType;

static int cmp( elemType elem1, elemType elem2 ){
  return elem1 - elem2;
}

setADT newSet();

void freeSet( setADT );

int add( setADT, elemType );

int delete( setADT, elemType );

int isEmpty( setADT );

int belongs( setADT, elemType );

setADT unionSet( setADT, setADT );

setADT intersection( setADT, setADT );

setADT substraction( setADT, setADT );

#endif // sets.h
