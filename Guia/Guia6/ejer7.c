#include <stdio.h>

void unir( const int vec1[], const int vec2[], int vec3[]);

int main(){
  const int vec1[] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
  const int vec2[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 10, 2321, -1};
  int vec3[20];
  unir( vec1, vec2, vec3 );
  for( int i = 0; vec3[i] != -1; i++ )
    printf("%d ", vec3[i] );
  putchar('\n');
}

void unir( const int vec1[], const int vec2[], int vec3[]){
  int i = 0, j = 0, k = 0;
  while( vec1[i] != -1 && vec2[j] != -1 ){
    if( vec1[i] == vec2[j] ){
      vec3[k++] = vec1[i++]; j++;
    }else if( vec1[i] < vec2[j] && vec1[i] != -1 )
      vec3[k++] = vec1[i++];
    else if( vec1[i] > vec2[j] && vec2[j] != -1 )
      vec3[k++] = vec2[j++];
  }
  vec3[k] = -1;
}
