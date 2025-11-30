#include <stdio.h>
#include <limits.h> // Necessário para usar INT_MIN

// Define o tamanho máximo do terreno (n)
#define MAX_TERRENO 30

int main() {
    int n; // Número de alturas (largura do terreno)
    int alturas[MAX_TERRENO]; // Array para armazenar as alturas
    int altura_maxima = INT_MIN; // Inicializa com o menor valor possivel
    int primeira_posicao = -1; // Indice da primeira ocorrencia da altura maxima
    int ultima_posicao = -1;   // Indice da segunda (e ultima) ocorrencia da altura maxima
    int comprimento_ponte;
    int i; // Variavel de controle do loop

    printf("--- Calculadora de Comprimento de Ponte ---\n");
    printf("Digite o numero de pontos de altura (n, max %d): ", MAX_TERRENO);
    
    // 1. Leitura de N
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_TERRENO) {
        printf("Erro: Numero de pontos invalido.\n");
        return 1;
    }

    // 2. Leitura das N Alturas
    printf("\nDigite as %d alturas do terreno (inteiros > 0): \n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &alturas[i]) != 1 || alturas[i] <= 0) {
            printf("Erro na leitura da altura.\n");
            return 1;
        }
    }

    // --- 3. Encontrar a Altura Maxima ---
    for (i = 0; i < n; i++) {
        if (alturas[i] > altura_maxima) {
            altura_maxima = alturas[i];
        }
    }

    // --- 4. Encontrar as Posicoes (Indices) ---

    // Este loop encontra a PRIMEIRA e a ULTIMA ocorrencia da altura maxima.
    for (i = 0; i < n; i++) {
        if (alturas[i] == altura_maxima) {
            // A primeira vez que a encontramos
            if (primeira_posicao == -1) {
                primeira_posicao = i;
            }
            // Sempre armazena a posicao atual como a ultima encontrada
            ultima_posicao = i;
        }
    }
    
    // --- 5. Calcular o Comprimento da Ponte ---
    
    // O comprimento e a distancia entre as duas posicoes,
    // (Posicao Final - Posicao Inicial)
    comprimento_ponte = ultima_posicao - primeira_posicao;

    // --- 6. Saída ---

    printf("\n-----------------------------------\n");
    printf("Altura maxima do terreno: %d\n", altura_maxima);
    printf("Primeira posicao do pico: %d\n", primeira_posicao + 1); // +1 para exibir base 1
    printf("Ultima posicao do pico: %d\n", ultima_posicao + 1);   // +1 para exibir base 1
    printf("\nO comprimento da ponte e: %d\n", comprimento_ponte);
    printf("-----------------------------------\n");

    return 0; // Encerra o programa com sucesso
}