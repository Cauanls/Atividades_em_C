#include <stdio.h>

struct Dieta {
    char nomeComida[100];
    float pesoPorcao;
    int numCalorias;
    struct Dieta* proximo;
};

struct Dieta* solicitarDados() {
    struct Dieta* comida = (struct Dieta*)malloc(sizeof(struct Dieta));
    
    printf("Digite o nome da comida: ");
    scanf("%s", comida->nomeComida);
    
    printf("Digite o peso da porção: ");
    scanf("%f", &(comida->pesoPorcao));
    
    printf("Digite o número de calorias: ");
    scanf("%d", &(comida->numCalorias));
    
    comida->proximo = NULL;
    
    return comida;
}

void listarDados(struct Dieta* lista) {
    struct Dieta* atual = lista;
    
    if (atual == NULL) {
        printf("A lista de alimentos está vazia.\n");
        return;
    }
    
    printf("Lista de alimentos:\n");
    
    while (atual != NULL) {
        printf("Nome da comida: %s\n", atual->nomeComida);
        printf("Peso da porção: %.2f\n", atual->pesoPorcao);
        printf("Número de calorias: %d\n", atual->numCalorias);
        printf("------------------------\n");
        atual = atual->proximo;
    }
}

int main(void) {

  struct Dieta* lista = NULL;
    struct Dieta* novaComida = NULL;
    int opcao;
    
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar alimento\n");
        printf("2 - Listar alimentos\n");
        printf("0 - Sair\nQual opção escolhida? ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                novaComida = solicitarDados();
                if (lista == NULL) {
                    lista = novaComida;
                } else {
                    struct Dieta* atual = lista;
                    while (atual->proximo != NULL) {
                        atual = atual->proximo;
                    }
                    atual->proximo = novaComida;
                }
                printf("Alimento adicionado com sucesso!\n");
                break;
            case 2:
                listarDados(lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        
    } while (opcao != 0);
    
    struct Dieta* atual = lista;
    while (atual != NULL) {
        struct Dieta* proximo = atual->proximo;
        
        free(atual);
        atual = proximo;
    }
  
  return 0;
}