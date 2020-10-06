#include <stdio.h>
#include "getnum.h"

int main(){
  int seg = getint("Ingrese un intervalo de segundos: ");
  printf("Es equivalente a %d horas, %d minutos y %d segundos\n", seg/3600, (seg%3600)/60, seg%60);
}
