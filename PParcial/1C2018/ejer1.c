#include <stdio.h>

void eliminaRep( char * str1, char * str2 );

int main(){
  char str1[] = "tractor";
  char str2[] = "fraccion";
  eliminaRep( str1, str2 );
  printf("%s\n%s\n", str1, str2 );
}

void eliminaRep( char * str1, char * str2 ){
  int i = 0, j = 0, agrego1 = 0, agrego2 = 0;
  while( str1[i] || str2[j] ){
    if( str1[i] == str2[j] ){
      i++; j++;
    } else{
      if( str1[i] )
        str1[agrego1++] = str1[i++];
      if( str2[j] )
        str2[agrego2++] = str2[j++];
    }
  }
  str1[agrego1] = 0;
  str2[agrego2] = 0;
}
