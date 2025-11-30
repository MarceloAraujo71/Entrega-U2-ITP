#include <stdio.h>
#include <stdbool.h>
#include <math.h> // Necessario para a funcao sqrt() e pow()

// Definindo a funcao principal do programa
int main() {
    // --- 1. Declaracao de Variaveis ---
    
    // Coordenadas e comprimento, declarados como float
    float x_aranha, y_aranha;       // Coordenada atual do Homem-Aranha (x, y)
    float comp_max_teia;            // Comprimento maximo da teia (float)
    int n_alvos;                    // Quantidade de alvos (inteiro)
    float ax, ay;                   // Coordenadas do alvo atual (ax, ay)
    
    float dist_euclidiana;          // Distancia entre a posicao e o alvo
    int i;                          // Contador do loop

    // --- 2. Leitura da Entrada ---

    printf("--- Problema 2: Salve o Homem-Aranha ---\n");
    
    // 1. Coordenada inicial do Homem-Aranha (x, y)
    printf("1. Coordenada inicial (x y): ");
    if (scanf("%f %f", &x_aranha, &y_aranha) != 2) return 1;

    // 2. Comprimento maximo da teia
    printf("2. Comprimento maximo da teia: ");
    if (scanf("%f", &comp_max_teia) != 1) return 1;

    // 3. Quantidade de alvos (n)
    printf("3. Quantidade de alvos (n): ");
    if (scanf("%d", &n_alvos) != 1 || n_alvos <= 0) {
        printf("Quantidade de alvos invalida.\n");
        return 1;
    }

    // 4. Leitura das n coordenadas dos alvos (x, y)
    printf("4. Digite as coordenadas de cada um dos %d alvos:\n", n_alvos);

    // --- 3. Simulacao do Movimento (Loop) ---

    // Flag para verificar se o Homem-Aranha falhou
    bool falhou = false; 

    for (i = 1; i <= n_alvos; i++) {
        
        // Leitura do alvo atual
        printf("   Alvo %d (ax ay): ", i);
        if (scanf("%f %f", &ax, &ay) != 2) return 1;

        // Se ele ja falhou em um alvo anterior, nao ha necessidade de continuar
        if (falhou) continue; 
        
        // A. CALCULO DA DISTANCIA EUCLIDIANA (D)
        
        // D = sqrt((ax - x)^2 + (ay - y)^2)
        dist_euclidiana = sqrt(pow(ax - x_aranha, 2) + pow(ay - y_aranha, 2));

        // B. VERIFICACAO DE ALCANCE
        if (dist_euclidiana < comp_max_teia) {
            
            // C. ATUALIZACAO DA NOVA COORDENADA (Se alcancou)
            // (x', y') = (2*ax - x, 2*ay - y)
            float x_novo, y_novo;
            
            x_novo = 2 * ax - x_aranha;
            y_novo = 2 * ay - y_aranha;
            
            // Atualiza a posicao do Homem-Aranha
            x_aranha = x_novo;
            y_aranha = y_novo;
            
        } else {
            // Se a teia for curta demais (nao alcancou)
            falhou = true;
        }
    }

    // --- 4. Saída do Resultado ---
    
    printf("\n--- VEREDICTO ---\n");
    if (!falhou) {
        // Se a flag 'falhou' for falsa, significa que ele alcancou todos os alvos
        printf("S\n"); 
    } else {
        // Caso contrario, ele falhou em algum momento
        printf("N\n");
    }

    return 0;
}