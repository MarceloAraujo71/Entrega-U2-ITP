#include <stdio.h>
#include <math.h> // Necessário para sqrt(), pow(), e fabs()

// Define o número total de lances
#define NUM_LANCES 10
// Define um valor pequeno para comparação de floats (evita erro de precisao)
#define EPSILON 0.0001 

// Funcao para calcular a pontuacao principal
int calcular_pontuacao_principal(float distancia) {
    if (distancia <= 1.0) {
        return 10;
    } else if (distancia <= 2.0) {
        return 6;
    } else if (distancia <= 3.0) {
        return 4;
    } else {
        return 0;
    }
}

// Funcao para calcular a pontuacao bonus (metade da principal)
int calcular_pontuacao_bonus(int pontuacao_principal) {
    if (pontuacao_principal == 10) {
        return 5;
    } else if (pontuacao_principal == 6) {
        return 3;
    } else if (pontuacao_principal == 4) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    float x, y;             // Coordenadas do dardo atual
    float dist_atual;       // Distancia do dardo atual a (0,0)
    
    float x_anterior = 0.0; // Coordenadas do dardo anterior
    float y_anterior = 0.0;
    float dist_anterior = 0.0;
    
    int pontuacao_total = 0;
    int i; // Contador do loop

    printf("--- Problema 4: Jogo de Dardos (10 Lancamentos) ---\n");

    for (i = 1; i <= NUM_LANCES; i++) {
        
        printf("\n--- Lancamento %d ---\n", i);
        printf("Digite as coordenadas (x y): ");
        if (scanf("%f %f", &x, &y) != 2) {
            printf("Erro na leitura das coordenadas.\n");
            return 1;
        }

        // 1. Calcular a Distância Euclidiana do alvo (0, 0)
        // D = sqrt(x^2 + y^2)
        dist_atual = sqrt(pow(x, 2) + pow(y, 2));

        // 2. Calcular Pontuacao Principal
        int principal_pts = calcular_pontuacao_principal(dist_atual);
        pontuacao_total += principal_pts;
        
        printf("Distancia ao Alvo: %.2f\n", dist_atual);
        printf("Pontuacao Principal: +%d pts\n", principal_pts);

        // 3. Calcular Pontuacao Bônus
        int bonus_pts = 0;
        
        // Nao ha pontuacao bonus para o primeiro lancamento
        if (i > 1) { 
            // a. Distancia do ponto atual ao ponto anterior
            float dist_entre_lancamentos;
            
            // Distancia entre os pontos (x, y) e (x_anterior, y_anterior)
            dist_entre_lancamentos = sqrt(pow(x - x_anterior, 2) + pow(y - y_anterior, 2));
            
            // b. Verificar se o novo dardo está próximo do ÚLTIMO lançamento (distância < 1)
            // Usamos 1.0 + EPSILON para garantir que a comparacao de float seja segura
            if (dist_entre_lancamentos < 1.0 - EPSILON) {
                 bonus_pts = calcular_pontuacao_bonus(principal_pts);
                 pontuacao_total += bonus_pts;
            }
        }
        
        printf("Pontuacao Bonus (Proximidade ao anterior): +%d pts\n", bonus_pts);
        
        // 4. Atualizar as coordenadas anteriores para o proximo loop
        x_anterior = x;
        y_anterior = y;
    }
    
    // --- 4. Saída Final ---
    
    printf("\n====================================\n");
    printf("PONTUACAO TOTAL FINAL: %d pontos\n", pontuacao_total);
    printf("====================================\n");

    return 0;
}