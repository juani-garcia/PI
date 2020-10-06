#include <stdio.h>
#include "getnum.h"

int main(){
  float mxs = getfloat("Introduzca una rapidez en m/s: s");
  printf("%.3f m/s equivale a %.3f km/h\n", mxs, mxs*3.6);

}
