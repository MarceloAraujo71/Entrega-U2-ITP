#include <stdio.h>

// Definindo a função principal do programa
int main() {
    // Declaração das variáveis inteiras para os números de entrada
    int num1, num2;

    // --- 1. Entrada de Dados ---

    printf("--- Operacoes Aritmeticas Basicas ---\n");
    
    // Solicita o primeiro número inteiro
    printf("Digite o primeiro numero inteiro (num1): ");
    if (scanf("%d", &num1) != 1) {
        printf("Erro na leitura do primeiro numero.\n");
        return 1;
    }

    // Solicita o segundo número inteiro
    printf("Digite o segundo numero inteiro (num2): ");
    if (scanf("%d", &num2) != 1) {
        printf("Erro na leitura do segundo numero.\n");
        return 1;
    }

    // --- 2. Processamento e Saída ---

    printf("\n--- Resultados ---\n");

    // A. Soma
    printf("1. Soma: %d + %d = %d\n", num1, num2, num1 + num2);

    // B. Diferença (Primeiro menos segundo)
    printf("2. Diferenca: %d - %d = %d\n", num1, num2, num1 - num2);

    // C. Produto
    printf("3. Produto: %d * %d = %d\n", num1, num2, num1 * num2);

    // --- Tratamento para Divisão (evita divisão por zero) ---
    if (num2 == 0) {
        printf("4. Divisao Real: Impossivel dividir por zero.\n");
        printf("5. Resto da Divisao: Impossivel dividir por zero.\n");
        printf("6. Media Aritmetica: %.2f\n", (float)(num1 + num2) / 2.0);
        
    } else {
        // D. Divisão Real (Resultado em float)
        // Usamos (float)num1 para forçar a conversão de pelo menos um dos operandos,
        // garantindo que a operação seja tratada como ponto flutuante.
        float divisao_real = (float)num1 / num2;
        printf("4. Divisao Real: %d / %d = %.2f\n", num1, num2, divisao_real);

        // E. Resto da Divisão Inteira (Operador módulo %)
        printf("5. Resto da Divisao: %d %% %d = %d\n", num1, num2, num1 % num2);
        
        // F. Média Aritmética
        // Convertemos a soma para float e dividimos por 2.0 (que já é float)
        float media = (float)(num1 + num2) / 2.0;
        printf("6. Media Aritmetica: (%.2f + %.2f) / 2 = %.2f\n", (float)num1, (float)num2, media);
    }
    
    return 0; // Encerra o programa com sucesso
}