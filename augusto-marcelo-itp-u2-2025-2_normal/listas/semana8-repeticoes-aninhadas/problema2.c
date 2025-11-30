#include <stdio.h>
#include <string.h>

// Definimos uma estrutura para representar um Mês
typedef struct {
    char nome[15];
    int chuva;
} Mes;

int main() {
    // Inicializamos o vetor com os nomes dos meses
    // A chuva começa com 0, pois vamos ler depois
    Mes meses[12] = {
        {"Janeiro", 0}, {"Fevereiro", 0}, {"Marco", 0}, {"Abril", 0},
        {"Maio", 0}, {"Junho", 0}, {"Julho", 0}, {"Agosto", 0},
        {"Setembro", 0}, {"Outubro", 0}, {"Novembro", 0}, {"Dezembro", 0}
    };

    int i, j;

    // 1. Leitura dos dados
    // O usuário digita 12 números sequencialmente
    for (i = 0; i < 12; i++) {
        scanf("%d", &meses[i].chuva);
    }

    // 2. Ordenação (Selection Sort - Decrescente)
    // Queremos do MAIOR para o MENOR
    for (i = 0; i < 12 - 1; i++) {
        int indice_maior = i;

        // Procura o maior valor no restante do vetor
        for (j = i + 1; j < 12; j++) {
            if (meses[j].chuva > meses[indice_maior].chuva) {
                indice_maior = j;
            }
        }

        // Se encontrou alguém maior que o atual, troca de lugar
        if (indice_maior != i) {
            Mes temp = meses[i];
            meses[i] = meses[indice_maior];
            meses[indice_maior] = temp;
        }
    }

    // 3. Exibição dos resultados
    for (i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i].nome, meses[i].chuva);
    }

    return 0;
}