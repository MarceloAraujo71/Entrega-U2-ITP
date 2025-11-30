#include <stdio.h>
#include <ctype.h> // Biblioteca para tolower()

// Definindo a função principal do programa
int main() {
    // Declaracao das variaveis char para armazenar as jogadas
    char jogada1, jogada2;

    // --- 1. Entrada de Dados ---

    printf("--- Jogo: Pedra, Papel, Tesoura (Jokenpo) ---\n");
    printf("P: Pedra | A: Papel | T: Tesoura\n");
    
    // Leitura da jogada do Jogador 1
    printf("\nJogador 1, digite sua jogada (P, A ou T): ");
    if (scanf(" %c", &jogada1) != 1) return 1;

    // Leitura da jogada do Jogador 2
    printf("Jogador 2, digite sua jogada (P, A ou T): ");
    if (scanf(" %c", &jogada2) != 1) return 1;

    // --- 2. Preparacao e Normalizacao (Para aceitar maiusculas ou minusculas) ---
    
    // Converte as jogadas para minusculo para simplificar a logica de comparacao
    jogada1 = tolower(jogada1);
    jogada2 = tolower(jogada2);

    // --- 3. Processamento (Determinacao do Vencedor) ---
    
    printf("\n--- Resultado da Partida ---\n");

    // Verifica se as jogadas sao validas
    if ((jogada1 != 'p' && jogada1 != 'a' && jogada1 != 't') || 
        (jogada2 != 'p' && jogada2 != 'a' && jogada2 != 't')) {
        printf("ERRO: Uma ou ambas as jogadas sao invalidas. Use apenas P, A ou T.\n");
        return 1;
    }


    // Caso de Empate
    if (jogada1 == jogada2) {
        printf("JOGADAS IGUAIS: EMPATE!\n");
    } 
    // Casos de Vitoria/Derrota
    else {
        // Usamos um switch para verificar a jogada do Jogador 1
        switch (jogada1) {
            case 'p': // Pedra
                // Pedra vence Tesoura ('t')
                if (jogada2 == 't') {
                    printf("Pedra vence Tesoura. JOGADOR 1 VENCEU!\n");
                } 
                // Pedra perde para Papel ('a')
                else if (jogada2 == 'a') {
                    printf("Papel vence Pedra. JOGADOR 2 VENCEU!\n");
                }
                break;
                
            case 'a': // Papel
                // Papel vence Pedra ('p')
                if (jogada2 == 'p') {
                    printf("Papel vence Pedra. JOGADOR 1 VENCEU!\n");
                } 
                // Papel perde para Tesoura ('t')
                else if (jogada2 == 't') {
                    printf("Tesoura vence Papel. JOGADOR 2 VENCEU!\n");
                }
                break;
                
            case 't': // Tesoura
                // Tesoura vence Papel ('a')
                if (jogada2 == 'a') {
                    printf("Tesoura vence Papel. JOGADOR 1 VENCEU!\n");
                } 
                // Tesoura perde para Pedra ('p')
                else if (jogada2 == 'p') {
                    printf("Pedra vence Tesoura. JOGADOR 2 VENCEU!\n");
                }
                break;
        }
    }

    return 0; // Encerra o programa com sucesso
}