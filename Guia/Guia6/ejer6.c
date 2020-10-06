#include <stdio.h>
#include "random.h"

void shuffle( int v[], int dim ){
  int rand, temp;
  for( int i = 0; i < dim; i++){
    rand = randInt(0, i);
    temp = v[i];
    v[i] = v[rand];
    v[rand] = temp;
  }
}

int main(){
  randomize();
  int v[] = {1 , 2, 43, 5332, 3463272, 1234324543};
  int dim = sizeof( v ) / sizeof( v[0] );
  shuffle( v, dim );
  printVec( v, dim );
}
