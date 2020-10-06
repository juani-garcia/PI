typedef struct multiSetCDT * multiSetADT;
typedef ... elemType; // Tipo de elemento a insertar
/**
** Retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y positivo
** si e1 es "mayor" que e2
*/
static int compare (elemType e1, elemType e2) {
...
}
/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet (¿?);
/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
size_t add (multiSetADT multiSet, elemType elem);
/* Retorna cuántas veces aparece el elemento en el multiSet */
size_t count (const multiSetADT multiSet, elemType elem);
/* Retorna la cantidad de elementos distintos que hay en el multiSet */
size_t size (const multiSetADT multiSet);
/* Retorna el elemento que aparece más veces. Si hay más de uno
** con esa condición, retorna cualquiera de los dos.
** Pre-condición: el multiSet no debe estar vacío
*/
elemType maxElement (const multiSetADT multiSet);
/* Retorna un vector con los distintos elementos (sin repetir) que hay en el multiSet */
elemType * values (const multiSetADT multiSet);
