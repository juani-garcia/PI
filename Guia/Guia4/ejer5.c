#define MAXIMO2( x, y, z ) float z = ( (x) > (y) ? x : y )
#include <stdio.h>

int main(){
    MAXIMO2( 4.001, 4.002, max);
    printf("%f\n", max);
}
