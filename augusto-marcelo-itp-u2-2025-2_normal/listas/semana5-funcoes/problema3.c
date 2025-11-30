#include <stdio.h>
#include <math.h>   // Necessário para as funções sin(), cos() e fabs()
#include <stdbool.h> // Necessário para o tipo bool

// Define as constantes de seguranca de altura
#define ALTURA_MINIMA 0.0
#define ALTURA_MAXIMA 2.0
// Define o deslocamento da sonda (raio de 0.2)
#define RAIO_SONDA 0.2
// Define o deslocamento dos vizinhos (2.0)
#define DESLOCAMENTO_VIZINHO 2.0

// --- FUNÇÃO 1: Calcula a altura do terreno ---

/**
 * Calcula a altura da superficie na coordenada (x, y)
 * Formula: f(x, y) = sin(cos(y) + x) + cos(y + sin(x))
 */
float calcular_altura(float x, float y) {
    return sin(cos(y) + x) + cos(y + sin(x));
}

// --- FUNÇÃO AUXILIAR: Verifica se a altura é segura ---
bool eh_altura_segura(float altura) {
    return altura >= ALTURA_MINIMA && altura <= ALTURA_MAXIMA;
}

// --- FUNÇÃO 2: Verifica se uma coordenada é um ponto de pouso seguro ---

/**
 * Verifica se o ponto central (x, y) e os 4 pontos da sonda estao em altura segura.
 */
bool eh_ponto_seguro(float x, float y) {
    
    // 1. Ponto Central (P)
    if (!eh_altura_segura(calcular_altura(x, y))) {
        return false;
    }

    // 2. Os 4 Pontos de Contato da Sonda (em verde)
    
    // Deslocamentos (dx e dy)
    float d = RAIO_SONDA; 
    
    // Ponto A: (x + 0.2, y + 0.2)
    if (!eh_altura_segura(calcular_altura(x + d, y + d))) {
        return false;
    }
    // Ponto B: (x - 0.2, y - 0.2)
    if (!eh_altura_segura(calcular_altura(x - d, y - d))) {
        return false;
    }
    // Ponto C: (x + 0.2, y - 0.2)
    if (!eh_altura_segura(calcular_altura(x + d, y - d))) {
        return false;
    }
    // Ponto D: (x - 0.2, y + 0.2)
    if (!eh_altura_segura(calcular_altura(x - d, y + d))) {
        return false;
    }

    // Se todos os 5 pontos (centro + 4 cantos) sao seguros
    return true;
}

// --- FUNÇÃO PRINCIPAL ---
int main() {
    float x_pouso, y_pouso; // Coordenadas de pouso p = (x, y)
    
    printf("--- Classificacao de Local de Pouso da Sonda ---\n");
    
    // Leitura da coordenada de pouso
    printf("Digite a coordenada X (float): ");
    if (scanf("%f", &x_pouso) != 1) return 1;

    printf("Digite a coordenada Y (float): ");
    if (scanf("%f", &y_pouso) != 1) return 1;

    // --- 1. Verificacao do Ponto Central (Regra 1) ---
    
    if (!eh_ponto_seguro(x_pouso, y_pouso)) {
        printf("\nCLASSIFICACAO: troque de coordenada\n");
        return 0;
    }

    // --- 2. Verificacao dos Vizinhos (Regras 2b, 2c, 2d) ---
    
    printf("\nVerificando vizinhanca...\n");
    
    int vizinhos_seguros = 0;
    
    // Coordenadas dos 4 vizinhos (a, b, c, d em azul)
    float vizinhos_x[] = {x_pouso + DESLOCAMENTO_VIZINHO, x_pouso - DESLOCAMENTO_VIZINHO, x_pouso, x_pouso};
    float vizinhos_y[] = {y_pouso, y_pouso, y_pouso - DESLOCAMENTO_VIZINHO, y_pouso + DESLOCAMENTO_VIZINHO};

    // Loop para verificar cada vizinho
    for (int i = 0; i < 4; i++) {
        if (eh_ponto_seguro(vizinhos_x[i], vizinhos_y[i])) {
            vizinhos_seguros++;
        }
    }
    
    printf("Numero de locais vizinhos seguros: %d\n", vizinhos_seguros);

    // --- 3. Classificacao Final ---
    
    printf("CLASSIFICACAO: ");
    
    if (vizinhos_seguros == 4) {
        printf("seguro\n"); // 4 pontos seguros
    } else if (vizinhos_seguros == 2 || vizinhos_seguros == 3) {
        printf("relativamente seguro\n"); // 2 ou 3 pontos seguros
    } else { // vizinhos_seguros == 0 ou 1
        printf("inseguro\n"); // 0 ou 1 ponto seguro
    }

    return 0;
}