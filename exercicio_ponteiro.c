#include <stdio.h>

int main(void) {
  int array[5];
  int *ptr;
  int i;

  ptr = array;

  printf("Digite 5 valores inteiros:\n");
  for (i = 0; i < 5; i++) {
      scanf("%d", ptr + i);
  }

  printf("\n------------------------------\n");
  
  printf("\nO dobro de cada valor lido:\n");
  for (i = 0; i < 5; i++) {
      printf("%d\n", *(ptr + i) * 2);
  }  
  return 0;
}