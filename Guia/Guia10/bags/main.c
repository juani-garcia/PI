#include "bagADT.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bagADT.h"

int main(){
  printf("A ver... \n");
  bagADT bag = newBag();
  assert(add(bag, 1) == 1 );
  assert(add(bag, 1) == 2 );
  assert(count(bag, 1) == 2);
  assert(count(bag, 2) == 0);
  assert(size(bag) == 1);
  add(bag, 3);
  add(bag, 3);
  add(bag, 3);
  add(bag, 5);
  add(bag, 7);
  add(bag, 7);
  add(bag, 7);
  add(bag, 7);
  add(bag, 9);
  add(bag, 9);
  assert(count(bag, 3) == 3);
  assert(count(bag, 7) == 4);
  assert(count(bag, 9) == 2);
  assert(mostPopular(bag) == 7);
  printf("Salio todo joya\n");
}
