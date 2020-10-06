#include <stdio.h>

void eliminaEspacio( char stg[] ){
  int j = 0, i = 0;
  for(; stg[i] != 0; i++){
    if( stg[i] != ' ' || stg[i+1] != ' ' )
      stg[j++] = stg[i];
  }
  stg[j] = 0;
}

int main(){
  char stg[] = "Hola mundo     como estan    .";
  printf("%s\n", stg );
  eliminaEspacio( stg );
  printf("%s\n", stg);
}
