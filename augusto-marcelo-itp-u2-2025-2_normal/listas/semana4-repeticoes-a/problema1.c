#include <stdio.h>
#include <math.h> // Necessario para a funcao fmax()

// Definindo a funcao principal do programa
int main() {
    // Declaracao das variaveis float
    float comprimento_folha;
    float largura_folha;
    float comprimento_bolso;
    
    // Variavel inteira para contar as dobras
    int contador_dobras = 0;

    // --- 1. Entrada de Dados ---

    printf("--- Dobrando ate caber no bolso ---\n");
    
    // Leitura do comprimento da folha
    printf("Digite o comprimento inicial da folha: ");
    if (scanf("%f", &comprimento_folha) != 1 || comprimento_folha <= 0) return 1;

    // Leitura da largura da folha
    printf("Digite a largura inicial da folha: ");
    if (scanf("%f", &largura_folha) != 1 || largura_folha <= 0) return 1;

    // Leitura do comprimento do bolso
    printf("Digite o comprimento do bolso: ");
    if (scanf("%f", &comprimento_bolso) != 1 || comprimento_bolso <= 0) return 1;

    // --- 2. Processamento (Simulacao das Dobras) ---

    /*
     * A condicao de parada do loop 'while' e:
     * CONTINUAR ENQUANTO (os dois lados da folha forem MAIORES que o bolso)
     * Ou seja, parar quando: (Lado 1 <= Bolso) OU (Lado 2 <= Bolso)
     */
    while (comprimento_folha > comprimento_bolso && largura_folha > comprimento_bolso) {
        
        // 1. Encontrar o maior lado
        float maior_lado;
        
        // A funcao fmax() da math.h e a forma mais simples de fazer isso com float
        maior_lado = fmax(comprimento_folha, largura_folha); 

        // 2. Realizar a dobra (reduzir o maior lado pela metade)
        if (maior_lado == comprimento_folha) {
            // Dobrar o comprimento
            comprimento_folha /= 2.0; 
            printf("Dobrando o COMPRIMENTO...\n");
        } else {
            // Dobrar a largura
            largura_folha /= 2.0;
            printf("Dobrando a LARGURA...\n");
        }
        
        // 3. Incrementar o contador
        contador_dobras++;
        
        // Exibir o estado atual da folha (Opcional, mas util para visualizacao)
        printf("Apos %d dobra(s): Tamanho atual da folha: %.2f por %.2f\n", 
               contador_dobras, comprimento_folha, largura_folha);
    }
    
    // --- 3. Saída de Dados ---

    printf("\n------------------------------------\n");
    printf("TAMANHO DO BOLSO: %.2f\n", comprimento_bolso);
    printf("TAMANHO FINAL DA FOLHA: %.2f por %.2f\n", comprimento_folha, largura_folha);
    
    printf("\nRESULTADO: O programa deve escrever %d dobras.\n", contador_dobras);
    printf("------------------------------------\n");

    return 0; // Encerra o programa com sucesso
}