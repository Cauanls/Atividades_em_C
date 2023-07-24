#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    char sintomas[100];
    char historico_medico[200];
} Anamnese;

int main() {
    int numRegistros;
    printf("Quantos registros de anamnese deseja criar? ");
    scanf("%d", &numRegistros);

    Anamnese* registros = (Anamnese*) malloc(numRegistros * sizeof(Anamnese));

    for (int i = 0; i < numRegistros; i++) {
        printf("\n--- Registro %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", registros[i].nome);
        printf("Idade: ");
        scanf("%d", &registros[i].idade);
        printf("Sintomas: ");
        scanf(" %[^\n]s", registros[i].sintomas);
        printf("Histórico médico: ");
        scanf(" %[^\n]s", registros[i].historico_medico);
    }

    printf("\n--- Registros de Anamnese ---\n");
    for (int i = 0; i < numRegistros; i++) {
        printf("\n--- Registro %d ---\n", i + 1);
        printf("Nome: %s\n", registros[i].nome);
        printf("Idade: %d\n", registros[i].idade);
        printf("Sintomas: %s\n", registros[i].sintomas);
        printf("Histórico médico: %s\n", registros[i].historico_medico);
    }

    free(registros);

    return 0;
}