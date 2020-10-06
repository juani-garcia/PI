#ifndef MATRIXADT_H
#define MATRIXADT_H

typedef struct matrixCDT * matrixADT;

typedef int elemType;

#include <stdio.h> // :(

static int compare(elemType e1, elemType e2) {
  return e1 - e2;
}

struct rowElement {
    size_t row;
    elemType elem;
};

matrixADT newMatrix();

void freeMatrix(matrixADT m);

int setIfFree(matrixADT m, elemType elem, size_t f, size_t c);

void set(matrixADT m, elemType elem, size_t f, size_t c);

int get(matrixADT m, size_t f, size_t c, elemType * elem);

elemType getOrDefault(matrixADT m, size_t f, size_t c, elemType def);

void deleteElement(matrixADT m, size_t f, size_t c);

int elementCount(const matrixADT m);

struct rowElement * maxElements(const matrixADT m, size_t * dim);

#endif
