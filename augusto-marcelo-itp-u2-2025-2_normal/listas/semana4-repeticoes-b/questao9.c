#include <stdio.h>
#include <float.h> // Necessário para a constante FLT_MAX

// Define o número máximo de unidades que cada fornecedor pode vender
#define MAX_UNIDADES 10

int main() {
    // Declaracao das variaveis float para valores monetarios
    float preco1, preco2;
    float quantia_disponivel;
    
    // Variaveis para rastrear a melhor combinacao (ideal)
    int melhor_unidades1 = -1;
    int melhor_unidades2 = -1;
    
    // Inicializamos o menor restante com o maior valor float possivel
    // Isso garante que a primeira combinacao valida sera sempre o menor restante inicial
    float menor_restante = FLT_MAX; 

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
    
    // --- 2. Processamento (Loops Aninhados para Otimizacao) ---

    // Loop externo: Unidades do Fornecedor 1 (de 0 a 10)
    for (int unidades1 = 0; unidades1 <= MAX_UNIDADES; unidades1++) {
        
        // Loop interno: Unidades do Fornecedor 2 (de 0 a 10)
        for (int unidades2 = 0; unidades2 <= MAX_UNIDADES; unidades2++) {
            
            float custo_total = (unidades1 * preco1) + (unidades2 * preco2);
            
            // Verifica se a compra e possivel
            if (custo_total <= quantia_disponivel) {
                
                float restante = quantia_disponivel - custo_total;
                
                // Logica de Otimizacao: Se o restante atual for menor que o melhor ja encontrado
                if (restante < menor_restante) {
                    menor_restante = restante; // Atualiza o menor restante
                    melhor_unidades1 = unidades1; // Armazena a combinacao
                    melhor_unidades2 = unidades2;
                }
            }
        }
    }

    // --- 3. Saída Final ---
    
    printf("\n============================================\n");
    
    // Verifica se alguma compra foi possivel (se as variaveis de unidades foram atualizadas)
    if (melhor_unidades1 != -1) {
        printf("Resta menos comprando %d do primeiro e %d do segundo\n", 
               melhor_unidades1, melhor_unidades2);
        printf("(Valor restante: R$ %.2f)\n", menor_restante);
    } else {
        // Isso so acontece se o orcamento for muito baixo para comprar ate mesmo 0 unidades,
        // o que so ocorre se a quantia disponivel for negativa, ou se os precos forem muito altos.
        printf("Nao foi possivel realizar nenhuma compra dentro do orcamento.\n");
    }
    printf("============================================\n");

    return 0;
}