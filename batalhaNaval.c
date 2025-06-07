#include <stdio.h>

// Definições fixas do tabuleiro e navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posições iniciais dos navios (pré-definidas conforme simplificação do desafio)
    int linha_navio_horizontal = 0; // linha onde o navio horizontal começa
    int coluna_navio_horizontal = 1; // coluna onde o navio horizontal começa

    int linha_navio_vertical = 6; // linha onde o navio vertical começa
    int coluna_navio_vertical = 4; // coluna onde o navio vertical começa

    // Validação dos limites para o navio horizontal
    if (coluna_navio_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Posiciona o navio horizontal no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação dos limites para o navio vertical
    if (linha_navio_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Validação para evitar sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao) {
            printf("Erro: sobreposição detectada com o navio horizontal.\n");
            return 1;
        } else {
            // Posiciona o navio vertical no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
            }
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Impressão do tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}