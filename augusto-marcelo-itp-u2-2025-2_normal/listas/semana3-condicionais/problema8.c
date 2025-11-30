#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool
#include <math.h>    // Para usar a funcao fabs() para comparacao de floats

// Definindo a funcao principal do programa
int main() {
    // Declaracao das variaveis float para os lados
    float l1, l2, l3;

    // --- 1. Entrada de Dados ---

    printf("--- Validador e Classificador de Triangulos ---\n");
    
    // Leitura dos tres lados
    printf("Digite o comprimento do Lado 1: ");
    if (scanf("%f", &l1) != 1 || l1 <= 0) return 1;

    printf("Digite o comprimento do Lado 2: ");
    if (scanf("%f", &l2) != 1 || l2 <= 0) return 1;

    printf("Digite o comprimento do Lado 3: ");
    if (scanf("%f", &l3) != 1 || l3 <= 0) return 1;

    // --- 2. Verificacao da Condicao de Existencia ---
    
    // Condicao: A soma de dois lados deve ser sempre maior que o terceiro lado
    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1) {
        
        printf("\n------------------------------------\n");
        printf("RESULTADO: Os valores FORMAM um triangulo.\n");
        
        // --- 3. Classificacao por Lados ---
        
        printf("\nCLASSIFICACAO POR LADOS:\n");
        if (l1 == l2 && l2 == l3) {
            printf(" - Triangulo EQUILATERO (Todos os lados iguais)\n");
        } else if (l1 == l2 || l1 == l3 || l2 == l3) {
            printf(" - Triangulo ISOSCELES (Dois lados iguais)\n");
        } else {
            printf(" - Triangulo ESCALENO (Todos os lados diferentes)\n");
        }
        
        // --- 4. Classificacao por Angulos ---

        // Variaveis para armazenar os lados ordenados: A (maior), B e C (menores)
        float A, B, C;

        // Logica simples para encontrar o maior lado (A)
        if (l1 >= l2 && l1 >= l3) {
            A = l1; B = l2; C = l3;
        } else if (l2 >= l1 && l2 >= l3) {
            A = l2; B = l1; C = l3;
        } else {
            A = l3; B = l1; C = l2;
        }

        // Variaveis para os quadrados (para evitar a necessidade de linkar math.h com pow())
        float A2 = A * A;
        float B2_C2 = (B * B) + (C * C);
        
        // Epsilon para comparacao de floats (evita erro de precisao)
        // Valores de ponto flutuante raramente sao exatamente iguais
        const float EPSILON = 0.0001; 

        printf("\nCLASSIFICACAO POR ANGULOS (A = maior lado):\n");

        // Retangulo (A² = B² + C²)
        if (fabs(A2 - B2_C2) < EPSILON) {
            printf(" - Triangulo RETANGULO (a^2 = b^2 + c^2)\n");
        }
        // Acutangulo (A² < B² + C²)
        else if (A2 < B2_C2) {
            printf(" - Triangulo ACUTANGULO (a^2 < b^2 + c^2)\n");
        }
        // Obtusangulo (A² > B² + C²)
        else {
            printf(" - Triangulo OBTUSANGULO (a^2 > b^2 + c^2)\n");
        }

    } else {
        // Nao forma um triangulo
        printf("\n------------------------------------\n");
        printf("RESULTADO: Os valores NAO formam um triangulo (A soma de dois lados e menor que o terceiro).\n");
    }

    printf("------------------------------------\n");
    return 0; // Encerra o programa com sucesso
}