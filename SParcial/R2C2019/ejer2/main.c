#include "matrixADT.h"
#include <stdio.h>

int main() {
    matrixADT m = newMatrix();
    set(m, 10, 5, 2);
    setIfFree(m, 10, 5, 30); // m[5][30] = 10
    setIfFree(m, 11, 5, 30);
    set(m, 20, 5, 10);
    size_t dim;
    struct rowElement * v = maxElements(m, &dim);
    int elem = 0;
    get( m, 5, 10, &elem );
    printf("m[5][10] = %d\n", elem );
    for (int i = 0; i < dim; i++) {
        printf("\t%ld\t%d\n", v[i].row, v[i].elem);
    }
    freeMatrix(m);
    return 0;
}
