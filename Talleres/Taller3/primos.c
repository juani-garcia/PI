#include <stdio.h>
#include <math.h>
#include "getnum.h"

int isPrime(int x){
  for( int i = 2; i <= sqrt(x); i++ ){
    if( x % i == 0 )
      return 0;
  }
  return 1;
}

int primeTable(int n){
  int count = 1, num = 2;
  while ( count <= n ){
    if( isPrime(num) ){
      printf("El primo numero %d es %d\n", count, num);
      count++;
    }
    num++;
  }
  return 0;
}
