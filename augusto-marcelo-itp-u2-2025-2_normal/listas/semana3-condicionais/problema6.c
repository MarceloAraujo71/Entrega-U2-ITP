#include <stdio.h>
#include <ctype.h> // Necessario para a funcao tolower()
#include <stdbool.h> // Necessario para o tipo bool

// Definindo a funcao principal do programa
int main() {
    // Declaracao das variaveis char para as respostas (S/N)
    char resposta_febre, resposta_cabeca, resposta_corpo, resposta_tosse;

    // Variaveis booleanas para facilitar a logica
    bool tem_febre, tem_cabeca, tem_corpo, tem_tosse;

    // --- 1. Entrada de Dados ---

    printf("--- Diagnostico Medico Basico (Responda S para Sim ou N para Nao) ---\n");
    
    printf("1. Tem febre? (S/N): ");
    if (scanf(" %c", &resposta_febre) != 1) return 1;

    printf("2. Tem dor de cabeca? (S/N): ");
    if (scanf(" %c", &resposta_cabeca) != 1) return 1;

    printf("3. Tem dor no corpo? (S/N): ");
    if (scanf(" %c", &resposta_corpo) != 1) return 1;

    printf("4. Tem tosse? (S/N): ");
    if (scanf(" %c", &resposta_tosse) != 1) return 1;

    // --- 2. Preparacao e Conversao da Logica ---

    // Converte as respostas para minúsculo e atribui o valor booleano
    tem_febre  = (tolower(resposta_febre) == 's');
    tem_cabeca = (tolower(resposta_cabeca) == 's');
    tem_corpo  = (tolower(resposta_corpo) == 's');
    tem_tosse  = (tolower(resposta_tosse) == 's');

    printf("\n--- Diagnostico ---\n");

    // --- 3. Processamento (Logica de Diagnostico) ---

    // 1. Febre + Dor de cabeça + Dor no corpo: "Possível gripe"
    if (tem_febre && tem_cabeca && tem_corpo) {
        printf("Sugerimos: Possivel gripe.\n");
    }
    // 2. Tosse + Febre: "Possível resfriado"
    else if (tem_tosse && tem_febre) {
        // Esta condicao deve ser verificada antes da 'Apenas febre'
        printf("Sugerimos: Possivel resfriado.\n");
    }
    // 3. Apenas dor de cabeça: "Possível enxaqueca"
    else if (tem_cabeca && !tem_febre && !tem_corpo && !tem_tosse) {
        printf("Sugerimos: Possivel enxaqueca.\n");
    }
    // 4. Apenas febre: "Consulte um médico"
    else if (tem_febre && !tem_cabeca && !tem_corpo && !tem_tosse) {
        printf("Sugerimos: Consulte um medico.\n");
    }
    // 5. Nenhum sintoma: "Você parece estar bem"
    else if (!tem_febre && !tem_cabeca && !tem_corpo && !tem_tosse) {
        printf("Sugerimos: Voce parece estar bem.\n");
    }
    // 6. Qualquer outra combinação (catch-all)
    else {
        printf("Sugerimos: Consulte um medico para avaliacao.\n");
    }

    printf("---------------------------\n");

    return 0; // Encerra o programa com sucesso
}