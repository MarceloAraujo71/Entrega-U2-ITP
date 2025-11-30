#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool

// Define o limite maximo de figurinhas na colecao
#define MAX_FIGURINHAS 1000

int main() {
    int m; // Quantidade de figurinhas na colecao completa (1 a m)
    int n; // Quantidade de figurinhas que o usuario possui
    int numero_figurinhas; // Variavel temporaria para leitura
    
    // Array de sinalizacao: +1 para usar indices de 1 a m
    // Inicialmente, todas sao consideradas FALSE (faltando)
    bool presente[MAX_FIGURINHAS + 1] = {false};
    
    int i; // Variavel de controle do loop

    // --- 1. Leitura de M e N ---

    printf("--- Listagem de Figurinhas Faltantes ---\n");
    printf("Digite o total de figurinhas da colecao (m) e a quantidade que voce tem (n), ex: 13 6\n");
    
    if (scanf("%d %d", &m, &n) != 2 || m < 1 || m > MAX_FIGURINHAS || n < 0 || n > m) {
        printf("Erro: Valores de M e/ou N invalidos.\n");
        return 1;
    }

    // --- 2. Leitura das Figurinhas Possuidas ---

    printf("Digite os %d numeros das figurinhas que voce POSSUI (ex: 2 5 13 8 11 7):\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &numero_figurinhas) != 1) {
            printf("Erro na leitura das figurinhas.\n");
            return 1;
        }
        
        // Verifica se o numero e valido e sinaliza como PRESENTE no array
        if (numero_figurinhas >= 1 && numero_figurinhas <= m) {
            presente[numero_figurinhas] = true;
        }
    }

    // --- 3. Processamento e Saída (Listagem das Faltantes) ---
    
    printf("\nFigurinhas Faltando (em ordem crescente): \n");
    
    // Contagem de quantas faltam (para formatacao)
    int count_faltando = 0;
    
    // Loop de 1 ate M para verificar o array de sinalizacao
    for (i = 1; i <= m; i++) {
        
        // Se o valor do array for 'false', significa que a figurinha esta faltando
        if (presente[i] == false) {
            printf("%d ", i);
            count_faltando++;
        }
    }
    
    // Verifica se faltou alguma
    if (count_faltando == 0) {
        printf("Nenhuma! Sua colecao esta completa!\n");
    } else {
        printf("\nTotal de %d figurinha(s) faltando.\n", count_faltando);
    }

    return 0; // Encerra o programa com sucesso
}