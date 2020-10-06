#include "complexADT.h"

typedef struct complexCDT{
  double real;
  double img;
}complexCDT;

complexADT newNum( double r, double i ){
  complexADT num = malloc( sizeof(complexCDT));
  num->real = r; num->img = i;
  return num;
}

void freeNum( complexADT num ){
  free(num);
}

double getReal( complexADT num ){
  return num->real;
}

double getImg( complexADT num ){
  return num->img;
}

complexADT sum( complexADT num1, complexADT num2 ){
  double r = num1->real + num2->real;
  double i = num1->img + num2->img;
  complexADT num3 = newNum( r, i );
  return num3;
}
