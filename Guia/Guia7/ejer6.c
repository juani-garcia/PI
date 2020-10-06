#include <stdio.h>
#include "random.h"
#include "getnum.h"
#include <math.h>
#define X 5
#define NUMS 9
#define CLEAN while( getchar() != '\n' )

void generaAleatorio( int incognita[] );
int elegirNivel();
void leerNumero( int numero[] );
void printVec( int vec[] );
int coinciden( int numero[], int incognita[] );
int pertenece( int num, int vec[], int dim );
int cantBien( int numero[], int incognita[] );
int cantReg( int numero[], int incognita[] );

int main(){
  randomize();
  int numero[X], incognita[X], igual = 0, reg, bien;
  generaAleatorio( incognita );
  int n = elegirNivel();
  while( n-- && !igual ){
    leerNumero( numero );
    if( coinciden( numero, incognita ))
      igual = 1;
    else{
      bien = cantBien( numero, incognita );
      reg = cantReg( numero, incognita );
      printf("%d bien y %d regular\n", bien, reg );
    }
  }
  if( igual ){
    printf("Acertaste! El numero era ");
    printVec( incognita );
  }else{
    printf("Lo siento, el numero era ");
    printVec( incognita );
  }
}

void generaAleatorio( int incognita[] ){
  int dim = NUMS, r;
  int valores[NUMS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for( int i = 0; i < X; i++ ){
    r = randInt(0, dim - 1);
    incognita[i] = valores[r];
    valores[r] = valores[--dim];
  }
}

int elegirNivel(){
  int dif;
  do{
    dif = getint("Ingrese un numero del 1 al 10: ");
  }while( dif < 1 || dif > 10 );
  return dif;
}

void leerNumero( int numero[] ){
  int flag, num;
  do{
    num = getint( "Ingrese un numero de %d digitos sin repetir: ", X );
    flag = 1;
    for( int i = X - 1; i >= 0 && flag; i--, num /= 10 ){
      numero[i] = num % 10;
      if( !numero[i] )
        flag = 0;
      else
        if( pertenece( numero[i], numero, X - i) )
          flag = 0;
    }
  } while( !flag || num != 0 );
}

void printVec( int vec[] ){
  for( int i = 0; i< X; i++ )
    printf("%d%s", vec[i], (i == X - 1)? "\n" : "" );
}

int coinciden( int numero[], int incognita[] ){
  for( int i = 0; i < X; i++ )
    if( numero[i] != incognita[i] )
      return 0;
  return 1;
}

int cantBien( int numero[], int incognita[] ){
  int bien = 0;
  for( int i = 0; i < X; i++ )
    if( numero[i] == incognita[i] ){
      numero[i] = -1;
      bien++;
    }
  return bien;
}
int cantReg( int numero[], int incognita[] ){
  int reg = 0;
  for( int i = 0; i < X; i++ )
    for( int j = 0; j < X; j++ )
      if( numero[i] == incognita[j] && i != j )
        reg++;
  return reg;
}

int pertenece( int num, int vec[], int dim ){
  for( int i = X - 1; i > X - dim; i-- )
    if( vec[i] == num )
      return 1;
  return 0;
}
