#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TAM 10
#define TAM_HABIL 5  // Tamanho fixo da matriz de habilidade
#define ORIGEM_H 2   // Posição central da matriz 5x5

// Criação dinâmica da matriz de cone
void gerarCone(int cone[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (i >= j - ORIGEM_H && i >= ORIGEM_H - j) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Criação dinâmica da matriz de cruz
void gerarCruz(int cruz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (i == ORIGEM_H || j == ORIGEM_H) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Criação dinâmica da matriz de octaedro (losango)
void gerarOctaedro(int octaedro[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (abs(i - ORIGEM_H) + abs(j - ORIGEM_H) <= ORIGEM_H) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABIL][TAM_HABIL], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            int linhaTab = origemLinha - ORIGEM_H + i;
            int colTab = origemColuna - ORIGEM_H + j;
            if (linhaTab >= 0 && linhaTab < TAM && colTab >= 0 && colTab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0) {
                    tabuleiro[linhaTab][colTab] = 5;  // Marcar área de efeito
                }
            }
        }
    }
}

// Exibir tabuleiro com legenda visual
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Legenda: 0=Água, 3=Navio, 5=Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionar alguns navios como referência
    int navios[4][3][2] = {
        {{1, 2}, {1, 3}, {1, 4}}, // horizontal
        {{5, 7}, {6, 7}, {7, 7}}, // vertical
        {{3, 3}, {4, 4}, {5, 5}}, // diagonal principal
        {{0, 9}, {1, 8}, {2, 7}}  // diagonal secundária
    };

    for (int n = 0; n < 4; n++) {
        for (int i = 0; i < 3; i++) {
            int l = navios[n][i][0];
            int c = navios[n][i][1];
            tabuleiro[l][c] = 3;
        }
    }

    // Criar e aplicar habilidades
    int cone[TAM_HABIL][TAM_HABIL], cruz[TAM_HABIL][TAM_HABIL], octaedro[TAM_HABIL][TAM_HABIL];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicar as habilidades em diferentes pontos do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);   // Octaedro em (7,2)

    // Mostrar o resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}