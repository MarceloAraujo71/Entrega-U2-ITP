#include <stdio.h>
#include <math.h> // Necessário para a função sqrt()

// Definindo a função principal do programa
int main() {
    // Declaracao das variaveis float para os coeficientes, discriminante e raizes
    float a, b, c;
    float delta;
    float x1, x2; // As duas raizes

    // --- 1. Entrada de Dados ---

    printf("--- Solucionador de Equacao do 2o Grau (ax^2 + bx + c = 0) ---\n");
    
    // Leitura dos coeficientes a, b e c
    printf("Digite o coeficiente a: ");
    if (scanf("%f", &a) != 1) return 1;

    printf("Digite o coeficiente b: ");
    if (scanf("%f", &b) != 1) return 1;

    printf("Digite o coeficiente c: ");
    if (scanf("%f", &c) != 1) return 1;

    // --- 2. Processamento (Verificacao e Calculo) ---

    printf("\n------------------------------------\n");
    
    // A. Verificar se é uma equação do segundo grau (a != 0)
    if (a == 0) {
        printf("ERRO: O coeficiente 'a' deve ser diferente de zero para ser uma equacao do 2o grau.\n");
        // Neste caso, a equacao e de 1o grau (bx + c = 0)
        printf("A equacao e de 1o grau.\n");
        return 1;
    }

    // B. Calcular o discriminante (Delta = b² - 4ac)
    delta = b * b - 4 * a * c;

    printf("Coeficientes: a=%.2f, b=%.2f, c=%.2f\n", a, b, c);
    printf("Discriminante (Delta): %.2f\n", delta);
    printf("------------------------------------\n");

    // C. Determinar e exibir as raízes conforme o valor de Delta
    
    if (delta > 0) {
        // Se Delta > 0: duas raízes reais distintas
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("RESULTADO: DUAS RAIZES REAIS DISTINTAS (Delta > 0)\n");
        printf("Raiz 1 (x1): %.4f\n", x1);
        printf("Raiz 2 (x2): %.4f\n", x2);
    } 
    else if (delta == 0) {
        // Se Delta = 0: uma raiz real (ou duas raizes iguais)
        x1 = -b / (2 * a);

        printf("RESULTADO: UMA RAIZ REAL (OU DUAS IGUAIS) (Delta = 0)\n");
        printf("Raiz (x): %.4f\n", x1);
    } 
    else {
        // Se Delta < 0: não possui raízes reais
        printf("RESULTADO: NAO POSSUI RAIZES REAIS (Delta < 0)\n");
        printf("As raizes sao complexas.\n");
    }

    return 0; // Encerra o programa com sucesso
}