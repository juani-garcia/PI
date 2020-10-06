#ifndef EJ2ADT_H
#define EJ2ADT_H

typedef struct popularSetCDT * popularSetADT

typedef int elemType;

static int compare (elemType e1, elemType e2){
  return e1-e2;
}

popularSetADT newPopularSet();

size_t add(popularSetADT popularSet, elemType elem);

size_t size(popularSetADT popularSet);

void toBegin(popularSetADT popularSet);

int hasNext(popularSetADT popularSet);

elemType next(popularSetADT popularSet);

elemType * get(popularSetADT popularSet, elemType elem);

#endif
