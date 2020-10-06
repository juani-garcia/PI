#include <stdio.h>
void interseccion( int vec1[], int vec2[], int vec3[] );

int main(){
  int vec1[] = {9, 9, 8, 6, 6, 5, 3, 1, -1};
  int vec2[] = {10, 9, 9, 9, 9, 9, 8, 6, 6, 3, 3, 3, -1};
  int vec3[10];
  interseccion( vec1, vec2, vec3 );
  for( int i = 0; vec3[i] != -1; i++ )
    printf("%d ", vec3[i] );
  putchar('\n');
}

void interseccion( int vec1[], int vec2[], int vec3[] ){
  int i = 0, j = 0, agrego = 0;
  while( vec1[i] != -1 && vec2[j] != -1 ){
    if( vec1[i] == vec2[j] ){
      if( !agrego || vec3[agrego - 1] != vec1[i] )
        vec3[agrego++] = vec1[i];
      i++; j++;
    }else{
      if( vec1[i] > vec2[j] )
        i++;
      else
        j++;
    }
  }
  vec3[agrego] = -1;
}
