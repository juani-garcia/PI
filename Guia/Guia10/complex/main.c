#include "complexADT.h"
#include <stdio.h>

int main(){
  complexADT a = newNum( 3, 2 );
  complexADT b = newNum( 2, -5 );
  complexADT c = sum( a, b);
  printf("a = %.0g + (%.0g) i\n", getReal(a), getImg(a));
  printf("b = %.0g + (%.0g) i\n", getReal(b), getImg(b));
  printf("c = %.0g + (%.0g) i\n", getReal(c), getImg(c));
  freeNum(a);
  freeNum(b);
  freeNum(c);
}
