#ifndef complexADT_h
#define complexADT_h

#include <stdlib.h>

typedef struct complexCDT * complexADT;

complexADT newNum( double r, double i );

void freeNum( complexADT num );

double getReal( complexADT num );

double getImg( complexADT num );

complexADT sum( complexADT num1, complexADT num2 );

#endif // complexADT
