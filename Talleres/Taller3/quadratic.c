#include <stdio.h>
#include <math.h>

int quadraticSolver(double a, double b, double c){
  double disc = b - (4 * a * c);
  if(disc < 0)
    return 1;
  return 0;
}

int main(){
  printf("%d\n", quadraticSolver(1, 0, 4));
}
