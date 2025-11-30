#include <stdio.h>
#include <math.h> // Necessário para a função pow()

// Definindo a função principal do programa
int main() {
    // Declaração das variáveis com o tipo apropriado (float)
    float peso_kg;
    float altura_m;
    float imc;

    // --- 1. Entrada de Dados ---

    // Solicita o peso ao usuário
    printf("--- Calculadora de Indice de Massa Corporal (IMC) ---\n");
    printf("Digite o seu peso em quilogramas (ex: 75.5): ");
    
    // Lê o valor do peso e armazena na variável 'peso_kg'
    if (scanf("%f", &peso_kg) != 1) {
        printf("Erro na leitura do peso.\n");
        return 1; // Encerra o programa com erro
    }

    // Solicita a altura ao usuário
    printf("Digite a sua altura em metros (ex: 1.70): ");
    
    // Lê o valor da altura e armazena na variável 'altura_m'
    if (scanf("%f", &altura_m) != 1) {
        printf("Erro na leitura da altura.\n");
        return 1; // Encerra o programa com erro
    }

    // --- 2. Processamento (Cálculo do IMC) ---

    // Verifica se a altura é válida para evitar divisão por zero
    if (altura_m <= 0) {
        printf("\nErro: A altura deve ser um valor positivo e maior que zero.\n");
        return 1; // Encerra o programa com erro
    }

    // IMC = peso / (altura * altura) ou peso / pow(altura, 2)
    // Usamos altura_m * altura_m para simplicidade e evitar a inclusão de math.h, mas mantive o pow() para demonstrar, se quiser usar.
    // imc = peso_kg / pow(altura_m, 2);
    imc = peso_kg / (altura_m * altura_m);


    // --- 3. Saída de Dados ---

    printf("\n--- Resultado ---\n");
    printf("Peso inserido: %.2f kg\n", peso_kg);
    printf("Altura inserida: %.2f m\n", altura_m);
    
    // Exibe o IMC usando '%.2f' para garantir 2 casas decimais
    printf("Seu Indice de Massa Corporal (IMC) e: %.2f\n", imc);
    
    return 0; // Encerra o programa com sucesso
}