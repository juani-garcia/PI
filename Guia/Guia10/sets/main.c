#include <stdio.h>
#include <assert.h>
#include "sets.h"

int main(){
  setADT s1 = newSet();
  setADT s2 = newSet();
  assert(add( s1, 2 ) == 1);
  assert(add( s1, 4 ) == 1);
  assert(add( s1, 6 ) == 1);
  assert(add( s1, 6 ) == 0);
  assert(add( s2, 3 ) == 1);
  assert(add( s2, 6 ) == 1);
  assert(add( s2, 9 ) == 1);
  assert(add( s2, 3 ) == 0);
  setADT s3 = unionSet(s1, s2);
  setADT s4 = intersection(s1, s2);
  setADT s5 = substraction(s1, s2);
  assert( belongs( s3, 2 ) );
  assert( belongs( s3, 0 ) == 0 );
  assert( belongs( s4, 6 ) );
  assert( belongs( s4, 3 ) == 0 );
  assert( belongs( s5, 2 ) );
  assert( belongs( s5, 6 ) == 0 );

  printf("Sorprendentemente, no la cagaste\n");
}
