#include <stdio.h>
#include <stdbool.h>
#include <math.h> // Necessário para a função abs()

// Define o tamanho do tabuleiro
#define N 4

// Array para armazenar a coluna de cada rainha
// Por exemplo, 'coluna[i] = j' significa que a rainha na linha 'i' está na coluna 'j'
int coluna[N]; 

// Contador global para o número de soluções encontradas
int contador_solucoes = 0;

/**
 * Verifica se e seguro colocar uma rainha na linha 'linha' e na coluna 'col'.
 * Uma nova rainha e segura se nao for atacada por nenhuma rainha colocada anteriormente.
 */
bool eh_seguro(int linha, int col) {
    // Itera sobre as rainhas que ja foram colocadas (linhas anteriores)
    for (int i = 0; i < linha; i++) {
        
        // 1. Checa a mesma coluna:
        // Se a rainha na linha 'i' ja esta na mesma coluna 'col', nao e seguro.
        if (coluna[i] == col) {
            return false;
        }
        
        // 2. Checa as diagonais:
        // A diferenca absoluta nas linhas (linha - i) deve ser igual a diferenca absoluta nas colunas (col - coluna[i])
        // Se |linha_atual - linha_anterior| == |coluna_atual - coluna_anterior|, estao na mesma diagonal.
        if (abs(linha - i) == abs(col - coluna[i])) {
            return false;
        }
    }
    return true;
}

/**
 * Exibe a solucao do tabuleiro
 */
void exibir_tabuleiro() {
    printf("\n--- Solucao %d ---\n", ++contador_solucoes);
    
    // Imprime as posicoes das rainhas (por linha e coluna)
    printf("Posicoes (Linha, Coluna): ");
    for (int i = 0; i < N; i++) {
        printf("(%d, %d)", i + 1, coluna[i] + 1);
        if (i < N - 1) printf(", ");
    }
    printf("\n");
    
    // Exibe a representacao grafica do tabuleiro (R para Rainha)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (coluna[i] == j) {
                printf(" R ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

/**
 * Funcao de backtracking (recursiva) para resolver o problema.
 * Tenta colocar uma rainha na linha 'linha' atual.
 */
void resolver_4_rainhas(int linha) {
    // CONDIÇÃO BASE: Se todas as rainhas foram colocadas (chegamos alem da ultima linha)
    if (linha == N) {
        exibir_tabuleiro();
        return;
    }

    // Passos recursivos: Itera sobre todas as colunas para a linha atual
    for (int col = 0; col < N; col++) {
        
        // 1. Checa a seguranca
        if (eh_seguro(linha, col)) {
            
            // 2. Tenta: Coloca a rainha na posicao atual
            coluna[linha] = col;
            
            // 3. Recorre: Chama a funcao para colocar a rainha na proxima linha
            resolver_4_rainhas(linha + 1);
            
            // 4. Backtrack (Desfaz): Nao precisamos desfazer nada explicitamente aqui,
            //    pois a proxima iteracao do loop 'for' simplesmente sobrescrevera 'coluna[linha]',
            //    e a chamada recursiva garante que o estado e limpo ao retornar.
        }
    }
}

// --- FUNÇÃO PRINCIPAL ---
int main() {
    printf("--- Problema das 4 Rainhas (Backtracking) ---\n");
    
    // Inicia a busca pela primeira linha (linha 0)
    resolver_4_rainhas(0);
    
    printf("\nTotal de solucoes encontradas: %d\n", contador_solucoes);
    printf("--------------------------------------------\n");
    
    return 0;
}