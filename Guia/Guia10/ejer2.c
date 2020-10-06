#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

tResp buscaCeros( tIntv * intervalo, double (*fun) (double) );
void menu( double * min, double * max, int opcion );

int main(){

}

tResp buscaCeros( tIntv * intervalo, double (*fun) (double) ){
    tResp res;
    res.raices = NULL;
    double step = ( intervalo->fin - intervalo->inicio )/DIVS;
    double pos = intervalo->inicio, donde;
    int cant;

    double actual, anterior;

    actual = anterior = fun(pos);

    for( esCero = 0, cant = 0; intervalo->fin - pos >= EPS; pos += step ){

        actual = fun(pos);

        if( fabs(actual) < EPS || actual * anterior < 0 ){
            if( cant % BLOCK == 0 )
                res.raices = realloc( res.raices, (cant + BLOCK) * sizeof(tResp));
            res.raices[cant].inicio = pos - step;
            res.raices[cant].fin = pos;
            cant++;
            while(fabs(actual) < EPS) {
                pos += step;
                actual = fun(pos);
            }
        }

        anterior = actual;
    }
    res.raices = realloc( res.raices, cant * sizeof( tResp ));
    res.dim = cant;
    return res;
}

void menu( double * min, double * max, int * opcion ){

}
