#include "vectorADT.h"
#define FORCE 1

typedef elemType * tVec;
typedef struct vectorADT{
  tVec elems;
  size_t * qty; // Sera 0 si la posicion esta disponible
  size_t dim; // Espacio maximo reservado
  size_t amount; // Espacio ocupado
}

vectorADT newVector(){
  return calloc( 1, sizeof(vectorCDT) );
}

void freeVector(vectorADT v){
  free( v->elems );
  free( v->qty );
  free( v );
}

int add(vectorADT v, elemType elem, size_t index, size_t qty, int forced ){
  if( v->dim <= index ){ // Me quede sin espacio
    v->elems = realloc( v->elems, (index + 1) * sizeof(elemType) );
    v->qty = realloc( v->qty, (index + 1) * sizeof(size_t) );
    for( int i = v->dim; i <= index; i++ ){
      v->qty[i] = 0;
    }
    v->amount = index + 1;
  }
  if( v->qty[index] == 0 || forced ){
    v->amount += v->qty[index] == 0; // Si estaba libre ahora tengo una posicion mas ocupada
    v->elems[index] = elem;
    v->qty[index] = qty;
    return 1;
  }
  return 0; // O estaba ocupado o no fue forzada
}

int put(vectorADT v, elemType elem, size_t index, size_t qty){
  return add( v, elem, index, qty, !FORCED );
}

void putForced(vectorADT v, elemType elem, size_t index, size_t  qty){
  add( v, elem, index, qty, FORCED );
}

int get(vectorADT v, size_t index, elemType * elem){
  if( index >= v->dim || v->qty[index] == 0 )
    return 0;
  *elem = v->elems[index];
  v->qty[index]--;
  return 1;
}

void deleteElement(vectorADT v, size_t index){
  if( index >= v->dim || v->qty[index] == 0 )
    return;
  v->qty[index] = 0;
}

int elementCount(const vectorADT v){
  return v->amount;
}

elemType * toArray(const vectorADT v){
  if( v->amount == 0 )
    return NULL;
  tVec res = malloc( sizeof(elemType) * v->amount);
  for( int i = 0, j = 0, i < v->dim; i++ ){
    if( v->qty[i] )
      res[j++] = v->qty[i];
  }
  return res;
}
