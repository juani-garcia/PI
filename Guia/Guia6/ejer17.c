#include <stdio.h>

void insertaDesde( char stg1[], char stg2[], char c ){
  int encontro = 1;
  for( int i = 0; stg1[i] != 0 && encontro; i++ ){
    if( stg1[i] == c ){
      encontro = 0;
      for( int j = 0; stg2[j] != 0; j++, i++)
        stg1[i] = stg2[j];
    }
  }
}

int main(){
  char stg1[] = "manuel";
  char stg2[] = "javier es un buen tipo";
  insertaDesde( stg1, stg2, 'l' );
  printf("%s\n", stg1 );
}
