#include <stdio.h>
#include <stdlib.h>

struct Restaurante {
    char nome[100];
    char endereco[100];
    float precoMedio;
    char tipoComida[100];
    struct Restaurante* proximo;
};

struct Restaurante* solicitarDados() {
    struct Restaurante* restaurante = (struct Restaurante*)malloc(sizeof(struct Restaurante));
    
    printf("Digite o nome do restaurante: ");
    scanf("%s", restaurante->nome);
    
    printf("Digite o endereço do restaurante: ");
    scanf("%s", restaurante->endereco);
    
    printf("Digite o preço médio do restaurante: ");
    scanf("%f", &(restaurante->precoMedio));
    
    printf("Digite o tipo de comida do restaurante: ");
    scanf("%s", restaurante->tipoComida);
    
    restaurante->proximo = NULL;
    
    return restaurante;
}

void listarDados(struct Restaurante* lista) {
    struct Restaurante* atual = lista;
    
    if (atual == NULL) {
        printf("A lista de restaurantes está vazia.\n");
        return;
    }
    
    printf("Lista de restaurantes:\n");
    
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Endereço: %s\n", atual->endereco);
        printf("Preço Médio: %.2f\n", atual->precoMedio);
        printf("Tipo de Comida: %s\n", atual->tipoComida);
        printf("------------------------\n");
        atual = atual->proximo;
    }
}

int main() {
    struct Restaurante* lista = NULL;
    struct Restaurante* novoRestaurante = NULL;
    int opcao;
    
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar restaurante\n");
        printf("2 - Listar restaurantes\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                novoRestaurante = solicitarDados();
                if (lista == NULL) {
                    lista = novoRestaurante;
                } else {
                    struct Restaurante* atual = lista;
                    while (atual->proximo != NULL) {
                        atual = atual->proximo;
                    }
                    atual->proximo = novoRestaurante;
                }
                printf("Restaurante adicionado com sucesso!\n");
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
  
    struct Restaurante* atual = lista;
    while (atual != NULL) {
        struct Restaurante* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    return 0;
}