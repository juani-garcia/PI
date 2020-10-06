#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#define PALOS 4
#define FIGS 13
#define JUEGO 5

typedef struct{
  char palo;
  char fig;
}tipoCarta;
typedef tipoCarta tipoMazo[52];
typedef tipoCarta tipoJuego[5];

void crearMazo( tipoMazo mazo );
void mezclarMazo( tipoMazo mazo );
void sacarJuego( tipoJuego juego, tipoMazo mazo, int dim );
int clasificar( tipoJuego juego );

int main(){
  char * nombres[] = {"NADA", "PAR", "PIERNA", "POKER"};
  randomize();
  tipoMazo mazo;
  tipoJuego juego;
  crearMazo( mazo );
  mezclarMazo( mazo );
  int dim = PALOS * FIGS;
  sacarJuego( juego, mazo, dim );
  int res = clasificar( juego );
  for( int i = 0; i < JUEGO; i++ )
    printf("F = %d P = %d ||", juego[i].fig, juego[i].palo);
  printf("\nSacaste este juego: %s\n", nombres[res] );
}

void crearMazo( tipoMazo mazo ){
  for( int i = 0; i < PALOS * FIGS; i++ ){
    mazo[i].palo = i % PALOS;
    mazo[i].fig = i % FIGS;
    }
}

void mezclarMazo( tipoMazo mazo ){
  int r;
  tipoCarta temp;
  for( int i = 0; i < PALOS * FIGS; i++ ){
    r = randInt(0, i);
    temp = mazo[r];
    mazo[r] = mazo[i];
    mazo[i] = temp;
  }
}

void sacarJuego( tipoJuego juego, tipoMazo mazo, int dim ){
  int r;
  for( int i = 0; i < JUEGO; i++ ){
    r = randInt(0, dim - 1);
    juego[i] = mazo[r];
    mazo[r] = mazo[dim - 1];
    dim--;
  }
}

int clasificar( tipoJuego juego ){
  int coincidencias = 0, aux;
  for( int i = 0; i < JUEGO - 1; i++ ){
    aux = 0;
    for( int j = 0; j < JUEGO; j++ ){
      if( i != j && juego[i].fig == juego[j].fig )
        aux++;
    }
    coincidencias = (aux > coincidencias)? aux : coincidencias;
  }
  return coincidencias;
}
