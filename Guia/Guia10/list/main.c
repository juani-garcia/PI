//
//  main.c
//  listADT
//


#include <stdio.h>
#include <assert.h>
#include "listADT.h"
#include <stdlib.h>

elemType doble (elemType elem){
    return elem * 2;
}
int main(void) {
    
    listADT list1 = newList();
    
    assert(size(list1)==0);
    assert(add(list1, 10)==1);
    assert(size(list1)==1);
    assert(add(list1, 10)==0);
    assert(size(list1)==1);
    assert(get(list1,0)==10);
    
    assert(add(list1, 5)==1);
    assert(add(list1, 15)==1);
    assert(size(list1)==3);
    
    assert(get(list1,0)==5);
    assert(get(list1,1)==10);
    assert(get(list1,2)==15);
    
    assert(removeList(list1, 20)==0);
    assert(removeList(list1, 10)==1);
    assert(size(list1)==2);
    
    for(int i=20; i < 2000; i++) {
        assert(add(list1, i)==1);
    }
    
    listADT list2 = newList();
    add(list2, 999);
    
    elemType * v = toArray(list1);
    elemType * w = toArray(list2);
    // lo usa el vector
    free(v);
    free(w);
    
    int sum = 0;
    for(int i=0; i < size(list1); i++) {
           sum += get(list1, i);
    }
    
    toBegin(list1);
    while ( hasNext(list1)) {
        printf("%d\n", next(list1));
    }
    
    
    toBegin(list1);
    
    listADT list3 = map(list1, doble);
  
    elemType elem = next(list1);
    
    printf("OK!\n");
    return 0;
}
