#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define FUN(X) (sin(X))
#define BLOCK 10
#define EPS 0.000001
#define DIVS 100000

typedef struct{
  double inicio;
  double fin;
}tIntv;

typedef struct{
  int dim;
  tIntv * raices;
}tResp;

tResp buscaCeros( tIntv * intervalo );

int main(){
  tIntv intervalo = {-10, 10};
  tResp res = buscaCeros( &intervalo );
  printf("Se encontraron %d raices de en los siguientes intervalos\n", res.dim );

  for( int i = 0; i < res.dim; i++ )
    printf("Intervalo %d = {%f, %f}\n", i + 1, res.raices[i].inicio, res.raices[i].fin);
  free( res.raices );
}

tResp buscaCeros( tIntv * intervalo ){
  tResp res;
  res.raices = NULL;
  double step = ( intervalo->fin - intervalo->inicio )/DIVS;
  double pos = intervalo->inicio, donde;
  int esCero, cant;
  for( esCero = 0, cant = 0; intervalo->fin - pos >= EPS; pos += step ){
    if( fabs(FUN(pos)) < EPS && esCero == 0 ){
      esCero = 1;
      donde = pos;
    }
    if( fabs(FUN(pos)) > EPS && esCero == 1 ){
      esCero = 0;
      if( cant % BLOCK == 0 )
        res.raices = realloc( res.raices, (cant + BLOCK) * sizeof(tResp));
      res.raices[cant].inicio = donde;
      res.raices[cant].fin = pos - step;
      cant++;
    }
    if( FUN(pos) * FUN( pos + step ) < 0 && esCero == 0 ){
      if( cant % BLOCK == 0 )
        res.raices = realloc( res.raices, (cant + BLOCK) * sizeof(tResp));
      res.raices[cant].inicio = pos;
      res.raices[cant].fin = pos + step;
      cant++;
    }
  }
  res.raices = realloc( res.raices, cant * sizeof( tResp ));
  res.dim = cant;
  return res;
}
