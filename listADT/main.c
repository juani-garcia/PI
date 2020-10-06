//
//  main.c
//  listADT
//


#include <stdio.h>
#include "listADT.h"
#include <stdlib.h>

void printList( listADT list );
elemType square( elemType elem );
elemType div2( elemType elem );
int criterio1( elemType elem );
int criterio2( elemType elem );

int main(void) {
  listADT list1 = newList();
  int v[] = {1, 1, 2, 3, 4, 6, 2, 3, 4, 8, 9, 10, -1, -2 ,11, -23};
  int cant = fromArray( list1, v, sizeof(v)/sizeof(*v) );
  printList( list1 );
  printf("Se copiaron %d elementos\n", cant );
  printf("Creamos sublista\n" );
  listADT list2 = subList( list1, criterio2 );
  printList( list2 );
}

void printList( listADT list ){
  toBegin( list );
  while( hasNext(list) ){
    printf("%d ", next( list ) );
  }
  putchar('\n');
}

elemType square( elemType elem ){
  return elem * elem;
}

elemType div2( elemType elem ){
  return elem/2;
}

int criterio1( elemType elem ){
  return (elem % 2) == 0;
}

int criterio2( elemType elem ){
  return elem > 0;
}
