#include <stdio.h>

// Definindo a função principal do programa
int main() {
    // Variáveis de entrada
    float consumo_kwh;
    char tipo_consumidor;

    // Variáveis de cálculo
    float tarifa_por_kwh = 0.0;
    float taxa_fixa = 15.00;
    float valor_total = 0.0;
    
    // --- 1. Entrada de Dados ---

    printf("--- Calculadora de Conta de Energia Eletrica ---\n");
    
    // Solicita o consumo em kWh
    printf("Digite o consumo em kWh: ");
    if (scanf("%f", &consumo_kwh) != 1 || consumo_kwh < 0) {
        printf("Erro: Consumo deve ser um numero nao negativo.\n");
        return 1;
    }

    // Solicita o tipo de consumidor
    printf("Digite o tipo de consumidor (R/r para Residencial, C/c para Comercial, I/i para Industrial): ");
    // O espaco antes de %c e importante para ignorar o caractere de nova linha (Enter) anterior
    if (scanf(" %c", &tipo_consumidor) != 1) {
        printf("Erro na leitura do tipo de consumidor.\n");
        return 1;
    }

    // --- 2. Processamento (Atribuicao da Tarifa) ---

    // Usaremos uma estrutura switch/case para lidar com os diferentes tipos de consumidor
    switch (tipo_consumidor) {
        case 'R':
        case 'r':
            tarifa_por_kwh = 0.60;
            printf("\nTipo: Residencial (R$ 0.60/kWh)\n");
            break;
            
        case 'C':
        case 'c':
            tarifa_por_kwh = 0.48;
            printf("\nTipo: Comercial (R$ 0.48/kWh)\n");
            break;
            
        case 'I':
        case 'i':
            tarifa_por_kwh = 1.29;
            printf("\nTipo: Industrial (R$ 1.29/kWh)\n");
            break;
            
        default:
            printf("\nErro: Tipo de consumidor invalido.\n");
            return 1; // Encerra o programa se o tipo for invalido
    }

    // --- 3. Cálculo do Valor Total ---
    
    // Valor total = (Consumo * Tarifa) + Taxa Fixa
    valor_total = (consumo_kwh * tarifa_por_kwh) + taxa_fixa;

    // --- 4. Saída de Dados ---

    printf("Taxa Fixa: R$ %.2f\n", taxa_fixa);
    printf("Consumo (%.2f kWh) * Tarifa (R$ %.2f/kWh) = R$ %.2f\n", 
           consumo_kwh, tarifa_por_kwh, (consumo_kwh * tarifa_por_kwh));

    // Exibe o valor total da conta (formatado com 2 casas decimais)
    printf("----------------------------------------------------\n");
    printf("Valor Total da Conta: R$ %.2f\n", valor_total);
    
    return 0; // Encerra o programa com sucesso
}