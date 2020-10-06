#include <stdio.h>
#include <stdlib.h>

int isLeap( int year ){
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int validDate ( int year, int month, int day ){
  static int daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
                               {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
  if( day > daytab[ isLeap(year) ][month] )
    return 0;
  else
    return 1;
}

int dateConv( const char * date, int * day, int * month, int * year ){
  int ty = atoi( date ), tm = atoi( date + 3 ), td = atoi( date + 6 );
  if( validDate(ty, tm, td )){
    *day = td;
    *month = tm;
    *year = ty;
    return 1;
  }
  else
    return 0;
}

int main(){
  const char * date = "08/04/2020";
  int day, month, year;
  dateConv( date, &day, &month, &year );
  printf(" %d\n", day, month, year );
}
