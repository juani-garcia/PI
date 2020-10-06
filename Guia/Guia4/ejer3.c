#include <stdio.h>
#define PI 3.1415
#define Volumen(r) printf("El volumen de la esfera de radio %d es %.2f\n",\
                          r, ((4.0/3) * PI * (r) * (r) * (r)))

int main(){
  for( int i = 1; i <= 10; i++ )
    Volumen(i);
}
