#include <stdio.h>

// Definindo a função principal do programa
int main() {
    // Declaracao das variaveis do tipo float para valores monetarios e porcentagens
    float valor_compra;
    float percentual_desconto = 0.0; // Inicializado em 0%
    float valor_desconto;
    float valor_final;

    // --- 1. Entrada de Dados ---

    printf("--- Calculadora de Desconto Progressivo ---\n");
    
    // Solicita o valor total da compra
    printf("Digite o valor total da compra (R$): ");
    if (scanf("%f", &valor_compra) != 1 || valor_compra < 0) {
        printf("Erro: O valor da compra deve ser um numero nao negativo.\n");
        return 1;
    }

    // --- 2. Processamento (Determinacao da Taxa de Desconto) ---

    if (valor_compra <= 100.00) {
        // Até R$ 100,00: sem desconto (0%)
        percentual_desconto = 0.0;
    } 
    else if (valor_compra <= 500.00) {
        // De R$ 100,01 a R$ 500,00: 10% de desconto
        percentual_desconto = 10.0;
    }
    else if (valor_compra <= 1000.00) {
        // De R$ 500,01 a R$ 1000,00: 15% de desconto
        percentual_desconto = 15.0;
    }
    else {
        // Acima de R$ 1000,00: 20% de desconto
        percentual_desconto = 20.0;
    }
    
    // --- 3. Calculo dos Valores Finais ---
    
    // Converte a porcentagem para forma decimal para calculo (ex: 10% -> 0.10)
    float fator_desconto = percentual_desconto / 100.0;
    
    // Valor do Desconto = Valor da Compra * Fator de Desconto
    valor_desconto = valor_compra * fator_desconto;
    
    // Valor Final = Valor da Compra - Valor do Desconto
    valor_final = valor_compra - valor_desconto;


    // --- 4. Saída de Dados ---

    printf("\n--- Resumo da Transacao ---\n");
    printf("Valor da Compra Original: R$ %.2f\n", valor_compra);
    printf("------------------------------------\n");
    
    // Porcentagem de Desconto Aplicada
    printf("Porcentagem de Desconto Aplicada: %.0f%%\n", percentual_desconto);

    // Valor do Desconto
    printf("Valor do Desconto: R$ %.2f\n", valor_desconto);
    
    // Valor Final a Ser Pago
    printf("Valor Final a ser Pago: R$ %.2f\n", valor_final);
    
    return 0; // Encerra o programa com sucesso
}