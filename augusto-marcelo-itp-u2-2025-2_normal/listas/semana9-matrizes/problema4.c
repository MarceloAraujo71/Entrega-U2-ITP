#include <stdio.h>

int main() {
    int M;
    int custos[15][15]; // Matriz de custos (M <= 10)
    int X, Z;
    int i, j;

    // 1. Leitura do tamanho M
    scanf("%d", &M);

    // 2. Leitura da matriz de custos
    for(i = 0; i < M; i++) {
        for(j = 0; j < M; j++) {
            scanf("%d", &custos[i][j]);
        }
    }

    // 3. Leitura da origem (X) e destino (Z)
    scanf("%d %d", &X, &Z);

    // --- Processamento ---
    
    // Definimos o custo inicial como o do voo direto.
    // Se custos[X][Z] for 0, significa que NÃO existe voo direto,
    // então colocamos um valor "infinito" (muito alto) para ser substituído depois.
    int menor_custo = (custos[X][Z] > 0) ? custos[X][Z] : 999999;
    
    int melhor_intermediario = -1; // -1 indica que a melhor rota é a direta

    // Testamos todas as possíveis cidades intermediárias 'k'
    for(int k = 0; k < M; k++) {
        // A cidade intermediária não pode ser a origem nem o destino
        if (k != X && k != Z) {
            
            // Verifica se existem os dois voos necessários (custo > 0)
            if (custos[X][k] > 0 && custos[k][Z] > 0) {
                int custo_com_escala = custos[X][k] + custos[k][Z];

                // Se esse caminho for mais barato que o atual recorde, atualizamos
                if (custo_com_escala < menor_custo) {
                    menor_custo = custo_com_escala;
                    melhor_intermediario = k;
                }
            }
        }
    }

    // --- Saída ---
    if (melhor_intermediario == -1) {
        // Melhor opção é direta
        printf("%d-%d R$%d\n", X, Z, menor_custo);
    } else {
        // Melhor opção tem escala
        printf("%d-%d-%d R$%d\n", X, melhor_intermediario, Z, menor_custo);
    }

    return 0;
}