#include <stdio.h>
void resta( const int v1[], const int v2[], int v3[] );
int pertenece( int valor, const int v[] );

int main(){
  int v1[] = {1, 9, 2, 6, 3, 6, -1};
  int v2[] = {3, 2, 8, 2, -1};
  int v3[10];
  resta( v1, v1, v3 );
  for( int i = 0; v3[i] != -1; i++ )
    printf("%d ", v3[i] );
  putchar('\n');
}

void resta( const int v1[], const int v2[], int v3[] ){
  int agrego = 0;
  for( int i = 0; v1[i] != -1; i++ )
    if( !pertenece( v1[i], v2 ) )
      v3[agrego++] = v1[i];
  v3[agrego] = -1;
}

int pertenece( int valor, const int v[] ){
  int encontre = 0;
  for( int i = 0; v[i] != -1 && !encontre; i++ ){
    if( v[i] == valor )
      encontre = 1;
  }
  return encontre;
}
