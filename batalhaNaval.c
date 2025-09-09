#include <stdio.h>

int main() {
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