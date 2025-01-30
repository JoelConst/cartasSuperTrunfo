#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);
    
    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta->pontos_turisticos);
}

void exibirCarta(const Carta *carta) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da cidade: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("----------------------\n");
}

void editarCarta(Carta *carta) {
    int opcao;
    
    printf("\nO que você gostaria de editar?\n");
    printf("1. Estado\n");
    printf("2. Código\n");
    printf("3. Nome da cidade\n");
    printf("4. População\n");
    printf("5. Área\n");
    printf("6. PIB\n");
    printf("7. Pontos turísticos\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a nova letra do estado (A-H): ");
            scanf(" %c", &carta->estado);
            break;
        case 2:
            printf("Digite o novo código da carta (ex: A01): ");
            scanf("%s", carta->codigo);
            break;
        case 3:
            printf("Digite o novo nome da cidade: ");
            scanf(" %[^\n]", carta->nome);
            break;
        case 4:
            printf("Digite a nova população: ");
            scanf("%d", &carta->populacao);
            break;
        case 5:
            printf("Digite a nova área da cidade (em km²): ");
            scanf("%f", &carta->area);
            break;
        case 6:
            printf("Digite o novo PIB da cidade: ");
            scanf("%f", &carta->pib);
            break;
        case 7:
            printf("Digite o novo número de pontos turísticos: ");
            scanf("%d", &carta->pontos_turisticos);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void excluirCarta(Carta *cartas, int *numCartas, int indice) {
    // Shift cards after the deleted one
    for (int i = indice; i < *numCartas - 1; i++) {
        cartas[i] = cartas[i + 1];
    }
    (*numCartas)--;
}

int main() {
    int numCartas = 0, maxCartas = 10, opcao, i, indice;

    Carta *cartas = (Carta *)malloc(maxCartas * sizeof(Carta));
    if (cartas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    while (1) {
        printf("\n1. Cadastrar carta\n2. Exibir todas as cartas\n3. Editar carta\n4. Excluir carta\n5. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numCartas < maxCartas) {
                    cadastrarCarta(&cartas[numCartas]);
                    numCartas++;
                } else {
                    printf("Limite de cartas atingido!\n");
                }
                break;
            case 2:
                printf("\nCartas cadastradas:\n");
                for (i = 0; i < numCartas; i++) {
                    exibirCarta(&cartas[i]);
                }
                break;
            case 3:
                printf("Digite o índice da carta para editar (0 a %d): ", numCartas - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < numCartas) {
                    editarCarta(&cartas[indice]);
                } else {
                    printf("Índice inválido!\n");
                }
                break;
            case 4:
                printf("Digite o índice da carta para excluir (0 a %d): ", numCartas - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < numCartas) {
                    excluirCarta(cartas, &numCartas, indice);
                    printf("Carta excluída com sucesso!\n");
                } else {
                    printf("Índice inválido!\n");
                }
                break;
            case 5:
                free(cartas);
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
}
