#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    int acertos = 0;

    // 1. Lê a quantidade de números sorteados (m) e apostados (n)
    scanf("%d %d", &m, &n);

    // Declara vetores com tamanho suficiente conforme os limites do problema
    // m <= 30 e n <= 50.
    int sorteados[30];
    int aposta[50];

    // 2. Lê os 'm' números sorteados
    for (i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    // 3. Lê os 'n' números da aposta
    for (i = 0; i < n; i++) {
        scanf("%d", &aposta[i]);
    }

    // 4. Compara cada número da aposta com os sorteados
    for (i = 0; i < n; i++) {         // Para cada número apostado...
        for (j = 0; j < m; j++) {     // ...varre todos os sorteados
            if (aposta[i] == sorteados[j]) {
                acertos++;            // Se for igual, conta como acerto
                break;                // Para de procurar esse número e vai para o próximo da aposta
            }
        }
    }

    // 5. Exibe o total de acertos
    printf("%d\n", acertos);

    return 0;
}