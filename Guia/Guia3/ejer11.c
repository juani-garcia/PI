#include <stdio.h>

int main(){
  printf("N\t10*N\t100*N\t1000*N\n");
  for(int n = 0; n < 21; n++)
    printf("%-2d\t%-3d\t%-4d\t%-5d\n", n, n*10, n*100, n*1000);
}
