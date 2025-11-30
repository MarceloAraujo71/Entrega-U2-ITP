#include <stdio.h>

int main() {
    int n;
    int i;
    int piloto_id;
    
    // Vetor para armazenar onde cada piloto largou.
    // O índice do vetor será o ID do piloto (1 a 20).
    // Usamos tamanho 25 para ter folga e poder usar índices de 1 a N diretamente.
    int posicao_largada[25]; 

    // 1. Leitura da quantidade de pilotos
    scanf("%d", &n);

    // 2. Leitura da ordem de LARGADA
    for (i = 1; i <= n; i++) {
        scanf("%d", &piloto_id);
        // Armazenamos a posição 'i' no índice correspondente ao ID do piloto
        posicao_largada[piloto_id] = i; 
    }

    int maior_ganho = -999; // Começa com um valor muito baixo
    int piloto_vencedor = -1;
    int houve_empate = 0;   // Flag para verificar empate (0 = falso, 1 = verdadeiro)

    // 3. Leitura da ordem de CHEGADA e cálculo
    for (i = 1; i <= n; i++) {
        scanf("%d", &piloto_id);

        // O ganho é a posição onde largou menos a posição onde chegou (i)
        // Exemplo: Largou em 5º, chegou em 1º -> 5 - 1 = 4 posições ganhas.
        int ganho = posicao_largada[piloto_id] - i;

        if (ganho > maior_ganho) {
            maior_ganho = ganho;
            piloto_vencedor = piloto_id;
            houve_empate = 0; // Novo líder isolado, cancela empate anterior
        } 
        else if (ganho == maior_ganho) {
            houve_empate = 1; // Empate detectado no topo
        }
    }

    // 4. Exibição do resultado
    // A regra diz: empate entre pilotos OU se ninguém ganhou posições (ganho <= 0)
    if (houve_empate || maior_ganho <= 0) {
        printf("empate\n");
    } else {
        printf("%d\n", piloto_vencedor);
    }

    return 0;
}