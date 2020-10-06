#include <stdio.h>
#include <math.h>
#define EPS 0.001

double raiz( double anterior, double x );

int main(){
  printf("%f\n", raiz( 10/2, 1000 ));
}

double raiz( double anterior, double x ){
  double actual = ( anterior + x / anterior ) / 2;
  if( fabs(actual - anterior) < EPS )
    return actual;
  else
    return raiz( actual, x );
}
