#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// --- Definições Globais ---
#define JOGADOR 'X' // Jogador Humano
#define IA 'O'      // Jogador Computador
#define VAZIO ' '   // Espaço Vazio

char tabuleiro[3][3]; // O tabuleiro 3x3

// --- Funções de Inicialização e Exibição ---

// Inicializa o tabuleiro com espaços vazios
void inicializar_tabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

// Exibe o tabuleiro no console
void exibir_tabuleiro() {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

// --- Funções de Lógica do Jogo ---

// Verifica se há movimentos disponíveis
bool tem_movimentos() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                return true;
            }
        }
    }
    return false;
}

// Verifica se um jogador venceu
int checar_vitoria() {
    // Checa Linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != VAZIO) {
            return (tabuleiro[i][0] == IA) ? 10 : -10;
        }
    }

    // Checa Colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != VAZIO) {
            return (tabuleiro[0][j] == IA) ? 10 : -10;
        }
    }

    // Checa Diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != VAZIO) {
        return (tabuleiro[0][0] == IA) ? 10 : -10;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != VAZIO) {
        return (tabuleiro[0][2] == IA) ? 10 : -10;
    }

    return 0; // Nenhum vencedor
}

// --- Algoritmo Minimax (O Coração da IA) ---

// Função recursiva Minimax
int minimax(int profundidade, bool maximizando_jogador) {
    int pontuacao = checar_vitoria();

    // Se o maximizador (IA) venceu, retorna a pontuação
    if (pontuacao == 10)
        return pontuacao - profundidade; // Subtrai a profundidade para preferir vitórias mais rápidas

    // Se o minimizador (JOGADOR) venceu, retorna a pontuação
    if (pontuacao == -10)
        return pontuacao + profundidade; // Soma a profundidade para preferir derrotas mais lentas (ou seja, evitar derrota)

    // Se não há mais movimentos e não há vencedor (empate)
    if (tem_movimentos() == false)
        return 0;

    // Se for a vez do maximizador (IA)
    if (maximizando_jogador) {
        int melhor_pontuacao = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == VAZIO) {
                    // Faz o movimento
                    tabuleiro[i][j] = IA;
                    // Chama recursivamente Minimax e escolhe o valor máximo
                    int pont_atual = minimax(profundidade + 1, false);
                    melhor_pontuacao = (pont_atual > melhor_pontuacao) ? pont_atual : melhor_pontuacao;
                    // Desfaz o movimento (backtracking)
                    tabuleiro[i][j] = VAZIO;
                }
            }
        }
        return melhor_pontuacao;
    }
    // Se for a vez do minimizador (JOGADOR)
    else {
        int melhor_pontuacao = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == VAZIO) {
                    // Faz o movimento
                    tabuleiro[i][j] = JOGADOR;
                    // Chama recursivamente Minimax e escolhe o valor mínimo
                    int pont_atual = minimax(profundidade + 1, true);
                    melhor_pontuacao = (pont_atual < melhor_pontuacao) ? pont_atual : melhor_pontuacao;
                    // Desfaz o movimento (backtracking)
                    tabuleiro[i][j] = VAZIO;
                }
            }
        }
        return melhor_pontuacao;
    }
}

// Encontra o melhor movimento para a IA usando Minimax
struct Movimento {
    int linha, coluna;
};

struct Movimento encontrar_melhor_movimento() {
    int melhor_valor = INT_MIN;
    struct Movimento melhor_movimento;
    melhor_movimento.linha = -1;
    melhor_movimento.coluna = -1;

    // Itera sobre todas as células, avaliando movimentos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                // Faz o movimento
                tabuleiro[i][j] = IA;

                // Calcula a pontuação usando Minimax
                int valor_movimento = minimax(0, false);

                // Desfaz o movimento
                tabuleiro[i][j] = VAZIO;

                // Se o valor do movimento atual for melhor que o melhor valor encontrado até agora, atualiza.
                if (valor_movimento > melhor_valor) {
                    melhor_valor = valor_movimento;
                    melhor_movimento.linha = i;
                    melhor_movimento.coluna = j;
                }
            }
        }
    }

    return melhor_movimento;
}

// --- Função Principal do Jogo ---

int main() {
    inicializar_tabuleiro();
    
    printf("--- Jogo da Velha (Tic-Tac-Toe) com IA (Minimax) ---\n");
    printf("Você é o '%c'. O computador é o '%c'.\n", JOGADOR, IA);
    printf("Para fazer uma jogada, digite a linha e a coluna (ex: 1 3).\n");

    // Loop principal do jogo
    while (tem_movimentos() && checar_vitoria() == 0) {
        exibir_tabuleiro();

        // 1. Jogada do Humano (X)
        int linha, coluna;
        bool jogada_valida = false;
        while (!jogada_valida) {
            printf("Sua vez (Linha Coluna): ");
            // Lê a entrada. Subtrai 1 para converter de 1-3 para índice 0-2
            if (scanf("%d %d", &linha, &coluna) == 2) {
                linha--; 
                coluna--;
                // Verifica se a jogada está dentro dos limites e o local está vazio
                if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == VAZIO) {
                    tabuleiro[linha][coluna] = JOGADOR;
                    jogada_valida = true;
                } else {
                    printf("Jogada inválida. Tente novamente.\n");
                }
            } else {
                // Limpa o buffer de entrada em caso de erro (ex: digitar letras)
                while (getchar() != '\n'); 
                printf("Entrada inválida. Digite apenas dois números (Linha e Coluna).\n");
            }
        }

        // Checa vitória após a jogada humana
        if (checar_vitoria() != 0 || !tem_movimentos()) {
            break;
        }

        // 2. Jogada da IA (O)
        struct Movimento melhor_movimento = encontrar_melhor_movimento();
        if (melhor_movimento.linha != -1) {
            tabuleiro[melhor_movimento.linha][melhor_movimento.coluna] = IA;
            printf("\nO computador jogou na Linha %d e Coluna %d.\n", melhor_movimento.linha + 1, melhor_movimento.coluna + 1);
        }
    }

    // --- Fim de Jogo ---
    exibir_tabuleiro();
    int resultado = checar_vitoria();

    if (resultado == 10) {
        printf("FIM DE JOGO: O COMPUTADOR VENCEU! :(\n");
    } else if (resultado == -10) {
        printf("FIM DE JOGO: VOCÊ VENCEU! :)\n");
    } else {
        printf("FIM DE JOGO: EMPATE!\n");
    }

    return 0;
}