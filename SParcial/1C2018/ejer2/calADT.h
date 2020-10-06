#ifndef _calADT_h_
#define _calADT_h_

#include <stdlib.h>

typedef struct calCDT * calADT;

typedef struct tDate {
  unsigned char day;
  unsigned char month;
  unsigned short year;
}tDate;

  typedef struct tEvent {
  char * eventName;
  tDate date;
}tEvent;

/* Crea la estructura que dará soporte al almacenamiento de eventos. */
calADT newCal ();
/*
 Agrega un evento al calendario.
 Si ya existe un evento en el calendario para la fecha del evento, la función no lo agrega y
 retorna cero. Si pudo agregar el evento retorna 1.
 Se asume que la fecha recibida es válida
*/
int addEvent (calADT cal, tEvent event);
/*
 Funciones de iteración para que el usuario pueda consultar todas los eventos del calendario
 en orden cronológico (del más antiguo al más reciente).
 toBegin() inicializa el iterador en el evento de fecha más antigua del calendario.
 Si el calendario es vacío no hace nada.
 hasNext() retorna 1 (uno) si una invocación a nextElement() retorna un
 evento válido. Retorna cero si no hay más elementos por consumir en el iterador.
 nextElement() retorna el evento del calendario al que apunta el iterador y hace
 apuntar el iterador al siguiente evento cronológico del calendario.
** Si no hay más eventos en el calendario aborta la ejecución.
*/
void toBegin (calADT cal);
int hasNext (calADT cal);
tEvent nextElement (calADT cal);

#endif // calADT.h
