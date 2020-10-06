#include <stdio.h>
#include "getnum.h"

int main(){
  float payment = 300;
  int sold;
  do{
  sold = getint("Ingrese el monto de las ventas: ");
  } while(sold < 0);
  if(sold > 1000 && sold < 2000)
    payment += sold * 0.05;
  else{
    if(sold > 2000 && sold < 4000)
      payment += sold * 0.07;
    else{
      if(sold > 4000)
        payment += sold * 0.09;
    }
  }
  printf("Se debe pagar %.2f\n", payment);
}
