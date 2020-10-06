#define swap( t, x, y ) { t aux = x; x = y; y = aux; }
#include <stdio.h>

int main(){
  double x = 5.4363264, y = 6.463251;
  printf("x vale %f e y vale %f\n", x, y);
  printf("Aplico swap\n");
  swap( float, x, y);
  printf("x vale %f e y vale %f\n", x, y);
}
