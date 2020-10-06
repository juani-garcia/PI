#include <stdio.h>
#define EXITO 1
#define ERROR 0

int minMax( int vec[], int dim, int * max, int * min, double * avg ){
  if( !dim )
    return ERROR;
  *max = *min = vec[0];
  int sum = 0;
  for( int i = 1; i < dim; i++ ){
    sum += vec[i];
    if( vec[i] > *max )
      *max = vec[i];
    if( vec[i] < *min )
      *min  = vec[i];
  }
  *avg = (double) sum / dim;
  return EXITO;
}

int main(){
  int vec[] = {1, 2, 5,  3, 4, -3, 12, -22, -11 };
  int max, min, out;
  double avg;
  out  = minMax( vec, 9, &max, &min, &avg );
  printf("%d %d %f %d\n", min, max, avg, out);
}
