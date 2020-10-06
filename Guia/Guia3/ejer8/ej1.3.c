#include <stdio.h>
#define lower 0
#define upper 300
#define step 20

int main(){
  float fahr, cels;
  while(fahr <= upper){
    cels = (5.0/9) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, cels);
    fahr += step;
  }
}
