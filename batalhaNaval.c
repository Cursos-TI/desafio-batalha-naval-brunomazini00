#include <stdio.h>

#define TAMANHO 10 // Constante de tamanho para facilitar mudanças futuras
#define TAMANHO_NAVIO 3 // Constante para tamanho do Navio
#define AGUA 0 //Constate para representar água (vazia)
#define NAVIO 3 //Constante para respresentar posição ocupada pelo navio

int main() {

    int tabuleiro[TAMANHO][TAMANHO] = {AGUA}; // Inicialização da Matriz 10x10 com posições {AGUA}
    int i, j, k; // Variáveis para controlar os loops

    // Declaração dos Navios (Vetores unidimensionais)
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // --- POSICIONAMENTO DOS NAVIOS ---

    // Navio 1 - Horizontal
    int linhaNavio1 = 2;
    int colunaNavio1 = 2;

    // VALIDAÇÃO 1: verificação se o navio cabe no limite horizontal
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // VALIDAÇÃO 2: verificação se a posição já esta ocupada
            if (tabuleiro[linhaNavio1][colunaNavio1 + k] == AGUA) {
                tabuleiro[linhaNavio1][colunaNavio1 + k] = navioHorizontal[k];
            } else {
                printf("Erro: Sobreposição detectada no navio horizontal na posição %d,%d!\n", linhaNavio1, colunaNavio1 + k);
            }
        }
    } else {
        printf("Erro: Navio Horizontal ultrapassa o limite do tabuleiro!\n");
    }

    // Navio 2 - Vertical
    int linhaNavio2 = 5;
    int colunaNavio2 = 8;

    // VALIDAÇÃO 1: verificação se o navio cabe no limite vertical
    if (linhaNavio2 + TAMANHO_NAVIO <= TAMANHO) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // VALIDAÇÃO 2: verificação se a posição já esta ocupada
            if (tabuleiro[linhaNavio2 + k][colunaNavio2] == AGUA) {
                tabuleiro[linhaNavio2 + k][colunaNavio2] = navioVertical[k];
            } else {
                printf("Erro: Sobreposição detectada no navio vertical na posição %d,%d!\n", linhaNavio2 + k, colunaNavio2);
            }
        }
    } else {
        printf("Erro: Navio Vertical ultrapassa o limite do tabuleiro!\n");
    }

    // Navio 3 - Diagonal 
int linhaNavio3 = 5;
int colunaNavio3 = 3;

if (linhaNavio3 + TAMANHO_NAVIO <= TAMANHO && colunaNavio3 + TAMANHO_NAVIO <= TAMANHO) {
    int sobreposicao = 0;
    for (k = 0; k < TAMANHO_NAVIO; k++) {
        if (tabuleiro[linhaNavio3 + k][colunaNavio3 + k] != AGUA) {
            sobreposicao = 1;
            printf("Erro: Sobreposição detectada no navio diagonal na posição %d,%d!\n", 
                   linhaNavio3 + k, colunaNavio3 + k);
        }
    }

    // Posiciona o navio somente se não houver sobreposição
    if (sobreposicao == 0) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            tabuleiro[linhaNavio3 + k][colunaNavio3 + k] = NAVIO;
        }
    }

} else {
    printf("Erro: Navio diagonal ultrapassa o limite do tabuleiro!\n");
}

// Navio 4 - Diagonal ↙
int linhaNavio4 = 2;
int colunaNavio4 = 7;

if (linhaNavio4 + TAMANHO_NAVIO <= TAMANHO && colunaNavio4 - (TAMANHO_NAVIO - 1) >= 0) {
    int sobreposicao = 0;
    for (k = 0; k < TAMANHO_NAVIO; k++) {
        if (tabuleiro[linhaNavio4 + k][colunaNavio4 - k] != AGUA) {
            sobreposicao = 1;
            printf("Erro: Sobreposição detectada no navio diagonal na posição %d,%d!\n", 
                   linhaNavio4 + k, colunaNavio4 - k);
        }
    }

    // Posiciona o navio somente se não houver sobreposição
    if (sobreposicao == 0) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            tabuleiro[linhaNavio4 + k][colunaNavio4 - k] = NAVIO;
        }
    }

} else {
    printf("Erro: Navio diagonal ultrapassa o limite do tabuleiro!\n");
}
    


    // --- Exibição do Tabuleiro ---
    printf("\n*************** BATALHA NAVAL ***************\n");
    printf("   A B C D E F G H I J\n"); // Cabeçalho das colunas

    // Loop Externo (Linhas)
    for (i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Cabeçalho das linhas
        // Loop Interno (Colunas)
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}