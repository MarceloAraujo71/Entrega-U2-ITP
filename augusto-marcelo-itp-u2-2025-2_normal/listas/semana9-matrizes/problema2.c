#include <stdio.h>

int main() {
    int M, x;
    int grafo[105][105]; // Matriz de adjacência (máx 100x100)

    // 1. Leitura do número de usuários
    scanf("%d", &M);

    // 2. Leitura da matriz de amizades
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            // %1d lê apenas um dígito. Funciona para "0 1 0" e "010"
            scanf("%1d", &grafo[i][j]);
        }
    }

    // 3. Leitura do usuário alvo (x)
    scanf("%d", &x);

    // 4. Processamento das sugestões
    // Percorre todos os possíveis candidatos (i)
    for(int i = 0; i < M; i++) {
        
        // Condição 1: Não ser o próprio usuário
        // Condição 2: Não ser amigo direto atualmente (valor 0 na matriz)
        if (i != x && grafo[x][i] == 0) {
            
            int amigo_em_comum = 0; // Flag

            // Verifica se existe algum amigo 'k' em comum
            for(int k = 0; k < M; k++) {
                // Se 'k' é amigo de 'x' E 'k' é amigo de 'i'
                if (grafo[x][k] == 1 && grafo[i][k] == 1) {
                    amigo_em_comum = 1;
                    break; // Encontrou um, já é suficiente
                }
            }

            // Se achou amigo em comum, imprime o candidato
            if (amigo_em_comum) {
                printf("%d ", i);
            }
        }
    }
    
    printf("\n"); // Quebra de linha final (boa prática)

    return 0;
}