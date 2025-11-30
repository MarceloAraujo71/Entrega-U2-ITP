#include <stdio.h>

// Definindo a função principal do programa
int main() {
    int n;          // Número de linhas (entrada do usuário)
    int i, j;       // Variáveis de controle dos loops (linhas e colunas)
    int contador = 1; // Contador único que armazena o proximo número a ser impresso

    printf("--- Gerador de Padrao Numerico ---\n");
    
    // Leitura do número de linhas
    printf("Digite o numero de linhas (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("\n--- Padrao Gerado ---\n");

    // Loop externo: Controla o número de LINHAS (i)
    // i vai de 1 ate n
    for (i = 1; i <= n; i++) {
        
        // Loop interno: Controla o número de COLUNAS (j)
        // O número de colunas em cada linha e igual ao numero da linha atual (i)
        for (j = 1; j <= i; j++) {
            
            // 1. Imprime o valor da variavel 'contador'
            printf("%d ", contador);
            
            // 2. Incrementa o contador para o proximo numero
            contador++;
        }
        
        // Quebra de linha apos o fim da impressao da linha atual
        printf("\n");
    }

    return 0; // Encerra o programa com sucesso
}