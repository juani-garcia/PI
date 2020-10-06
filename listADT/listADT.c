//
//  listADT.c
//  listADT
//

#include "listADT.h"

typedef struct node {
    elemType elem;
    struct node * tail;
} node;

typedef struct listCDT {
    struct node * first;
    size_t size;
    node * current;
} listCDT;

listADT newList() {
    return calloc(1, sizeof(listCDT));
}

static void freeRec(node * first) {
    if (first == NULL)
        return;
    freeRec(first->tail);
    free(first);
}

void freeList(listADT list) {
    freeRec(list->first);
    free(list);
}

void freeListIter(listADT list) {
    node * aux = list->first;
    while ( aux != NULL) {
        ////
    }
    free(list);
}

int isEmpty(const listADT list) {
    return list->first == NULL;
    // return list->size == 0;
}

size_t size(const listADT list) {
    return list->size;
}

static node * addRec(node * first, elemType elem, int *ok) {
    int c;
    if(first == NULL || ( c = compare(elem, first->elem)) < 0 ) {
        node * aux = malloc(sizeof(node));
        aux->elem = elem;
        aux->tail = first;
        *ok = 1;
        return aux;
    }
    if ( c > 0)
        first->tail = addRec(first->tail, elem, ok);
    return first;
}

int add(listADT list, elemType elem) {
    int ok=0;   // size_t sizeOld = list->size
    list->first = addRec(list->first, elem, &ok);  // &list->size
    if ( ok )     // return sizeOld != list->size
        list->size++;
    return ok;
}

static node * removeRec(node * first, elemType elem, int *ok) {
    int c;
    if ( first == NULL || ( c = compare(elem, first->elem)) < 0 ) {
        return first;
    }
    if ( c == 0) {
        *ok=1;
        node * aux = first->tail;
        free(first);
        return aux;
    }
    first->tail = removeRec(first->tail, elem, ok);
    return first;
}


int removeList(listADT list, elemType elem) {
    int ok=0;   // size_t sizeOld = list->size
       list->first = removeRec(list->first, elem, &ok);  // &list->size
       if ( ok )     // return sizeOld != list->size
           list->size--;
       return ok;
}

static elemType getRec(node * first, size_t idx) {
    if ( idx == 0)
        return first->elem;
    return getRec(first->tail, idx-1);
}

elemType get(const listADT list, size_t idx) {
    if ( idx >= list->size) {
        exit(1);
    }
    return getRec(list->first, idx);
}

static int containsRec(node * first, elemType elem) {
    if ( first == NULL)
        return 0;
    int c = compare(first->elem, elem);
    if ( c == 0)
        return 1;
    if ( c > 0)
        return 0;
    return containsRec(first->tail, elem);
}

int contains(const listADT list, elemType elem) {
    return containsRec(list->first, elem);
}

elemType * toArray(const listADT list) {
    elemType * ans = malloc(sizeof(elemType) * list->size);
    // no les pedimos validar malloc
    node * aux = list->first;
    int i=0;
    while ( aux != NULL) {
        ans[i++] = aux->elem;
        aux = aux->tail;
    }

    return ans;
}

elemType * toArray2(const listADT list) {
    elemType * ans = malloc(sizeof(elemType) * list->size);
    // no les pedimos validar malloc
    node * aux = list->first;
    for(int i=0; i < list->size; i++, aux = aux->tail) {
        ans[i] = aux->elem;
    }

    return ans;
}


int hasNext(const listADT list) {
    return list->current != NULL;
}

void toBegin(listADT list) {
    list->current = list->first;
}

elemType next(listADT list) {
    if ( ! hasNext(list))
        exit(1);
    elemType elem = list->current->elem;
    list->current = list->current->tail;
    return elem;
}

int fromArray(listADT list, const elemType v[], size_t dim) {
    int count=0;
    for(size_t i =0; i < dim; i++)
        count += add(list, v[i]);
    return count;
}

listADT map(const listADT source, elemType (* pfun)(elemType elem)){
    listADT target = newList();
    toBegin(source);
    elemType new;
    while( hasNext(source) ){
        new = next(source);
        new  = pfun( new );
        add( target, new );
    }
    return target;
}

listADT subList(const listADT source, int (* criteria)(elemType elem)) {
    listADT target = newList();
    toBegin(source);
    elemType new;
    while( hasNext(source) ){
      new = next(source);
      if( criteria( new ))
        add( target, new );
    }
    return target;
}
