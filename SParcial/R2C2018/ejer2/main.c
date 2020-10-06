#include "multiADT.h"
#include <assert.h>
#include <stdio.h>

int main() {
  printf("A ver ");
  multiSetADT mset = newMultiSet();
  add(mset, 1);
  assert(count(mset, 1) == 1);
  assert(count(mset, 2) == 0);
  assert(size(mset) == 1);
  add(mset, 3);
  add(mset, 3);
  add(mset, 3);
  add(mset, 5);
  add(mset, 7);
  add(mset, 7);
  add(mset, 7);
  add(mset, 7);
  add(mset, 9);
  add(mset, 9);
  assert(count(mset, 3) == 3);
  assert(count(mset, 7) == 4);
  assert(count(mset, 9) == 2);
  removeAll(mset, 9);
  assert(count(mset, 9) == 0);
  assert(size(mset) == 4);
  printf("Mateo deja el anime, por favor, es el causante numero uno de muertes por deprimision exhaustiva //F\n"); //F
}
