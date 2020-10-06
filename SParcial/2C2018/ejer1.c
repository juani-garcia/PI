#include <stdio.h>

int sumMatch( int * v );

int main(){
  int v1[]={1,2,3,6,4,3,2,9,1,2,3,-1};    // 1+2+3=6, 4+3+2=9, 1+2=3
    int v2[]={1,1,2,4,5,5,14,-1};           // 14=5+5+4, 2=1+1
    int v3[]={3,3,-1};                      // 3=3
    int v4[]={1,1,2,2,90,90,-1};            // 90=90, 2=2, 1=1
    int v5[]={1,0,1,2,2,2,6,-1};            // 6=2+2+2, 1=0+1
    int v6[]={-1};
    int v7[]={0,-1};
    int v10[]={1,1,2,3,6,4,3,2,9,1,2,3,-1};
    int v20[]={1,1,2,4,5,5,14,10,-1};
    int v30[]={4,3,-1};
    int v40[]={1,-1};
    int v50[]={1,0,1,2,1,2,2,2,-1};
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", sumMatch(v1), sumMatch(v2), sumMatch(v3), sumMatch(v4), sumMatch(v5), sumMatch(v6), sumMatch(v7), sumMatch(v10), sumMatch(v20), sumMatch(v30), sumMatch(v40), sumMatch(v50));
}

int sumMatch( const int * v ){
  if(*v < 0 )
    return 0;
  int partial = sumMatch( v + 1 );
  if( partial == 0 )// Hay que sumar
    return *v;
  if( partial > 0 ) // Resto hasta llegar a 0
    return partial - *v;
   return partial; // Que devuelva negativo hasta terminar
}
