#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    // Definindo o tamanho do tabuleiro (5x5 só para facilitar no nível Novato)
    int linhas = 5, colunas = 5;

    // Inicializando o tabuleiro vazio
    int tabuleiro[5][5] = {0};

    // Variáveis para o posicionamento dos navios
    int x_vertical = 1, y_vertical = 2; // posição inicial do navio vertical
    int tamanho_vertical = 3; // tamanho do navio

    int x_horizontal = 4, y_horizontal = 0; // posição inicial do navio horizontal
    int tamanho_horizontal = 4; // tamanho do navio

    // Posicionando o navio vertical
    for (int i = 0; i < tamanho_vertical; i++) {
        tabuleiro[x_vertical + i][y_vertical] = 1;
    }

    // Posicionando o navio horizontal
    for (int j = 0; j < tamanho_horizontal; j++) {
        tabuleiro[x_horizontal][y_horizontal + j] = 2;
    }

    // Exibindo as coordenadas ocupadas pelos navios
    printf("Coordenadas do Navio Vertical:\n");
    for (int i = 0; i < tamanho_vertical; i++) {
        printf("(%d, %d)\n", x_vertical + i, y_vertical);
    }

    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int j = 0; j < tamanho_horizontal; j++) {
        printf("(%d, %d)\n", x_horizontal, y_horizontal + j);
    }

    return 0;
}
}

#include <stdio.h>

int main() {
    int linhas = 10, colunas = 10;
    int tabuleiro[10][10] = {0}; // inicializa tudo com 0

    // ---- Navio 1: Vertical ----
    int x_vertical = 1, y_vertical = 2; 
    int tamanho_vertical = 4; 
    for (int i = 0; i < tamanho_vertical; i++) {
        tabuleiro[x_vertical + i][y_vertical] = 3;
    }

    // ---- Navio 2: Horizontal ----
    int x_horizontal = 6, y_horizontal = 4; 
    int tamanho_horizontal = 5; 
    for (int j = 0; j < tamanho_horizontal; j++) {
        tabuleiro[x_horizontal][y_horizontal + j] = 3;
    }

    // ---- Navio 3: Diagonal (↘) ----
    int x_diag1 = 0, y_diag1 = 0;
    int tamanho_diag1 = 4;
    for (int k = 0; k < tamanho_diag1; k++) {
        tabuleiro[x_diag1 + k][y_diag1 + k] = 3;
    }

    // ---- Navio 4: Diagonal (↙) ----
    int x_diag2 = 0, y_diag2 = 9;
    int tamanho_diag2 = 4;
    for (int k = 0; k < tamanho_diag2; k++) {
        tabuleiro[x_diag2 + k][y_diag2 - k] = 3;
    }

    // ---- Exibição do Tabuleiro Completo ----
    printf("=== Tabuleiro 10x10 ===\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

#define N 5 // tamanho fixo 5x5 para exibir habilidades

// Função para exibir matriz
void mostrarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int cone[N][N] = {0};
    int cruz[N][N] = {0};
    int octaedro[N][N] = {0};

    // ==== Padrão Cone ====
    // Formato piramidal com base maior
    for (int i = 0; i < N; i++) {
        for (int j = N/2 - i; j <= N/2 + i; j++) {
            if (j >= 0 && j < N)
                cone[i][j] = 1;
        }
    }

    // ==== Padrão Cruz ====
    for (int i = 0; i < N; i++) {
        cruz[i][N/2] = 1; // coluna central
    }
    for (int j = 0; j < N; j++) {
        cruz[N/2][j] = 1; // linha central
    }

    // ==== Padrão Octaedro ====
    int centro = N/2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ==== Exibição das Matrizes ====
    printf("Habilidade Cone:\n");
    mostrarMatriz(cone);

    printf("Habilidade Cruz:\n");
    mostrarMatriz(cruz);

    printf("Habilidade Octaedro:\n");
    mostrarMatriz(octaedro);

    return 0;
}