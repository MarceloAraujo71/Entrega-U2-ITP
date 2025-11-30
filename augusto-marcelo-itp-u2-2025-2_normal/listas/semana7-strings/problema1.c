#include <stdio.h>
#include <string.h>

int main() {
    char campo[21]; // 20 caracteres + 1 para o terminador nulo '\0'
    int indice;

    // Leitura da entrada
    scanf("%s", campo);
    scanf("%d", &indice);

    // Obtém o tamanho da string para verificar limites
    int tamanho = strlen(campo);

    // 1. Verifica se no índice escolhido existe uma bomba
    if (campo[indice] == 'x') {
        printf("bum!\n");
    } 
    else {
        // 2. Se não for bomba, conta as adjacências
        int bombas_adjacentes = 0;

        // Verifica o vizinho da ESQUERDA (índice - 1)
        // Só verifica se o índice for maior que 0 para não acessar memória inválida
        if (indice > 0) {
            if (campo[indice - 1] == 'x') {
                bombas_adjacentes++;
            }
        }

        // Verifica o vizinho da DIREITA (índice + 1)
        // Só verifica se o índice for menor que o último elemento (tamanho - 1)
        if (indice < tamanho - 1) {
            if (campo[indice + 1] == 'x') {
                bombas_adjacentes++;
            }
        }

        // Imprime a quantidade de bombas vizinhas
        printf("%d\n", bombas_adjacentes);
    }

    return 0;
}