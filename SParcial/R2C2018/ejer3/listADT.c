#include "listADT.h"

typedef struct node{
  elemType elem;
  struct node * tailAsc; // El siguiente en orden ascendente
  struct node * tailIns; // El siguiente en orden de insercion
}node;

typedef struct listCDT{
  node * smallest; // El primero en orden ascendente
  node * first;    // El primero insertado
  node * last;     // El ultimo insertado
  node * currentAsc;
  node * currentIns;
}listCDT;

listADT newList(){
  return calloc( 1, sizeof(listCDT)); // Todo inicializado en NULL
}

static node * addRec( node * list, elemType elem, node ** donde, int * cambio ){
  int c;
  if( list == NULL || (c = compare( elem, list->elem )) < 0){
    node * new = malloc( sizeof(node) );
    new->elem = elem;
    new->tailAsc = list;
    new->tailIns = NULL; // Siempre es el ultimo
    *donde = new;
    *cambio = 1;
    return new;
  }
  if( c > 0 )
    list->tailAsc = addRec( list->tailAsc, elem, donde, cambio );
  return list;
}

void add( listADT list, elemType elem ){
  node * donde; // Guardo donde se crea el nuevo nodo para asignarle a last
  int cambio = 0; // Guardo si se crea un nuevo nodo o no
  list->smallest = addRec( list->smallest, elem, &donde, &cambio );
  if( cambio ){
    if( list->first == NULL ) //Estaba vacia, hay que inicializar first
      list->first = donde;
    else
      list->last->tailIns = donde; // Actualizo el tail del anteultimo
    list->last = donde;
  }
}

void toBegin (listADT list){
  list->currentAsc = list->smallest; // El current apunta al menor
}

int hasNext (listADT list){
  return list->currentAsc != NULL;
}

elemType next (listADT list){
  elemType aux = list->currentAsc->elem;
  list->currentAsc = list->currentAsc->tailAsc;
  return aux;
}

void toBeginAsc (listADT list){
  list->currentIns = list->first; // El current apunta al primero
}

int hasNextAsc (listADT list){
  return list->currentIns != NULL;
}

elemType nextAsc (listADT list){
  elemType aux = list->currentIns->elem;
  list->currentIns = list->currentIns->tailIns;
  return aux;
}
