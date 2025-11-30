#include <stdio.h>

// Definindo a função principal do programa
int main() {
    // Declaracao das variaveis float para valores monetarios
    float preco1, preco2;
    float quantia_disponivel;
    
    // Variaveis inteiras para os loops e a contagem de unidades
    int unidades1, unidades2;
    
    // Variavel para armazenar o menor valor restante encontrado
    float menor_restante = -1.0; 

    // --- 1. Entrada de Dados ---

    printf("--- Otimizacao de Compra de Placas de Aluminio ---\n");
    
    // Leitura do preco do primeiro fornecedor
    printf("Digite o preco do primeiro fornecedor: ");
    if (scanf("%f", &preco1) != 1 || preco1 <= 0) return 1;

    // Leitura do preco do segundo fornecedor
    printf("Digite o preco do segundo fornecedor: ");
    if (scanf("%f", &preco2) != 1 || preco2 <= 0) return 1;

    // Leitura da quantia disponivel
    printf("Digite a quantia disponivel: ");
    if (scanf("%f", &quantia_disponivel) != 1 || quantia_disponivel < 0) return 1;
    
    printf("\n--- Resultados de Todas as Combinacoes (Max 10 Unidades) ---\n");

    // --- 2. Processamento (Loops Aninhados) ---

    // Loop externo: Representa as unidades compradas do Fornecedor 1 (de 0 a 10)
    for (unidades1 = 0; unidades1 <= 10; unidades1++) {
        
        // Loop interno: Representa as unidades compradas do Fornecedor 2 (de 0 a 10)
        for (unidades2 = 0; unidades2 <= 10; unidades2++) {
            
            // Calculo do custo total para esta combinacao
            float custo_total = (unidades1 * preco1) + (unidades2 * preco2);
            
            // Verifica se a compra e possivel (custo <= orcamento)
            if (custo_total <= quantia_disponivel) {
                
                // Calcula o valor restante
                float restante = quantia_disponivel - custo_total;
                
                // Exibe o resultado (conforme o formato do exemplo)
                printf("Comprando %d do primeiro e %d do segundo resta: %.0f\n", 
                       unidades1, unidades2, restante);

                // Logica de Otimizacao (Encontrar o menor restante)
                if (menor_restante < 0.0 || restante < menor_restante) {
                    menor_restante = restante;
                }
            }
        }
    }

    // --- 3. Saída Final (O menor restante) ---
    
    printf("\n============================================\n");
    if (menor_restante >= 0) {
        printf("O MENOR valor restante possivel e: R$ %.2f\n", menor_restante);
    } else {
        printf("Nao foi possivel realizar nenhuma compra.\n");
    }
    printf("============================================\n");

    return 0; // Encerra o programa com sucesso
}