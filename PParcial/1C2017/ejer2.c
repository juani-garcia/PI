#include <stdio.h>

int eliminar( char str[], int vec[], int dim );

int main(){
  char str[] = "Holaaaaa, Como estan???";
  int vec[5];
  int dim = eliminar( str, vec, 5 );
  printf( "%s\n%d\n", str, dim );
  for( int i = 0; i < dim; i++ )
    printf( "%d %s", vec[i], i == dim - 1? "\n" : "");
}

int eliminar( char str[], int vec[], int dim ){
  int i, elimino, agrego = 0;
  for( i = elimino = 0; str[i] && elimino < dim; i++ ){
    if( i == 0 || str[i] != str[i - 1] )
      str[agrego++] = str[i];
    else
      vec[elimino++] = i;
  }
  if( str[agrego] != 0 )
    while( str[i] )
      str[agrego++] = str[i++];
  str[agrego] = 0;
  return elimino;
}
