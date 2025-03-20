#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função recursiva para movimentação do Bispo
void moverBispo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int dx, int dy) {
    if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) return;
    tabuleiro[x][y] = 'B';
    moverBispo(tabuleiro, x + dx, y + dy, dx, dy);
}

// Movimentação da Torre
void moverTorre(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[x][i] = 'T';
        tabuleiro[i][y] = 'T';
    }
}

// Movimentação da Rainha
void moverRainha(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    moverTorre(tabuleiro, x, y);
    moverBispo(tabuleiro, x, y, -1, -1);
    moverBispo(tabuleiro, x, y, -1, 1);
    moverBispo(tabuleiro, x, y, 1, -1);
    moverBispo(tabuleiro, x, y, 1, 1);
}

// Movimentação do Cavalo
void moverCavalo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int movimentos[8][2] = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
    };
    for (int i = 0; i < 8; i++) {
        int nx = x + movimentos[i][0];
        int ny = y + movimentos[i][1];
        if (nx >= 0 && nx < TAMANHO_TABULEIRO && ny >= 0 && ny < TAMANHO_TABULEIRO) {
            tabuleiro[nx][ny] = 'C';
        }
    }
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializando tabuleiro vazio
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '.';
        }
    }
    
    // Testando a movimentação
    printf("Movimentação do Bispo:\n");
    moverBispo(tabuleiro, 4, 4, -1, -1);
    moverBispo(tabuleiro, 4, 4, -1, 1);
    moverBispo(tabuleiro, 4, 4, 1, -1);
    moverBispo(tabuleiro, 4, 4, 1, 1);
    exibirTabuleiro(tabuleiro);
    
    // Resetando tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = '.';
    
    printf("Movimentação da Torre:\n");
    moverTorre(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);
    
    // Resetando tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = '.';
    
    printf("Movimentação da Rainha:\n");
    moverRainha(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);
    
    // Resetando tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = '.';
    
    printf("Movimentação do Cavalo:\n");
    moverCavalo(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);
    
    return 0;
}