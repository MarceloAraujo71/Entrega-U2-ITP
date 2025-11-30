#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// --- Definições Globais ---
#define JOGADOR 'X' // Jogador Humano
#define IA 'O'      // Jogador Computador
#define VAZIO ' '   // Espaço Vazio
#define MAX_TAM 10  // Tamanho máximo seguro para alocação estática

// Variáveis globais para configuração do jogo
int TAMANHO = 3;         // Tamanho do tabuleiro (N x N)
char tabuleiro[MAX_TAM][MAX_TAM];

// --- Funções Auxiliares ---

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

// Inicializa o tabuleiro com espaços vazios
void inicializar_tabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

// Exibe o tabuleiro de forma dinâmica
void exibir_tabuleiro() {
    printf("\n");
    // Imprime cabeçalho das colunas
    printf("   ");
    for(int k = 0; k < TAMANHO; k++) printf(" %d  ", k + 1);
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf(" %d ", i + 1); // Número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) {
            printf("   ");
            for (int k = 0; k < TAMANHO; k++) {
                printf("---");
                if (k < TAMANHO - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Verifica se há movimentos disponíveis
bool tem_movimentos() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                return true;
            }
        }
    }
    return false;
}

// Verifica vitória de forma dinâmica (funciona para qualquer N)
// Retorna 10 se IA vence, -10 se Jogador vence, 0 caso contrário.
int checar_vitoria() {
    // Verificar Linhas e Colunas
    for (int i = 0; i < TAMANHO; i++) {
        int cont_linha_ia = 0, cont_linha_jog = 0;
        int cont_col_ia = 0, cont_col_jog = 0;

        for (int j = 0; j < TAMANHO; j++) {
            // Linhas
            if (tabuleiro[i][j] == IA) cont_linha_ia++;
            else if (tabuleiro[i][j] == JOGADOR) cont_linha_jog++;
            
            // Colunas
            if (tabuleiro[j][i] == IA) cont_col_ia++;
            else if (tabuleiro[j][i] == JOGADOR) cont_col_jog++;
        }

        if (cont_linha_ia == TAMANHO || cont_col_ia == TAMANHO) return 10;
        if (cont_linha_jog == TAMANHO || cont_col_jog == TAMANHO) return -10;
    }

    // Verificar Diagonais
    int diag1_ia = 0, diag1_jog = 0;
    int diag2_ia = 0, diag2_jog = 0;

    for (int i = 0; i < TAMANHO; i++) {
        // Diagonal Principal
        if (tabuleiro[i][i] == IA) diag1_ia++;
        else if (tabuleiro[i][i] == JOGADOR) diag1_jog++;

        // Diagonal Secundária
        if (tabuleiro[i][TAMANHO - 1 - i] == IA) diag2_ia++;
        else if (tabuleiro[i][TAMANHO - 1 - i] == JOGADOR) diag2_jog++;
    }

    if (diag1_ia == TAMANHO || diag2_ia == TAMANHO) return 10;
    if (diag1_jog == TAMANHO || diag2_jog == TAMANHO) return -10;

    return 0;
}

// --- Algoritmo Minimax com Poda Alpha-Beta ---

// Função heurística para quando atingirmos o limite de profundidade sem vitória
int avaliar_tabuleiro() {
    // Se não chegou ao fim, a IA prefere estados onde ela tem mais peças
    // Isso é uma heurística simples. Pode ser melhorada para contar "linhas abertas".
    return 0; 
}

int minimax(int profundidade, int alpha, int beta, bool maximizando_jogador, int max_depth) {
    int pontuacao = checar_vitoria();

    if (pontuacao == 10) return pontuacao - profundidade;
    if (pontuacao == -10) return pontuacao + profundidade;
    if (!tem_movimentos()) return 0;
    
    // Limite de profundidade para evitar travamento em tabuleiros grandes
    if (profundidade >= max_depth) return 0;

    if (maximizando_jogador) {
        int melhor_pontuacao = INT_MIN;
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                if (tabuleiro[i][j] == VAZIO) {
                    tabuleiro[i][j] = IA;
                    // Chamada recursiva com alpha e beta
                    int val = minimax(profundidade + 1, alpha, beta, false, max_depth);
                    tabuleiro[i][j] = VAZIO;
                    
                    melhor_pontuacao = max(melhor_pontuacao, val);
                    alpha = max(alpha, melhor_pontuacao);
                    
                    // Poda Alpha-Beta: se beta <= alpha, cortamos este ramo
                    if (beta <= alpha) return melhor_pontuacao;
                }
            }
        }
        return melhor_pontuacao;
    } else {
        int melhor_pontuacao = INT_MAX;
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                if (tabuleiro[i][j] == VAZIO) {
                    tabuleiro[i][j] = JOGADOR;
                    int val = minimax(profundidade + 1, alpha, beta, true, max_depth);
                    tabuleiro[i][j] = VAZIO;
                    
                    melhor_pontuacao = min(melhor_pontuacao, val);
                    beta = min(beta, melhor_pontuacao);
                    
                    if (beta <= alpha) return melhor_pontuacao;
                }
            }
        }
        return melhor_pontuacao;
    }
}

// Estrutura para retorno do movimento
struct Movimento {
    int linha, coluna;
};

struct Movimento encontrar_melhor_movimento() {
    int melhor_valor = INT_MIN;
    struct Movimento melhor_movimento = {-1, -1};
    
    // Define a profundidade máxima baseada no tamanho do tabuleiro
    // Tabuleiro 3x3 = Profundidade alta (cálculo rápido)
    // Tabuleiro 4x4+ = Profundidade limitada para não travar
    int max_depth = (TAMANHO == 3) ? 9 : 6;

    // Se for o primeiro movimento em tabuleiro grande, pega o centro para economizar tempo
    if (TAMANHO > 3 && tabuleiro[TAMANHO/2][TAMANHO/2] == VAZIO) {
        melhor_movimento.linha = TAMANHO/2;
        melhor_movimento.coluna = TAMANHO/2;
        return melhor_movimento;
    }

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                tabuleiro[i][j] = IA;
                
                // Inicializa Minimax com alpha -Inf e beta +Inf
                int valor_movimento = minimax(0, INT_MIN, INT_MAX, false, max_depth);
                
                tabuleiro[i][j] = VAZIO;

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

// --- Função Principal ---

int main() {
    // Configuração Inicial
    printf("--- Jogo da Velha Avancado (Minimax + Alpha-Beta) ---\n");
    do {
        printf("Escolha o tamanho do tabuleiro (3 a 5): ");
        if (scanf("%d", &TAMANHO) != 1) {
            while(getchar() != '\n'); // Limpa buffer
            TAMANHO = 0;
        }
    } while (TAMANHO < 3 || TAMANHO > 5);

    inicializar_tabuleiro();

    printf("\nVoce é o '%c'. A IA é o '%c'.\n", JOGADOR, IA);
    printf("O objetivo é alinhar %d simbolos.\n", TAMANHO);

    // Loop do Jogo
    while (tem_movimentos() && checar_vitoria() == 0) {
        exibir_tabuleiro();

        // 1. Jogada do Humano
        int linha, coluna;
        bool jogada_valida = false;
        while (!jogada_valida) {
            printf("Sua vez (Linha Coluna): ");
            if (scanf("%d %d", &linha, &coluna) == 2) {
                linha--; coluna--; // Ajuste para índice 0
                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == VAZIO) {
                    tabuleiro[linha][coluna] = JOGADOR;
                    jogada_valida = true;
                } else {
                    printf("Jogada inválida ou posicao ocupada.\n");
                }
            } else {
                while (getchar() != '\n');
                printf("Entrada inválida. Digite dois números.\n");
            }
        }

        if (checar_vitoria() != 0 || !tem_movimentos()) break;

        // 2. Jogada da IA
        printf("\nIA calculando jogada...\n");
        struct Movimento mm = encontrar_melhor_movimento();
        if (mm.linha != -1) {
            tabuleiro[mm.linha][mm.coluna] = IA;
            printf("A IA jogou na Linha %d, Coluna %d\n", mm.linha + 1, mm.coluna + 1);
        }
    }

    exibir_tabuleiro();
    int resultado = checar_vitoria();

    if (resultado == 10) printf("\nIA VENCEU! A máquina prevalece.\n");
    else if (resultado == -10) printf("\nVOCE VENCEU! Incrível!\n");
    else printf("\nEMPATE! Jogo acirrado.\n");

    system("pause"); // Pausa no Windows para ver o resultado
    return 0;
}