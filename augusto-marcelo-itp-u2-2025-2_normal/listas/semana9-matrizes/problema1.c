#include <stdio.h>

int main() {
    int M, N;
    int campo[15][15]; // Matriz com margem de segurança (máximo é 10x10)
    int i, j;
    int ferteis_irrigados = 0;
    int ferteis_secos = 0;

    // 1. Leitura das dimensões
    scanf("%d %d", &M, &N);

    // 2. Leitura da matriz do campo
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    // 3. Processamento
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            
            // Se encontramos um setor FÉRTIL (1)
            if (campo[i][j] == 1) {
                int tem_irrigador = 0; // Flag (0 = falso, 1 = verdadeiro)

                // Verifica vizinho de CIMA (garante que i > 0 para não sair da matriz)
                if (i > 0 && campo[i-1][j] == 2) {
                    tem_irrigador = 1;
                }
                // Verifica vizinho de BAIXO (garante que i < M-1)
                else if (i < M-1 && campo[i+1][j] == 2) {
                    tem_irrigador = 1;
                }
                // Verifica vizinho da ESQUERDA (garante que j > 0)
                else if (j > 0 && campo[i][j-1] == 2) {
                    tem_irrigador = 1;
                }
                // Verifica vizinho da DIREITA (garante que j < N-1)
                else if (j < N-1 && campo[i][j+1] == 2) {
                    tem_irrigador = 1;
                }

                // Contabiliza
                if (tem_irrigador) {
                    ferteis_irrigados++;
                } else {
                    ferteis_secos++;
                }
            }
        }
    }

    // 4. Saída
    printf("%d %d\n", ferteis_irrigados, ferteis_secos);

    return 0;
}