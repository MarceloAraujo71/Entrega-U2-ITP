#include <stdio.h>
#include <math.h> // Necessário para a função sqrt() e pow()

// Define o limite máximo para o maior número (c)
#define LIMITE_MAXIMO 1000

int main() {
    int a, b;
    double c_quadrado, c_flutuante;
    int c_inteiro;
    
    // Variável para contar quantos trios foram encontrados
    int contador_trios = 0;

    printf("--- Trios Pitagoricos onde o maior numero (c) e menor que %d ---\n", LIMITE_MAXIMO);
    
    // O loop externo percorre o lado 'a'
    // 'a' deve ser menor que o LIMITE_MAXIMO
    for (a = 1; a < LIMITE_MAXIMO; a++) {
        
        // O loop interno percorre o lado 'b'
        // Podemos otimizar: 'b' so precisa comecar em 'a + 1'
        // para evitar repetir (3, 4, 5) e (4, 3, 5)
        for (b = a + 1; b < LIMITE_MAXIMO; b++) {
            
            // 1. Calcula c^2 = a^2 + b^2
            // Usamos pow() para garantir a precisao do double
            c_quadrado = pow(a, 2) + pow(b, 2);
            
            // 2. Calcula a raiz quadrada (c)
            c_flutuante = sqrt(c_quadrado);
            
            // 3. Converte para inteiro para verificacao
            c_inteiro = (int)c_flutuante;
            
            // 4. Checa a Condição
            // Condicao A: c deve ser menor que o limite
            // Condicao B: c deve ser um numero inteiro (quadrado perfeito)
            if (c_inteiro < LIMITE_MAXIMO && (c_flutuante - c_inteiro) < 0.000001) {
                
                // Ultima checagem (necessaria apos o casting e comparacao com epsilon)
                // Se c_inteiro * c_inteiro for igual a c_quadrado, e um trio valido
                if ((int)c_quadrado == (c_inteiro * c_inteiro)) {
                    printf("(%d, %d, %d)\n", a, b, c_inteiro);
                    contador_trios++;
                }
            }
        }
    }

    printf("\nTotal de trios encontrados: %d\n", contador_trios);

    return 0;
}