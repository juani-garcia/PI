#include "matrixADT.h"
#include <stdlib.h>
#define BLOCK 10

typedef struct tRow{
  elemType * elems;
  char * occ;
  size_t colQty; // Memoria que tengo reservada en los arreglos elem y occ
}tRow;

typedef struct matrixCDT{
  tRow * rows;
  size_t rowQty; // Cuantos rows tengo disponibles
  size_t amount; // Posiciones efectivamente ocupadas
}matrixCDT;

matrixADT newMatrix(){
  return calloc( 1, sizeof(matrixCDT));
}

void freeMatrix(matrixADT m){
  for( int i = 0; i < m->rowQty; i++ ){
    free( m->rows[i].elems );
    free( m->rows[i].occ );
  }
  free( m->rows );
  free( m );
}

int setIfFree(matrixADT m, elemType elem, size_t i, size_t j){
  if( i >= m->rowQty || j >= m->rows[i].colQty || m->rows[i].occ[j] == 0 ){
    set( m, elem, i, j );
    return 1;
  }
  return 0;
}

void set(matrixADT m, elemType elem, size_t i, size_t j){
  if( i >= m->rowQty ){ // Tengo que crear filas
    m->rows = realloc( m->rows, (i + 1) * sizeof(tRow));
    for( int k = m->rowQty; k <= i; k++ ){
      m->rows[k].elems = NULL;
      m->rows[k].occ = NULL;
      m->rows[k].colQty = 0;
    }
    m->rowQty = i + 1;
  } // Ya tengo la fila que necesito
  if( j >= m->rows[i].colQty ){ // Tengo que crear columnas
    m->rows[i].elems = realloc( m->rows[i].elems, (j + 1) * sizeof(elemType));
    m->rows[i].occ = realloc( m->rows[i].occ, (j + 1) * sizeof(char));
    for( int k = m->rows[i].colQty; k <= j; k++ )
       m->rows[i].occ[j] = 0;
    m->rows[i].colQty = j + 1;
  } // Ya tengo la columna que necesito. Ahora simplemente agrego
  m->amount += ( m->rows[i].occ[j] == 0 ); // Si estaba en cero ahora tengo un elemento maxElements
  m->rows[i].elems[j] = elem;
  m->rows[i].occ[j] = 1;
}

int get(matrixADT m, size_t i, size_t j, elemType * elem){
  if( i > m->rowQty || j > m->rows[i].colQty || m->rows[i].occ[j] == 0 )
    return 0;
  *elem = m->rows[i].elems[j];
  return 1;
}

elemType getOrDefault(matrixADT m, size_t i, size_t j, elemType def){
  elemType aux;
  int res = get( m, i, j, &aux );
  if( res )
    return aux;
  return def;
}

void deleteElement(matrixADT m, size_t i, size_t j){
  if( i > m->rowQty || j > m->rows[i].colQty || m->rows[i].occ[j] == 0 )
    return;
  m->rows[i].occ[j] = 0;
  m->amount--;
}

int elementCount(const matrixADT m){
  return m->amount;
}

// Devuelve el indice del mayor de la fila
static int maxRow( elemType * vec, char * occ, size_t dim ){
  int max = -1;
  for( int i = 0; i < dim; i++ ){
    if( occ[i] != 0 && ( max == -1 || compare( vec[max], vec[i]) < 0) )
      max = i;
  }
  return max;
}

struct rowElement * maxElements(const matrixADT m, size_t * dim){
  struct rowElement * res = NULL;
  *dim = 0;
  for( int i = 0; i < m->rowQty; i++){
    int max;
    max = maxRow( m->rows[i].elems, m->rows[i].occ, m->rows[i].colQty );
    if( max != -1 ){ // Tengo que agregar
      if( *dim % BLOCK == 0 )
        res = realloc( res, (*dim + BLOCK )* sizeof(struct rowElement));
      res[*dim].row = i;
      res[(*dim)++].elem = m->rows[i].elems[max];
    }
  }
  res = realloc( res, *dim * sizeof(struct rowElement));
  return res;
}
