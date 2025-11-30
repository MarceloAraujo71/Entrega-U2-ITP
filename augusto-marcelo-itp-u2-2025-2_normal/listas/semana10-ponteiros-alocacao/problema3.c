#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que misturas as duas strings
char * misturar(char *str1, char *str2) {
    // 1. Calcula os tamanhos
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // 2. Aloca memória para a nova string
    // Tamanho total = len1 + len2 + 1 (para o caractere terminador '\0')
    char *resultado = (char *) malloc((len1 + len2 + 1) * sizeof(char));
    
    // Verifica se a alocação funcionou
    if (resultado == NULL) {
        exit(1); // Encerra se faltar memória
    }
    
    int i = 0; // Índice para percorrer str1 e str2
    int k = 0; // Índice para preencher a string 'resultado'
    
    // 3. Loop para intercalar
    // Continua enquanto houver caracteres em pelo menos uma das strings
    while (i < len1 || i < len2) {
        // Se ainda tem letra na str1, adiciona
        if (i < len1) {
            resultado[k] = str1[i];
            k++;
        }
        // Se ainda tem letra na str2, adiciona
        if (i < len2) {
            resultado[k] = str2[i];
            k++;
        }
        i++; // Avança para o próximo par de letras
    }
    
    // 4. Finaliza a string com o caractere nulo
    resultado[k] = '\0';
    
    return resultado;
}

int main() {
    char str1[101]; // Buffer estático para leitura (máx 100 + \0)
    char str2[101];
    
    // Leitura da primeira string
    // fgets lê até o ENTER ou até encher o buffer
    if (fgets(str1, 101, stdin) != NULL) {
        // Remove o '\n' (enter) que o fgets captura no final
        str1[strcspn(str1, "\n")] = 0;
    }
    
    // Leitura da segunda string
    if (fgets(str2, 101, stdin) != NULL) {
        str2[strcspn(str2, "\n")] = 0;
    }
    
    // Chamada da função
    char *mistura = misturar(str1, str2);
    
    // Exibição do resultado
    printf("%s\n", mistura);
    
    // Libera a memória alocada
    free(mistura);
    
    return 0;
}