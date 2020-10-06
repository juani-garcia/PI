#include <stdio.h>
#include "getnum.h"
#define swap( t, x, y ) { t temp = x; x = y; y = temp; }

int mcd(int a, int b){
  int auxi = 1;
  if( a < b )
    swap(int , a, b)
  while (b){
    auxi = b;
    b = a % b;
    a = auxi;
  }
return a;
}

void simplify( int num, int den ){
  printf("%d/%d\n", num / mcd(num, den), den / mcd(num, den));
}

void fracSum( int num1, int den1, int num2, int den2 ){
  int numf = den2 * num1 + den1 * num2;
  simplify( numf, den1*den2);
}

int main(){
  int num1 = getint("Ingrese numerador: ");
  int den1 = getint("Ingrese denominador: ");
  int num2 = getint("Ingrese numerador: ");
  int den2 = getint("Ingrese dnominador: ");
  fracSum(num1, den1, num2, den2);
}
