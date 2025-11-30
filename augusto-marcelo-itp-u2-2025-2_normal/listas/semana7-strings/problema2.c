#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[15]; // Tamanho seguro para ler a entrada
    
    // Lê a placa (assumindo sem espaços, conforme enunciado)
    scanf("%s", placa);
    
    int len = strlen(placa);
    int eh_brasileiro = 1; // Flag assumindo verdadeiro inicialmente
    int eh_mercosul = 1;   // Flag assumindo verdadeiro inicialmente

    // --- Verificação Padrão Brasileiro (LLL-AAAA) ---
    // Deve ter tamanho 8
    if (len != 8) {
        eh_brasileiro = 0;
    } else {
        // Verifica LLL (0,1,2)
        if (!isupper(placa[0]) || !isupper(placa[1]) || !isupper(placa[2])) eh_brasileiro = 0;
        // Verifica hífen (3)
        if (placa[3] != '-') eh_brasileiro = 0;
        // Verifica AAAA (4,5,6,7)
        if (!isdigit(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6]) || !isdigit(placa[7])) eh_brasileiro = 0;
    }

    // --- Verificação Padrão Mercosul (LLLALAA) ---
    // Deve ter tamanho 7
    if (len != 7) {
        eh_mercosul = 0;
    } else {
        // Verifica LLL (0,1,2)
        if (!isupper(placa[0]) || !isupper(placa[1]) || !isupper(placa[2])) eh_mercosul = 0;
        // Verifica A (3) - Primeiro número
        if (!isdigit(placa[3])) eh_mercosul = 0;
        // Verifica L (4) - Letra intermediária
        if (!isupper(placa[4])) eh_mercosul = 0;
        // Verifica AA (5,6) - Números finais
        if (!isdigit(placa[5]) || !isdigit(placa[6])) eh_mercosul = 0;
    }

    // --- Saída do Resultado ---
    if (eh_brasileiro) {
        printf("brasileiro\n");
    } else if (eh_mercosul) {
        printf("mercosul\n");
    } else {
        printf("inválido\n");
    }

    return 0;
}