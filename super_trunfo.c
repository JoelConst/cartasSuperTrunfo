#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para representar uma carta do jogo Super Trunfo - Países
typedef struct {
    char estado;          // Letra do estado (A-H)
    char codigo[4];       // Código único da carta (ex: A01, B02)
    char nome[50];        // Nome da cidade
    int populacao;        // População da cidade
    float area;           // Área da cidade em km²
    float pib;            // PIB da cidade em bilhões
    int pontos_turisticos;// Número de pontos turísticos
    float densidade_populacional; // Habitantes por km²
    float pib_per_capita;         // PIB per capita (PIB / População)
} Carta;

// Função para cadastrar os dados de uma carta
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
    
    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculo da Densidade Populacional (População / Área)
    carta->densidade_populacional = carta->populacao / carta->area;

    // Cálculo do PIB per Capita (PIB / População)
    carta->pib_per_capita = carta->pib * 1000000000 / carta->populacao; // Convertendo PIB de bilhões para reais
}

// Função para exibir os dados de uma carta cadastrada
void exibirCarta(const Carta *carta) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da cidade: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta->pib_per_capita);
    printf("----------------------\n");
}

int main() {
    // Criando duas cartas para o jogo
    Carta carta1, carta2;

    // Cadastro das duas cartas
    printf("\n--- Cadastro da Carta 1 ---\n");
    cadastrarCarta(&carta1);
    
    printf("\n--- Cadastro da Carta 2 ---\n");
    cadastrarCarta(&carta2);

    // Exibição das cartas cadastradas com os cálculos realizados
    printf("\n=== Cartas Cadastradas ===\n");
    exibirCarta(&carta1);
    exibirCarta(&carta2);

    return 0;
}
