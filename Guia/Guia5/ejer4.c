#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randInt( int min, int max ){
  return ( (rand() / (RAND_MAX + 1.0)) * ( max - min + 1 ) + min );
}

int main(){
  srand(time(NULL));
  int dist[6] = { 0, 0, 0, 0, 0, 0 };
  for ( int i = 0; i < 100; i++ ){
    int num = randInt( 1, 6 );
    dist[num-1]++;
  }
  for( int j = 0; j < 6; j++ )
    printf("El numero %d salio %d veces\n", j+1,  dist[j]);
}
