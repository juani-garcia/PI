#include "calADT.h"

typedef struct node{
  tEvent event;
  struct node * tail;
}node;

typedef struct calCDT{
  node * first;
  node * current;
}calCDT;

// 0 si son la misma, -1 si d1 es anterior y 1 si d1 es posterior
static int dateCmp(tDate date1, tDate date2) {
  if (date1.year != date2.year)
    return date1.year - date2.year;
  if (date1.month != date2.month)
    return date1.month - date2.month;
  return date1.day - date2.day;
}

calADT newCal(){
  return calloc(1, sizeof(calCDT));
}

node * addRec( node * list, tEvent event, int * ok ){
  int cmp;
  if( list == NULL || (cmp = dateCmp( event.date, list->event.date )) < 0 ){
    node * new = malloc( sizeof(node) );
    new->event = event;
    new->tail = list;
    *ok = 1;
    return new;
  }
  if( cmp > 0 )
    list->tail = addRec( list->tail, event, ok );
  return list;
}

int addEvent (calADT cal, tEvent event){
  int ok = 0;
  cal->first = addRec(cal->first, event, &ok );
  return ok;
}

void toBegin (calADT cal){
  if( cal->first != NULL )
    cal->current = cal->first;
}

int hasNext( calADT cal ){
  return cal->current != NULL;
}

tEvent nextElement( calADT cal ){
  tEvent event = cal->current->event;
  cal->current = cal->current->tail;
  return event;
}
