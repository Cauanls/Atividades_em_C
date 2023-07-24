#include <stdio.h> 
#include <stdlib.h> 

typedef struct { 
int codigo; 
char descricao[50]; 
int quant; 
float valor; 

} Produto; 

typedef struct { 
Produto *p; 
int tam; 

} Estoque;

Estoque inicializar() { 
  Estoque estoque; 
  estoque.p = NULL; 
  estoque.tam = 0; 
  
  return estoque; 
} 

void adcionar(Estoque *estoque) {
Produto produto; 

  printf("Digite o código do produto: "); 
  scanf("%d", &produto.codigo); 
  
  printf("Digite a descrição do produto: "); 
  scanf(" %[^\n]s", produto.descricao); 
  
  printf("Digite a quantidade do produto: "); 
  scanf("%d", &produto.quant); 
  
  printf("Digite o valor do produto: "); 
  scanf("%f", &produto.valor); 
  
  estoque->tam++; 
  estoque->p = realloc(estoque->p, estoque->tam * sizeof(Produto));          
  estoque->p[estoque->tam - 1] = produto; 
  printf("Produto adicionado com sucesso!\n"); 
  
} 

void exibir(Estoque estoque) { 
  printf("RELATÓRIO DE PRODUTOS\n"); 
  
  for (int i = 0; i < estoque.tam; i++) { 
    printf("Código: %d\n", estoque.p[i].codigo); 
    printf("Descrição: %s\n", estoque.p[i].descricao); 
    printf("Quantidade: %d\n", estoque.p[i].quant); 
    printf("Valor: R$ %.2f\n", estoque.p[i].valor); 
    printf("-----------------------\n"); 
  } 
  
} 

void pesquisar(Estoque estoque) { 
  int cod_prod; 
  int encontrado = 0; 
  
  printf("Digite o código do produto: "); 
  scanf("%d", &cod_prod); 
  
  for (int i = 0; i < estoque.tam; i++) { 
    if (estoque.p[i].codigo == cod_prod) { 
      printf("Código: %d\n", estoque.p[i].codigo); 
      
      printf("Descrição: %s\n", estoque.p[i].descricao); 
      
      printf("Quantidade: %d\n", estoque.p[i].quant); 
      
      printf("Valor: R$ %.2f\n", estoque.p[i].valor);       
      printf("-----------------------\n"); 
      encontrado = 1;
      break; 
    } 
  } 
  
  if (!encontrado) { 
    printf("Produto não encontrado.\n"); 
  } 
  
} 

void remover(Estoque *estoque) { 
  int cod_remov; 
  int encontrado = 0; 
  
  printf("Digite o código do produto a ser removido: "); 
  scanf("%d", &cod_remov); 
  
  for (int i = 0; i < estoque->tam; i++) { 
    if (estoque->p[i].codigo == cod_remov) { 
      for (int j = i; j < estoque->tam - 1; j++) { 
        estoque->p[j] = estoque->p[j + 1]; 
      } 
      
      estoque->tam--; 
      estoque->p = realloc(estoque->p, estoque->tam * sizeof(Produto)); 
      printf("Produto removido com sucesso!\n"); 
      encontrado = 1; 
      break; 
    } 
  } 
  
  if (!encontrado) { 
    printf("Produto não encontrado.\n");
  } 
} 

void Menu() { 
  printf("\n----- MENU -----\n"); 
  printf("1 - Cadastrar produto\n"); 
  printf("2 - Consultar produtos\n"); 
  printf("3 - Gerar relatório de produtos\n"); 
  printf("4 - Remover produto\n"); 
  printf("0 - Sair\n"); 
  printf("------------------\n"); 
  printf("Digite a opção desejada: "); 
} 


int main() { 
  Estoque estoque = inicializar(); 
  int opcao; 
  do { 
    
    Menu(); 
    scanf("%d", &opcao); 
    
    switch (opcao) { 
      case 1: adcionar(&estoque); 
        break; 
      
      case 2: pesquisar(estoque); 
        break; 
      
      case 3: exibir(estoque); 
        break; 
      
      case 4: remover(&estoque); 
        break; 
      
      case 0: 
        printf("Saindo do programa...\n"); 
        break; 
      
      default: 
        printf("Opção inválida. Tente novamente.\n");
    } 
  } while (opcao != 0); 
  
  free(estoque.p); 
  
  return 0; 
}