#ifndef punto_h
#define punto_h

typedef struct moveToFrontCDT * moveToFrontADT;

typedef int elemType;

static int compare(elemType e1, elemType e2){
    return e1-e2;
}

moveToFrontADT newMoveToFront(?);

size_t add(moveToFrontADT moveToFront, elemType elem);

size_t size(moveToFrontADT moveToFront);

void toBegin(moveToFrontADT moveToFront);

int hasNext(moveToFrontADT moveToFront);

void toBegin(moveToFrontADT moveToFront);

int hasNext(moveToFrontADT moveToFront);

elemType next(moveToFrontADT moveToFront);

elemType * get(moveToFrontADT moveToFront, elemType elem);


#endif
