//
//  listADT.h
//  listADT
//  Listas genericas ordenadas sin repetidos
//


#ifndef listADT_h
#define listADT_h

#include <stdlib.h>

typedef struct listCDT * listADT;

typedef int elemType;

static int compare(elemType source, elemType target) {
    return source - target;
}

listADT newList(void);
void freeList(listADT list);
int isEmpty(const listADT);
size_t size(const listADT list);

int add(listADT list, elemType elem);
int removeList(listADT list, elemType elem);
elemType get(const listADT list, size_t idx);
int contains(const listADT list, elemType elem);

elemType * toArray(const listADT list);

void toBegin(listADT list);

elemType next(listADT list);

int hasNext(const listADT list);

int fromArray(listADT list, const elemType v[], size_t dim);

// Una funcion que devuelva una nueva lista de elemType
// con la misma cantidad de elementos que la lista
// pero cada elemento resulta de aplicar una funcion a los
// elementos de la lista
listADT map(const listADT source, elemType (* pfun)(elemType elem));

listADT subList(const listADT source, int (* criteria)(elemType elem));


#endif /* listADT_h */
