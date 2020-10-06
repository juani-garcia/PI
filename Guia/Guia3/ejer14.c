#include <stdio.h>

int main(){
  int min = 'Z', mayus = 0, minus = 0, new, c, save;
  while((c = getchar()) != EOF) {
    if('a' <= c && c <= 'z'){
      minus++;
      new = c - 'a' + 'A';
    }else if(('A' <= c && c <= 'Z')){
      mayus++;
      new = c;
    }else if(c != ' ')
    break;
    if(new < min){
      min = new;
      save = c;
    }
  }
  printf("El menor fue %c.\nHay %d mayusculas y %d minusculas.\n", save, mayus, minus);
}
