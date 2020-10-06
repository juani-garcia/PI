#include <stdio.h>

void piramide( int * latas, int * h );

int main(){
  int latas = 338359, h = 0;
  piramide( &latas, &h );
  printf("%d / %d\n", latas, h );
}

void piramide( int * latas, int * h ){
  if( *latas < (*h + 1) * (*h + 1))
    return;
  if( *latas >= (*h + 1) * (*h + 1)){
    (*h)++;
    *latas -= (*h) * (*h);
    piramide( latas, h );
  }
}
