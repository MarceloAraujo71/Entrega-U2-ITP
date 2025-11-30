#include <stdio.h>

// Define o tamanho máximo de questões para o array
#define MAX_QUESTOES 20

int main() {
    int n; // Número de questões
    int gabarito[MAX_QUESTOES]; // Array para as respostas do gabarito
    int respostas_aluno[MAX_QUESTOES]; // Array para as respostas do aluno
    int acertos = 0; // Contador de acertos
    int i; // Variável de controle do loop

    // --- 1. Leitura do Numero de Questoes (N) ---

    printf("--- Corretor de Prova Objetiva do ENEM ---\n");
    printf("Digite o numero de questoes (1 a %d): ", MAX_QUESTOES);
    
    // Verifica se a leitura foi bem sucedida e se N esta dentro dos limites
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_QUESTOES) {
        printf("Erro: Numero de questoes invalido.\n");
        return 1;
    }

    // --- 2. Leitura do Gabarito ---

    printf("\nDigite as %d respostas do gabarito (separadas por espaco, ex: 1 2 3 4): \n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &gabarito[i]) != 1) {
            printf("Erro na leitura do gabarito.\n");
            return 1;
        }
    }

    // --- 3. Leitura das Respostas do Aluno ---

    printf("\nDigite as %d respostas do aluno (separadas por espaco, ex: 1 5 3 5): \n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &respostas_aluno[i]) != 1) {
            printf("Erro na leitura das respostas do aluno.\n");
            return 1;
        }
    }

    // --- 4. Processamento (Comparacao e Contagem) ---

    for (i = 0; i < n; i++) {
        // Compara a resposta do gabarito com a resposta do aluno na mesma posicao (questao i)
        if (gabarito[i] == respostas_aluno[i]) {
            acertos++; // Incrementa o contador se as respostas forem iguais
        }
    }

    // --- 5. Saída Formatada (Exibicao do Resultado) ---

    printf("\n--------------------------\n");
    printf("%d ", acertos);
    
    // Logica para a string correta ("acerto" ou "acertos")
    if (acertos == 1) {
        printf("acerto\n");
    } else {
        printf("acertos\n");
    }
    printf("--------------------------\n");

    return 0; // Encerra o programa com sucesso
}