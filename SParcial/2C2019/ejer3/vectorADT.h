#ifndef punto_h
#define punto_h

#include <stdlib.h>

typedef int elemType;

typedef struct vectorCDT * vectorADT;

vectorADT newVector(void);

void freeVector(vectorADT v);

int put(vectorADT v, elemType elem, size_t index, size_t qty);

void putForced(vectorADT v, elemType elem, size_t index, size_t  qty);

int get(vectorADT v, size_t index, elemType * elem);

void deleteElement(vectorADT v, size_t index);

int elementCount(const vectorADT v);

elemType * toArray(const vectorADT v);

#endif
