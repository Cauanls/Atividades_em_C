#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char proprietario[100];
    char combustivel[20];
    char modelo[100];
    char cor[100];
    char chassi[100];
    int ano;
    char placa[20];
} Veiculo;


typedef struct No {
    Veiculo veiculo;
    struct No* proximo;
} No;

void inserirVeiculo(No** lista, Veiculo veiculo) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->veiculo = veiculo;
    novoNo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novoNo;
    } else {
        No* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}


void listarProprietariosDiesel2010(No* lista) {
    No* atual = lista;

    while (atual != NULL) {
        if (atual->veiculo.ano >= 2010 && strcmp(atual->veiculo.combustivel, "diesel") == 0) {
            printf("Proprietário: %s\n", atual->veiculo.proprietario);
        }
        atual = atual->proximo;
    }
}


void listarPlacasJ(No* lista) {
    No* atual = lista;

    while (atual != NULL) {
        if (atual->veiculo.placa[0] == 'J' &&
            (atual->veiculo.placa[6] == '0' || atual->veiculo.placa[6] == '2' ||
             atual->veiculo.placa[6] == '4' || atual->veiculo.placa[6] == '7')) {
            printf("Placa: %s, Proprietário: %s\n", atual->veiculo.placa, atual->veiculo.proprietario);
        }
        atual = atual->proximo;
    }
}

int ehVogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


void listarModeloCorPlacas(No* lista) {
    No* atual = lista;

    while (atual != NULL) {
        if (ehVogal(atual->veiculo.placa[1])) {
            int somaNumeros = atoi(atual->veiculo.placa + 3); 
            if (somaNumeros % 2 == 0) {
                printf("Modelo: %s, Cor: %s\n", atual->veiculo.modelo, atual->veiculo.cor);
            }
        }
        atual = atual->proximo;
    }
}


void trocarProprietario(No* lista, char* chassi, char* novoProprietario) {
    No* atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->veiculo.chassi, chassi) == 0) {
            int i;
            int possuiZero = 0;
            for (i = 0; i < 7; i++) {
                if (atual->veiculo.placa[i] == '0') {
                    possuiZero = 1;
                    break;
                }
            }

            if (!possuiZero) {
                strcpy(atual->veiculo.proprietario, novoProprietario);
                printf("Proprietário alterado com sucesso.\n");
            } else {
                printf("O carro com o chassi fornecido possui dígito zero na placa. "
                       "A troca de proprietário não é permitida.\n");
            }
            return;
        }
        atual = atual->proximo;
    }

    printf("Carro com o chassi fornecido não encontrado.\n");
}

int main() {
    No* lista = NULL;

    Veiculo veiculo1;
    strcpy(veiculo1.proprietario, "Proprietário 1");
    strcpy(veiculo1.combustivel, "diesel");
    strcpy(veiculo1.modelo, "Modelo 1");
    strcpy(veiculo1.cor, "Cor 1");
    strcpy(veiculo1.chassi, "Chassi 1");
    veiculo1.ano = 2015;
    strcpy(veiculo1.placa, "JAB1234");
    inserirVeiculo(&lista, veiculo1);

    Veiculo veiculo2;
    strcpy(veiculo2.proprietario, "Proprietário 2");
    strcpy(veiculo2.combustivel, "gasolina");
    strcpy(veiculo2.modelo, "Modelo 2");
    strcpy(veiculo2.cor, "Cor 2");
    strcpy(veiculo2.chassi, "Chassi 2");
    veiculo2.ano = 2012;
    strcpy(veiculo2.placa, "JAD5678");
    inserirVeiculo(&lista, veiculo2);

    Veiculo veiculo3;
    strcpy(veiculo3.proprietario, "Proprietário 3");
    strcpy(veiculo3.combustivel, "diesel");
    strcpy(veiculo3.modelo, "Modelo 3");
    strcpy(veiculo3.cor, "Cor 3");
    strcpy(veiculo3.chassi, "Chassi 3");
    veiculo3.ano = 2008;
    strcpy(veiculo3.placa, "JBC9876");
    inserirVeiculo(&lista, veiculo3);

    printf("Proprietários de carros do ano de 2010 ou posterior e movidos a diesel:\n");
    listarProprietariosDiesel2010(lista);

    printf("\nPlacas que começam com a letra J e terminam com 0, 2, 4 ou 7 e seus respectivos proprietários:\n");
    listarPlacasJ(lista);

    printf("\nModelo e cor dos veículos cujas placas possuem como segunda letra uma vogal "
           "e cuja soma dos valores numéricos fornece um número par:\n");
    listarModeloCorPlacas(lista);

    printf("\nTrocar proprietário com o fornecimento do número do chassi:\n");
    trocarProprietario(lista, "Chassi 2", "Novo Proprietário");

    return 0;
}