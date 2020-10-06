#include <stdio.h>
#include <limits.h>
#define epsilon 0.0000000000000000001

int main(){
  printf("N\te\n");
  float e = 1, prev = 0;
  int acc = 1;
  for(int i = 1; e - prev > epsilon; i++){
    prev = e;
    acc *= i;
    e += 1.0/acc;
    printf("%d\t%.20f\n", i, e);
  }
}
