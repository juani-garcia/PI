#include <stdio.h>
#include "getnum.h"
#include "random.h"
#include <stdlib.h>

int maxDif( const int v[] ){
  int max = 0, dif, i;
  for( i = 0; v[i+1] != 0; i++ )
    if( (dif = abs(v[i+1]-v[i])) > max)
      max = dif;
  if( i == 0)
    return -1;
  else
    return max;
}

int main(){
  randomize();
  int dim = getint("Ingrese la dimension del vector: ");
  int v[dim];
  llenarInt( 1, 20, v, dim-1); v[5] = 0;
  printVec( v, dim);
  printf("%d\n", maxDif( v ));

}
