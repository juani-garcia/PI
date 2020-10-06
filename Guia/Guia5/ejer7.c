#include <stdio.h>
#include <math.h>
#include <limits.h>
#define EPSILON 0.00001

double texp ( double x ){
  double diff = 1, new = 1, prev;
  long accum = 1;
  for ( int i = 1; diff > EPSILON && accum < LONG_MAX; i++, diff = new - prev){
    accum *= i;
    prev = new;
    new += pow(x, i)/(double) accum;
  }
  return new;
}
