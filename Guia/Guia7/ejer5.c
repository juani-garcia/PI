#include <stdio.h>
#include <string.h>

void separaCurso( char nombres[][20], const char * curso,
char cursog[][20], char cursoh[][20] ){
  int i = 0, j = 0, k = 0;
  while( nombres[k][0] ){
      if( curso[k] == 'G' )
        strcpy( cursog[i++], nombres[k++]);
      else
        strcpy( cursoh[j++], nombres[k++] );
  }
  cursog[i][0] = 0;
  cursoh[j][0] = 0;
}

int main(){
  char nombres[][20] = {"Juan", "Lucila", "Agustina", "Pablo", ""};
  char curso[] = "HGHG";
  char cursog[5][20], cursoh[5][20];
  separaCurso( nombres, curso, cursog, cursoh );
  printf("El curso G esta compuesto por : ");
  for( int i = 0; cursog[i][0]; i++ )
    printf("%s ", cursog[i] );
  putchar('\n');
  printf("El curso H esta compuesto por : ");
  for( int i = 0; cursoh[i][0]; i++ )
    printf("%s ", cursoh[i] );
  putchar('\n');
}
