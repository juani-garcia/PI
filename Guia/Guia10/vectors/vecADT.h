#ifndef vecADT_h
#define vecADT_h

#include <stdlib.h>

typedef struct vecCDT * vecADT;

typedef  int elemType; // Tipo de element a insertar

/* Crea un nuevo vector dinámico de elementos genéricos
** Inicialmente el vector está vacío
** Cada elemento a insertar será de tipo elemType
** Si no se pudo crear retorna NULL.
*/
vecADT newVector(void);

/* Libera todos los recursos reservados por el TAD */
void freeVector(vecADT v);

/* Almacena los elementos de elems a partir de la posición index, donde elems es
un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen en la misma
posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
** si v tiene ocupadas las posiciones 1,3 y 6
** se invoca con index=2, dim=5
** el vector actual quedará con los mismos elementos en las posiciones 1, 3 y 6
** pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
** y la función retorna 3
*/
int put(vecADT v, elemType * elems, size_t dim, size_t index);

/* Retorna el índice en el cual está insertado el elemento, o -1 si no lo
encuentra */
int getIdx(vecADT v, elemType elem);

/* Elimina el elemento en la posición index. Si index está fuera del vector no
hace nada */
void deleteElement(vecADT v, size_t index);

/* Retorna cuántos elementos hay insertados en el vector */
int elementCount(vecADT v);

#endif
