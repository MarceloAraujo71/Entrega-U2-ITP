#include <stdio.h>
#include <stdlib.h>

// Função que busca todas as ocorrências de um valor em um vetor
int * buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd) {
    int i;
    int contador = 0;

    // 1. Primeiro passo: Contar quantas vezes o 'valor' aparece
    for (i = 0; i < n; i++) {
        if (v[i] == valor) {
            contador++;
        }
    }

    // Atualiza a variável qtd via ponteiro
    *qtd = contador;

    // Se não houver ocorrências, retorna NULL
    if (contador == 0) {
        return NULL;
    }

    // 2. Segundo passo: Alocar o vetor de índices dinamicamente
    // O tamanho será exatamente a quantidade de ocorrências encontradas
    int *indices = (int *) malloc(contador * sizeof(int));
    
    // Verifica se a alocação funcionou
    if (indices == NULL) {
        return NULL; // Falha de memória
    }

    // 3. Terceiro passo: Preencher o vetor de índices
    int k = 0; // Índice para controlar a posição no vetor 'indices'
    for (i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[k] = i; // Guarda a posição original
            k++;
        }
    }

    // Retorna o endereço base do novo vetor
    return indices;
}

int main() {
    int n, valor_busca;
    int qtd_ocorrencias = 0;
    int dummy_maior; // Variável apenas para satisfazer a assinatura da função

    // Leitura do tamanho
    scanf("%d", &n);

    // Alocação dinâmica do vetor de entrada
    int *vetor = (int *) malloc(n * sizeof(int));

    // Leitura dos elementos
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Leitura do valor a ser buscado
    scanf("%d", &valor_busca);

    // Chamada da função
    // Passamos &dummy_maior apenas para cumprir a assinatura
    int *resultado = buscaNoVetor(vetor, n, valor_busca, &dummy_maior, &qtd_ocorrencias);

    // Exibição dos resultados
    if (resultado == NULL) {
        printf("Nenhuma ocorrencia\n");
    } else {
        // Imprime a quantidade
        printf("%d\n", qtd_ocorrencias);
        
        // Imprime os índices
        for (int i = 0; i < qtd_ocorrencias; i++) {
            printf("%d", resultado[i]);
            // Adiciona espaço entre números, mas evita no final (opcional, mas boa prática)
            if (i < qtd_ocorrencias - 1) {
                printf(" ");
            }
        }
        printf("\n");

        // Libera a memória do vetor de resultados
        free(resultado);
    }

    // Libera a memória do vetor de entrada
    free(vetor);

    return 0;
}