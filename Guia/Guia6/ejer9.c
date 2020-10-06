#include "random.h"
#include <stdio.h>
#include <math.h>

double mean( const unsigned char set[], int dim ){
  int sum = 0;
  for( int i = 0; i < dim; i++ ){
    printf("%d %d \n", (set[i]>>4) & 0x0F, set[i] & 0x0F);
    sum += (set[i]>>4) + (set[i] & 0x0F );
  }
  return (double) sum / (2 * dim);
}


double stdDev( const unsigned char set[], int dim ){
  double accum = 0;
  double avg = mean( set, dim );
  for( int i = 0; i < dim; i++ )
    accum += pow( (set[i]>>4) - avg, 2) + pow( (set[i] & 0x0F) - avg, 2 );
  return sqrt( accum / (2 * dim));
}

int main(){
  unsigned char set[] = { 0x37, 0xF2, 0x4A, 0xFF, 0x03 };
  int dim = sizeof( set ) / sizeof( set[0] );
  printf("%f\n", stdDev( set, dim ));
}
