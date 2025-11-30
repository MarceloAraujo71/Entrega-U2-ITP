#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool

// --- FUNÇÃO AUXILIAR: Verifica se um número é primo ---
bool eh_primo(int num) {
    // 0 e 1 não são primos
    if (num <= 1) {
        return false;
    }
    // Otimizacao: so precisamos verificar divisores ate a raiz quadrada do numero
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Encontrou um divisor, nao e primo
        }
    }
    return true; // Se o loop terminou sem encontrar divisores, e primo
}

// --- FUNÇÃO PRINCIPAL ---
int main() {
    int a, b;
    bool entrada_valida = false;

    printf("--- Encontrando Numeros Primos entre A e B ---\n");

    // Loop do-while para garantir que a > b
    do {
        printf("Digite o primeiro numero inteiro (A): ");
        if (scanf("%d", &a) != 1) return 1;

        printf("Digite o segundo numero inteiro (B): ");
        if (scanf("%d", &b) != 1) return 1;

        if (a > b) {
            entrada_valida = true;
        } else {
            printf("\nERRO: O programa so prossegue se A for maior que B. Tente novamente.\n");
        }
    } while (!entrada_valida);

    printf("\n--- Numeros Primos entre %d e %d ---\n", b, a);
    
    // Loop para verificar cada numero no intervalo (de B + 1 ate A - 1)
    // Se quisermos incluir A e B, o loop vai de b ate a. Vou assumir o intervalo [b, a]
    
    // O loop deve percorrer todos os números no intervalo [b, a]
    for (int num_atual = b; num_atual <= a; num_atual++) {
        
        // Chama a função auxiliar para verificar se o número é primo
        if (eh_primo(num_atual)) {
            printf("%d\n", num_atual);
        }
    }

    printf("--------------------------------------\n");

    return 0;
}