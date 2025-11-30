#include <stdio.h>
#include <stdbool.h>
#include <math.h> // Necessario para a funcao sqrt()

// Define o limite superior para a busca
#define LIMITE 50000

/**
 * Funcao que verifica se um numero é primo.
 * Retorna true se for primo, false caso contrario.
 */
bool eh_primo(int num) {
    // 0 e 1 nao sao primos
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
    int x; // A variavel x representa o primeiro numero do trio
    
    printf("--- Trios de Primos Especiais (x, x+2, x+6) ate %d ---\n", LIMITE);
    
    // Loop principal: x vai de 1 ate o limite, pulando os 6 ultimos
    // O limite e LIMITE - 6, pois x+6 nao pode ultrapassar 50000
    for (x = 1; x <= LIMITE - 6; x++) {
        
        // 1. Verifica se o primeiro numero (x) e primo
        if (eh_primo(x)) {
            
            // 2. Verifica se o segundo numero (x+2) e primo
            if (eh_primo(x + 2)) {
                
                // 3. Verifica se o terceiro numero (x+6) e primo
                if (eh_primo(x + 6)) {
                    
                    // Se todas as condicoes sao satisfeitas, imprime o trio no formato solicitado
                    printf("(%d, %d, %d)\n", x, x + 2, x + 6);
                }
            }
        }
    }

    printf("\n--- Busca concluida. ---\n");
    
    return 0;
}