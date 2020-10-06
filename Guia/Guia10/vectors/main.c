#include "vecADT.h"
#include <assert.h>
#include <stdio.h>

int main(){
  vecADT v = newVector();
  int w[] = {1, 2, 3};
  assert( put( v, w, 3, 3 ) == 3 );
  assert( getIdx(v, 2) == 4 );
  int u[] = {4, 5, 6};
  assert( put(v, u, 3, 0) == 3 );
  printf("Todo de 10\n");
  free(v);
}
