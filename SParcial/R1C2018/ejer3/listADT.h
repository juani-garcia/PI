#ifndef LISTADT_H_
#define LISTADT_H_
typedef ____ elemType;
typedef struct listCDT * listADT;
/* 0 (cero) si son iguales, otro valor sinó */
static int compare(elemType elem1, elemType elem2)
{
return _____;
}
listADT newList(void);
/* Inserta un elemento sin importar el orden.
** Si el elemento ya está, lo inserta duplicado
*/

int insert(listADT list, elemType element);
/* Borra todas las apariciones del elemento */

int delete(listADT list, elemType element);

int listIsEmpty(const listADT list);

int elementBelongs(const listADT list, elemType element);

void freeList(listADT list);

int listSize(const listADT list);

void toBegin(listADT list);

int hasNext(const listADT list);

elemType next(listADT list);

#endif LISTADT_H_
