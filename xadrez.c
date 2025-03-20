#include <stdio.h>

#define BISPO_MOV 5
#define TORRE_MOV 5
#define RAINHA_MOV 8

// Função recursiva para movimentação do Bispo
void mover_bispo(int mov) {
    if (mov == 0) return;
    printf("Cima-Direita\n");
    mover_bispo(mov - 1);
}

// Função recursiva para movimentação da Torre
void mover_torre(int mov) {
    if (mov == 0) return;
    printf("Direita\n");
    mover_torre(mov - 1);
}

// Função recursiva para movimentação da Rainha
void mover_rainha(int mov) {
    if (mov == 0) return;
    printf("Esquerda\n");
    mover_rainha(mov - 1);
}

// Movimentação do Cavalo utilizando múltiplas variáveis e loops
void mover_cavalo() {
    int i = 0, j = 0;
    while (i < 2) { // Duas casas para cima
        printf("Cima\n");
        i++;
    }
    do { // Uma casa para a direita
        printf("Direita\n");
        j++;
    } while (j < 1);
}

int main() {
    printf("Movimentacao do Bispo:\n");
    mover_bispo(BISPO_MOV);
    
    printf("\nMovimentacao da Torre:\n");
    mover_torre(TORRE_MOV);
    
    printf("\nMovimentacao da Rainha:\n");
    mover_rainha(RAINHA_MOV);
    
    printf("\nMovimentacao do Cavalo:\n");
    mover_cavalo();
    
    return 0;
}
