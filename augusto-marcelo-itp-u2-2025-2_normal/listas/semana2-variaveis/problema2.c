#include <stdio.h>

// Definindo a função principal do programa
int main() {
    // Declaração das variáveis do tipo float
    float celsius;
    float fahrenheit;
    float kelvin;

    // --- 1. Entrada de Dados ---

    printf("--- Conversor de Temperatura ---\n");
    printf("Digite a temperatura em graus Celsius (ex: 25.5): ");
    
    // Lê o valor da temperatura em Celsius
    if (scanf("%f", &celsius) != 1) {
        printf("Erro na leitura da temperatura.\n");
        return 1; // Encerra o programa com erro
    }

    // --- 2. Processamento (Cálculos de Conversão) ---

    // Fórmula para Fahrenheit: (Celsius * 9/5) + 32
    // Nota: É crucial usar 9.0/5.0 (ou 9/5.0) para garantir que a divisao seja feita em ponto flutuante (float),
    // caso contrario, 9/5 seria 1 (divisao inteira).
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    // Fórmula para Kelvin: Celsius + 273.15
    kelvin = celsius + 273.15;

    // --- 3. Saída de Dados ---

    printf("\n--- Resultados da Conversao ---\n");
    
    // Exibe a temperatura em Fahrenheit usando '%.1f' para garantir 1 casa decimal
    printf("Fahrenheit (F): %.1f\n", fahrenheit);
    
    // Exibe a temperatura em Kelvin usando '%.1f' para garantir 1 casa decimal
    printf("Kelvin (K): %.1f\n", kelvin);
    
    return 0; // Encerra o programa com sucesso
}