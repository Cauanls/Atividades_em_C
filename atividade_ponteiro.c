#include <stdio.h>

void imprimirArray(int *array, int tamanho) {
    int *ptr = array;

    printf("Conteúdo do array:\n");
    while (tamanho > 0) {
        printf("%d\n", *ptr);
        ptr++;
        tamanho--;
    }
}

int main(void) {
  
  int array[] = {12, 5, 81, 25, 40};
  int tamanho = sizeof(array) / sizeof(array[0]);

  imprimirArray(array, tamanho);
  
  return 0;
}