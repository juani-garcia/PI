#include "random.h"
#include <stdio.h>
#define DIM 6

int main(){
  randomize();
  int v[] = {1, 2, 3, 4, 5, 6};
  int r, aux;
  for( int i = 0; i < DIM-1; i++){
    r = randInt(0, i);
    aux = v[i];
    v[i] = v[r];
    v[r] = aux;

  for( int j = 0; j < DIM-1; j++)
    printf("%d ", v[j]);
  }
  putchar('\n');
}
