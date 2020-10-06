#include <stdio.h>
#include <math.h>
#include "getnum.h"

int main(){
  double a, b, c;
  a = b = c = 0;
  a = getfloat("Ingrese el coeficiente de a: ");
  b = getfloat("Ingrese el coeficiente de b: ");
  c = getfloat("Ingrese el coeficiente de c: ");

  if (a == 0)
    printf("Esto no es una cuadratica\n");
  else {
    double disc;
    disc = b*b-4*a*c;
    if (disc < 0)
      printf("Esta cuadratica tiene soluciones imaginarias\n");
    else {
      if (disc != 0){
        double x1, x2;
        x1 = (-b+sqrt(disc))/(2*a);
        x2 = (-b-sqrt(disc))/(2*a);
        printf("x1 = %3.2f x2 = %3.2f\n", x1, x2);
      }
      else {
        double x;
        x = -b/(2*a);
        printf("x = %3.2f\n", x);
      }
    }
  }
}
