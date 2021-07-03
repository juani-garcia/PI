#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bstADT.h"

int main(){
    bstADT bst = newBst();
    insert(bst, 5);
    insert(bst, 8);
    insert(bst, 2);
    insert(bst, 10);
    insert(bst, 6);
    insert(bst, 1);
    int nodes = size(bst);
    int * v = inorder(bst);
    for(int i = 0; i < nodes; i++){
        printf("%d ", v[i]);
    }
    putchar('\n');
    free(v);
    freeBst(bst);
    return 0;
}
