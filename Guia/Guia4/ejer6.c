#include <stdio.h>
#define MAXIMO2(x, y, r) (r=(((x)>(y))? (x):(y)))
#define MAXIMO3(a, b, c, r) MAXIMO2(MAXIMO2(a, b, r), c, r)

int main(void){
    int x = 3, y = 4, q=1, z;
    MAXIMO3(x, y, q, z);
    printf("%d\n", z);
    return 0;
}
