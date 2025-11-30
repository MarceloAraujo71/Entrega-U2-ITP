#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

// Função para alocar um vetor dinamicamente
// Recebe o tamanho n e retorna um ponteiro para o bloco de memória alocado
int* alocarVetor(int n) {
    // malloc reserva (n * tamanho_de_um_inteiro) bytes na memória
    int* v = (int*) malloc(n * sizeof(int));
    return v;
}

// Função para ler os elementos do vetor
void lerVetor(int* v, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

// Função para somar dois vetores
// Retorna um NOVO vetor com o resultado da soma
int* somaVetores(int* u, int* v, int n) {
    int* resultado = alocarVetor(n); // Aloca o vetor de resposta
    
    for (int i = 0; i < n; i++) {
        resultado[i] = u[i] + v[i];
    }
    
    return resultado;
}

int main() {
    int n1, n2;
    
    // 1. Ler dimensões
    scanf("%d %d", &n1, &n2);
    
    // 2. Alocar vetores dinamicamente
    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);
    
    // 3. Ler elementos
    lerVetor(u, n1);
    lerVetor(v, n2);
    
    // 4. Verificar compatibilidade e somar
    if (n1 != n2) {
        printf("dimensoes incompativeis\n");
    } else {
        // Chama a função de soma
        int *soma = somaVetores(u, v, n1);
        
        // Exibe o resultado
        for (int i = 0; i < n1; i++) {
            printf("%d", soma[i]);
            // Adiciona espaço apenas se não for o último número
            if (i < n1 - 1) printf(" ");
        }
        printf("\n");
        
        // Libera a memória do vetor de resultado
        free(soma);
    }
    
    // Libera a memória dos vetores de entrada (Boa prática)
    free(u);
    free(v);
    
    return 0;
}