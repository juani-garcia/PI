#include <stdio.h>
#define ELAPSED( h1, m1, h2, m2 )   (((h1) > (h2))? (((h1) - (h2)) * 60) : (((h2) - (h1)) * 60) + \
                                    ((m1) > (m2)? ((m1) - (m2)) : ((m2) - (m1))))

int main(){
  int h1, h2, m1, m2;
  h1 = 2; m1 = 10; h2 = 3; m2 = 15;
  printf("%d\n", ELAPSED(h1, m1, h2, m2));
}
