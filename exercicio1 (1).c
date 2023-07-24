#include <stdio.h>

int main(void) {
  int i = 6, *inteiro = NULL;
  char c = 'f', *ch = NULL;
  double f = 4.5, *fl = NULL;
  
  inteiro = &i;
  ch = &c;
  fl = &f;
  
  printf("O numero inteiro antigo é %d\n", i);
  printf("O char antigo é %c\n", c);
  printf("O numero real antigo é %.2lf\n", f);
  printf("------------------------");
  
  printf("\nO endereco do numero antigo do numero inteiro é %p\n", inteiro);
  printf("O endereco char antigo é %p\n", ch);
  printf("O endereco numero real antigo é %p\n", fl);
  printf("------------------------");
  
  printf("\nAtualize o numero inteiro: ");
  scanf("%d", inteiro);
  printf("O numero atualizado de inteiro é %d\n", i);

  __fpurge(stdin);
  printf("\nAtualize o char: ");
  scanf("%[^\n]c", ch);
  printf("O char aualizado é %c\n", c);

  printf("\nAtualize o numero real: ");
  scanf("%lf", fl);
  printf("O numero real atualizado é %.2f\n", f);
  return 0;
}