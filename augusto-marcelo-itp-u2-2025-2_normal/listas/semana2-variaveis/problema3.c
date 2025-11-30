#include <stdio.h>
#include <math.h> // Biblioteca necessária para a função pow()

// Definindo a função principal do programa
int main() {
    // Declaração das variáveis do tipo double para maior precisão em cálculos financeiros
    double capital_inicial;
    double taxa_juros_percentual;
    double tempo_anos;
    double montante_final;

    // --- 1. Entrada de Dados ---

    printf("--- Calculadora de Juros Compostos ---\n");
    
    // Solicita o Capital Inicial
    printf("Digite o Capital Inicial (R$): ");
    if (scanf("%lf", &capital_inicial) != 1) {
        printf("Erro na leitura do capital.\n");
        return 1;
    }

    // Solicita a Taxa de Juros (em porcentagem)
    printf("Digite a Taxa de Juros Anual (em %%): ");
    if (scanf("%lf", &taxa_juros_percentual) != 1) {
        printf("Erro na leitura da taxa.\n");
        return 1;
    }

    // Solicita o Tempo (em anos)
    printf("Digite o Tempo da aplicacao (em anos): ");
    if (scanf("%lf", &tempo_anos) != 1) {
        printf("Erro na leitura do tempo.\n");
        return 1;
    }

    // --- 2. Processamento (Cálculo do Montante) ---
    
    // A fórmula exige a taxa em forma decimal. Ex: 5% = 0.05.
    double taxa_decimal = taxa_juros_percentual / 100.0;

    // Montante = Capital * (1 + taxa_decimal)^tempo
    // pow(base, expoente) calcula a potencia
    montante_final = capital_inicial * pow((1.0 + taxa_decimal), tempo_anos);

    // --- 3. Saída de Dados ---

    printf("\n--- Resultado ---\n");
    printf("Capital Inicial: R$ %.2f\n", capital_inicial);
    printf("Taxa de Juros: %.2f%%\n", taxa_juros_percentual);
    printf("Tempo: %.0f anos\n", tempo_anos);
    
    // Exibe o montante final formatado para moeda (2 casas decimais)
    printf("Montante Final: R$ %.2f\n", montante_final);
    
    return 0; // Encerra o programa com sucesso
}