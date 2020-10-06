#include <stdio.h>

int incluido( int array1[], int dim1, int array2[], int dim2 ){
  int esta = 1;
  for( int i = 0; i < dim1; i++ ){
    esta = 0;
    for( int j = 0; j < dim2 && !esta; j++ )
      if( array1[i] == array2[j] )
        esta = 1;
    if (esta == 0)
      return 0;
  }
  return 1;
}

int doubleInc( int array1[], int dim1, int array2[], int dim2 ){
  if( incluido( array1, dim1, array2, dim2 ))
    return 1;
  if( incluido( array2, dim2, array1, dim1 ))
    return 2;
  else
    return 0;
}

int main(){
  int v1[] = { 1, 2, 3, 4 };
  int v2[] = { 1, 2, 3, 5, 6, 7, 8, 9 };
  printf("%d\n", doubleInc( v2, 9, v1, 4 ) );
}
