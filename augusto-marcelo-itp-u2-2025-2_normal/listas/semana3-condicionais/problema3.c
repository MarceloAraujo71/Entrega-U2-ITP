#include <stdio.h>

// Definindo a função principal do programa
int main() {
    // Declaracao das variaveis float para as notas e media
    float nota1, nota2, nota3;
    float media;
    float nota_minima_final;

    // --- 1. Entrada de Dados ---

    printf("--- Sistema de Notas e Classificacao ---\n");
    
    // Leitura das tres notas
    printf("Digite a primeira nota: ");
    if (scanf("%f", &nota1) != 1) return 1;

    printf("Digite a segunda nota: ");
    if (scanf("%f", &nota2) != 1) return 1;

    printf("Digite a terceira nota: ");
    if (scanf("%f", &nota3) != 1) return 1;

    // --- 2. Processamento (Calculo da Media) ---

    media = (nota1 + nota2 + nota3) / 3.0;

    printf("\n------------------------------------\n");
    printf("Media Aritmetica: %.2f\n", media);
    printf("------------------------------------\n");

    // --- 3. Classificacao e Calculo de Nota Final ---

    // Aprovado: media >= 7.0
    if (media >= 7.0) {
        printf("RESULTADO: APROVADO!\n");
    } 
    // Reprovado: media < 4.0
    else if (media < 4.0) {
        printf("RESULTADO: REPROVADO.\n");
    } 
    // Recuperacao: 4.0 <= media < 7.0
    else {
        printf("RESULTADO: EM RECUPERACAO.\n");

        // Media Final precisa ser >= 5.0
        // Formula: (media + nota_final) / 2 = 5.0
        // Nota_final = (5.0 * 2) - media
        
        nota_minima_final = (10.0 - media); // 5.0 * 2 = 10.0

        // Garante que a nota minima nao seja maior que 10.0, pois e o limite maximo de uma prova
        if (nota_minima_final > 10.0) {
            nota_minima_final = 10.0;
        } else if (nota_minima_final < 0.0) {
            // Em tese, a media > 4.0 ja impede nota_minima_final de ser negativa
            nota_minima_final = 0.0; 
        }

        printf("Para ser aprovado, o aluno precisa tirar no minimo:\n");
        printf("NOTA FINAL MINIMA: %.2f\n", nota_minima_final);
        printf("------------------------------------\n");
    }
    
    return 0; // Encerra o programa com sucesso
}