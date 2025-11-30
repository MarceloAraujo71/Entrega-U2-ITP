#include <stdio.h>

// Define o limite máximo de itens no pacote (10)
#define MAX_ITENS 10

int main() {
    // Declaracao das variaveis float para precos
    float preco_venda_p;
    float preco_custo_q;
    
    // Variaveis para a melhor promocao encontrada
    int melhor_x = -1;
    int melhor_y = -1;
    float melhor_razao = 0.0; // Inicializada com o menor valor possivel
    
    // Variaveis de loop
    int x, y;

    // --- 1. Entrada de Dados ---

    printf("--- Otimizacao de Pacote Promocional ---\n");
    
    // Leitura do preco de venda (p)
    printf("Digite o preco de venda (p): ");
    if (scanf("%f", &preco_venda_p) != 1 || preco_venda_p <= 0) return 1;

    // Leitura do preco de producao (q)
    printf("Digite o preco de producao (q): ");
    if (scanf("%f", &preco_custo_q) != 1 || preco_custo_q <= 0) return 1;
    
    printf("\n--- Possibilidades Validas e Suas Razoes ---\n");

    // --- 2. Processamento (Loops Aninhados) ---

    // Loop externo: Unidades que o cliente LEVA (x)
    for (x = 1; x <= MAX_ITENS; x++) {
        
        // Loop interno: Unidades que o cliente PAGA (y)
        // y deve ir de 1 ate o limite, mas deve ser menor que x
        for (y = 1; y < x; y++) {
            
            // A. Condição de Prejuízo (y * p >= x * q)
            float receita = y * preco_venda_p;
            float custo = x * preco_custo_q;
            
            // Verifica se NAO ha prejuizo (Receita é maior ou igual ao Custo)
            if (receita >= custo) {
                
                // B. Calculo da Razão
                float razao_atual = (float)x / y;
                
                // Exibir todas as possibilidades validas
                printf("Leve %d pague %d: Razao = %.2f (Receita=%.2f, Custo=%.2f)\n", 
                       x, y, razao_atual, receita, custo);

                // C. Logica de Otimizacao: Encontrar a MAIOR Razão
                if (razao_atual > melhor_razao) {
                    melhor_razao = razao_atual;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    // --- 3. Saída Final ---
    
    printf("\n============================================\n");
    if (melhor_x != -1) {
        printf("A melhor promocao (maior razao e sem prejuizo) e:\n");
        printf("Leve %d pague %d\n", melhor_x, melhor_y);
        printf("(Razao de %.2f)\n", melhor_razao);
    } else {
        printf("Nao foi encontrada nenhuma promocao viavel sem prejuizo.\n");
    }
    printf("============================================\n");

    return 0; // Encerra o programa com sucesso
}