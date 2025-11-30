#include <stdio.h>
#include <stdlib.h> // Para a funcao system() (opcional, para limpar a tela)
#include <stdbool.h> // Para usar o tipo bool (opcional)

// Define o numero total de ilhas
#define NUM_ILHAS 10

int main() {
    // Array para armazenar as sugestoes dos nativos (Mapa de Ilhas)
    // mapa[i] = j significa: da ilha i, o tesouro esta na ilha j
    int mapa[NUM_ILHAS];

    // Array para contar o numero de vezes que cada ilha foi visitada
    // Inicializado em zero.
    int visitas[NUM_ILHAS] = {0};

    // Variavel que armazena a ilha atual que Cheque esperto esta visitando
    int ilha_atual = 0;
    
    // Variavel para armazenar a proxima ilha sugerida
    int proxima_ilha;
    
    // Variavel que armazena a resposta final
    int primeira_revisita = -1;

    // --- 1. Entrada de Dados ---

    printf("--- Problema 4: Em Busca do Tesouro Perdido ---\n");
    printf("Digite as 10 sugestoes dos nativos (ilha 0 a ilha 9):\n");
    printf("Exemplo: 8 4 3 0 7 4 2 1 5 2\n");
    
    // Leitura das 10 sugestoes para preencher o array 'mapa'
    for (int i = 0; i < NUM_ILHAS; i++) {
        if (scanf("%d", &mapa[i]) != 1 || mapa[i] < 0 || mapa[i] >= NUM_ILHAS) {
            fprintf(stderr, "Erro na leitura ou valor invalido (0-9) para a sugestao da ilha %d.\n", i);
            return 1;
        }
    }

    // --- 2. Processamento (Simulacao do Caminho) ---

    // Cheque esperto visita a ilha inicial (ilha 0)
    visitas[ilha_atual]++;
    
    // Loop principal: continua a viagem ate encontrar a primeira ilha revisitada
    // A ilha 0 ja foi visitada 1 vez. O loop para quando a ilha atual for visitada 2 vezes.
    while (visitas[ilha_atual] < 2) {
        
        // 1. Determinar a proxima ilha a ser visitada
        proxima_ilha = mapa[ilha_atual];
        
        // 2. Atualizar a posicao (mudar para a proxima ilha)
        ilha_atual = proxima_ilha;
        
        // 3. Registrar a visita
        visitas[ilha_atual]++;
        
        // DEBUG (Opcional): Imprime a sequencia de visitas
        // printf("Visitando ilha %d (Total de visitas: %d)\n", ilha_atual, visitas[ilha_atual]);

        // 4. Verificar a condicao de parada
        if (visitas[ilha_atual] == 2) {
            // Se a ilha atual foi visitada 2 vezes, essa e a resposta
            primeira_revisita = ilha_atual;
            break; // Sai do loop
        }
    }

    // --- 3. Saída do Resultado ---
    
    printf("\n--- Saida ---\n");
    
    if (primeira_revisita != -1) {
        printf("A primeira ilha a ser visitada uma segunda vez e a ilha: %d\n", primeira_revisita);
    } else {
        // Isso so ocorreria se houvesse um erro logico ou se o mapa fosse infinito
        printf("Nao foi possivel encontrar uma ilha revisitada.\n");
    }

    return 0;
}