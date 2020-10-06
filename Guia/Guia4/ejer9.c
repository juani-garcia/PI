#include <stdio.h>
#include "getnum.h"
#define ENT_HORA 9
#define ENT_MINUTOS 30

int llegaTemprano (const int hora, const int minuto){
 return ((hora < ENT_HORA) || ((minuto == ENT_HORA) && (minuto >= ENT_MINUTOS)));
}

int main(){
  int hora = getint("Ingrese la hora de llegada: ");
  int minuto = getint("Ingrese el minuto de llegada: ");
  if(llegaTemprano(hora, minuto))
    printf("Llego temprano\n");
  else printf("Llego tarde\n");
}
