#include <stdio.h>

int main() {
    int M;
    int gols[25][25]; // Tamanho seguro (M <= 20)
    int empates = 0;
    int i, j;

    // 1. Leitura do número de times
    scanf("%d", &M);

    // 2. Leitura da matriz de gols
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            // Usamos %1d para ler dígito por dígito, pois a entrada
            // pode não ter espaços (ex: 022132)
            scanf("%1d", &gols[i][j]);
        }
    }

    // 3. Processamento
    // O laço externo percorre os times 'i'
    for (i = 0; i < M; i++) {
        // O laço interno percorre os adversários 'j'.
        // Começamos de 'i + 1' para olhar apenas à frente e não repetir partidas.
        // Isso evita comparar um time com ele mesmo ou comparar A vs B e depois B vs A.
        for (j = i + 1; j < M; j++) {
            
            // Verifica se houve empate
            // Gols que 'i' fez em 'j' == Gols que 'j' fez em 'i'
            if (gols[i][j] == gols[j][i]) {
                empates++;
            }
        }
    }

    // 4. Saída
    printf("%d\n", empates);

    return 0;
}