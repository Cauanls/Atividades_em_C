#include <stdio.h>

void maior_menor(int n1, int n2){
  int aux = 0;
  
  if(n2 > n1){
    aux = n2;
    n2 = n1;
    n1 = aux;
    printf("Maior: %d\nMenor: %d", n1, n2);
  }else{
    printf("Maior: %d\nMenor: %d", n1, n2);
  }
}

int main(void) {
  int x, y;
  int *z = NULL, *w = NULL;

  w = &x;
  z = &y;

  printf("Digite um numero para x: ");
  scanf("%d", w);

  printf("Digite um numero para y: ");
  scanf("%d", z);

  maior_menor(*w, *z);
  return 0;
}