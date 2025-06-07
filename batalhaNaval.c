#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se as posições estão livres
int posicoes_livres(int tabuleiro[10][10], int posicoes[3][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        if (tabuleiro[linha][coluna] != 0) {
            return 0; // Posição ocupada
        }
    }
    return 1; // Todas livres
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[10][10], int posicoes[3][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        tabuleiro[linha][coluna] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // === NAVIO 1: HORIZONTAL ===
    int navio1[3][2] = {
        {1, 2}, {1, 3}, {1, 4}
    };

    // === NAVIO 2: VERTICAL ===
    int navio2[3][2] = {
        {5, 7}, {6, 7}, {7, 7}
    };

    // === NAVIO 3: DIAGONAL PRINCIPAL (↘) ===
    int navio3[3][2] = {
        {3, 3}, {4, 4}, {5, 5}
    };

    // === NAVIO 4: DIAGONAL SECUNDÁRIA (↙) ===
    int navio4[3][2] = {
        {0, 9}, {1, 8}, {2, 7}
    };

    // Lista de todos os navios
    int* navios[] = {&navio1[0][0], &navio2[0][0], &navio3[0][0], &navio4[0][0]};

    // Posicionamento com validação
    for (int n = 0; n < 4; n++) {
        int (*navio)[2] = (int (*)[2]) navios[n];

        // Verifica se as posições estão dentro dos limites
        int valido = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int l = navio[i][0];
            int c = navio[i][1];
            if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
                valido = 0;
                break;
            }
        }

        // Verifica sobreposição
        if (valido && posicoes_livres(tabuleiro, navio)) {
            posicionar_navio(tabuleiro, navio);
        } else {
            printf("Erro ao posicionar navio %d: coordenadas inválidas ou sobreposição.\n", n + 1);
            return 1;
        }
    }

    // === Impressão do tabuleiro ===
    printf("Tabuleiro Final:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}