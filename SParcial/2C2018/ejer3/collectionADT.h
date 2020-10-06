#ifndef COLLECTION_H
#define COLLECTION_H

typedef struct collectionCDT * collectionADT;
typedef int elemType; // Tipo de elemento a insertar, por defecto int
/**
** Retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y
** positivo si e1 es "mayor" que e2
*/
static int compare (elemType e1, elemType e2) {
return e1 - e2;
}
/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío.
** No hay límite de capacidad.
*/
collectionADT newCollection ();
/* Retorna cuántos elementos hay en la colección */
unsigned int size (const collectionADT collection);
/* Operación de Cola: Encola un elemento, agregándolo al final de la colección */
void enqueue (collectionADT collection, elemType elem);
/* Operación de Cola: Desencola el primer elemento de la colección.
** Precondición: la colección no está vacía.
*/
elemType dequeue (collectionADT collection);
/* Operación de Pila: Apila un elemento, agregándolo al tope (o principio)
** de la colección
*/
void push (collectionADT collection, elemType elem);
/* Operación de Pila: Desapila el elemento que está en el tope (el primero)
** de la colección. Precondición: la colección no está vacía.
*/
elemType pop (collectionADT collection);
/* Libera toda la memoria reservada */
void freeCollection (collectionADT collection);

#endif
