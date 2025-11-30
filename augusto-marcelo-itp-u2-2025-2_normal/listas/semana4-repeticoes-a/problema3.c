#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

/**
 * Funcao para calcular a soma dos divisores proprios de um numero (D(x)).
 * Divisores proprios sao todos os divisores de 'num', exceto o proprio 'num'.
 */
int soma_divisores(int num) {
    // Para 1, nao ha divisores proprios.
    if (num <= 1) {
        return 0;
    }
    
    // 1 e sempre um divisor proprio de qualquer numero > 1
    int soma = 1; 
    
    // Otimizacao: iteramos ate a raiz quadrada do numero
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            // 'i' e o primeiro divisor
            soma += i;
            
            // 'num / i' e o divisor par
            int divisor_par = num / i;
            
            // Se i * i != num, significa que i e o par sao diferentes
            // E ambos sao divisores proprios (pois i <= sqrt(num) < num)
            if (i * i != num) {
                soma += divisor_par;
            }
        }
    }
    
    return soma;
}

int main() {
    int A, B;
    int soma_div_A, soma_div_B;
    
    printf("--- Verificador de Numeros Colegas ---\n");
    
    // Leitura dos dois inteiros (assumidos como diferentes e positivos)
    printf("Digite o primeiro numero inteiro (A): ");
    if (scanf("%d", &A) != 1 || A <= 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Digite o segundo numero inteiro (B): ");
    if (scanf("%d", &B) != 1 || B <= 0) {
        printf("Entrada invalida.\n");
        return 1;
    }
    
    // 1. Calcular D(A) e D(B)
    soma_div_A = soma_divisores(A);
    soma_div_B = soma_divisores(B);

    // 2. Calcular as Diferencas Absolutas
    
    // Condicao 1: |D(A) - B| <= 2
    int dif1 = abs(soma_div_A - B);
    
    // Condicao 2: |D(B) - A| <= 2
    int dif2 = abs(soma_div_B - A);

    printf("\n--- Detalhes do Calculo ---\n");
    printf("Soma dos divisores de A (%d): D(A) = %d\n", A, soma_div_A);
    printf("Soma dos divisores de B (%d): D(B) = %d\n", B, soma_div_B);
    printf("Diferenca 1: |D(A) - B| = |%d - %d| = %d\n", soma_div_A, B, dif1);
    printf("Diferenca 2: |D(B) - A| = |%d - %d| = %d\n", soma_div_B, A, dif2);

    // 3. Resultado Final
    if (dif1 <= 2 && dif2 <= 2) {
        printf("\nRESULTADO: S (Sao Colegas)\n");
    } else {
        printf("\nRESULTADO: N (Nao sao Colegas)\n");
    }

    return 0; // Encerra o programa com sucesso
}