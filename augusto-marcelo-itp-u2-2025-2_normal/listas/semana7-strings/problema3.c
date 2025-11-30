#include <stdio.h>
#include <string.h>

int main() {
    char alvo[50];   // Nome do aluno que queremos verificar
    char token[50];  // Variável temporária para ler cada palavra/data da entrada
    int total_aulas = 0;
    int presencas = 0;

    // 1. Lê o nome do aluno alvo
    // A função scanf retorna 1 se leu com sucesso. Se não, encerra.
    if (scanf("%s", alvo) != 1) {
        return 0;
    }

    // 2. Lê o restante da entrada, palavra por palavra
    // O loop continua enquanto houver palavras para ler (até o fim da entrada/EOF)
    while (scanf("%s", token) != EOF) {
        
        // Verifica se o "token" atual é uma data.
        // O jeito mais fácil é ver se tem uma barra '/' na string.
        if (strchr(token, '/') != NULL) {
            total_aulas++;
        } 
        else {
            // Se não tem barra, é um nome.
            // Verificamos se é o nome do aluno alvo.
            if (strcmp(token, alvo) == 0) {
                presencas++;
            }
        }
    }

    // 3. Calcula e imprime o número de faltas
    // Faltas = Aulas que ocorreram - Aulas que ele foi
    printf("%d\n", total_aulas - presencas);

    return 0;
}