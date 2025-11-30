#include <stdio.h>

// Definicao da Taxa Fixa: 24 horas * 60 minutos/hora
#define MINUTOS_NO_DIA (24 * 60)

/**
 * Funcao auxiliar para exibir o horario formatado.
 * Ela trata a normalizacao dos minutos (se >= 60) e das horas (se >= 24).
 * * @param h A hora (pode ser maior que 23).
 * @param m O minuto (pode ser maior que 59).
 * @param formato 0 para 24h, 1 para 12h.
 */
void exibir_horario(int h, int m, int formato) {
    
    // --- 1. Normalização do Tempo (Garantir que o tempo esteja dentro de um dia) ---
    
    // 1.1 Normalizar Minutos e transportar para Horas
    // O total de minutos, incluindo o excedente de horas
    int total_minutos = (h * 60) + m;
    
    // Total de minutos normalizado para um dia (0 a 1439)
    total_minutos %= MINUTOS_NO_DIA; 
    
    // Recalcular horas e minutos
    int hh = total_minutos / 60;
    int mm = total_minutos % 60;

    // --- 2. Formatacao da Saida ---
    
    if (formato == 0) {
        // Formato 24h: hh:mm
        printf("%02d:%02d\n", hh, mm);
        
    } else if (formato == 1) {
        // Formato 12h: hh:mm AA
        
        char *am_pm;
        int h12;
        
        // Determinar AM/PM
        if (hh >= 12) {
            am_pm = "PM";
        } else {
            am_pm = "AM";
        }
        
        // Converter hora 24h para 12h (12, 1, 2, ..., 11)
        if (hh == 0 || hh == 12) {
            // 00:xx (meia-noite) e 12:xx (meio-dia) sao 12 no formato 12h
            h12 = 12; 
        } else {
            // Horas normais: 1-11
            h12 = hh % 12;
        }
        
        // Exibir
        printf("%02d:%02d %s\n", h12, mm, am_pm);
    }
}


// --- FUNÇÃO PRINCIPAL ---
int main() {
    // Variaveis de entrada
    int hora_inicio, minuto_inicio;
    int formato_saida;

    // Definicao dos acréscimos em minutos para cada ronda
    // 1h = 60m
    // 2h10m = 130m
    // 4h40m = 280m
    // 12h5m = 725m
    int acrescimos[] = {
        60,   // 1h
        130,  // 2h10m
        280,  // 4h40m
        725   // 12h5m
    };
    int num_rondas = sizeof(acrescimos) / sizeof(acrescimos[0]);
    
    // --- 1. Leitura da Entrada ---

    printf("--- Agendamento de Rondas ---\n");
    printf("Digite a hora de inicio (hh mm - formato 24h): ");
    if (scanf("%d %d", &hora_inicio, &minuto_inicio) != 2) return 1;

    printf("Digite o formato de saida (0 para 24h, 1 para 12h): ");
    if (scanf("%d", &formato_saida) != 1) return 1;

    // Verifica se o formato e valido (embora o problema aceite qualquer outro valor, vamos ser rigorosos)
    if (formato_saida != 0 && formato_saida != 1) {
        printf("ERRO: Formato de saida invalido. Use 0 ou 1.\n");
        return 1;
    }
    
    printf("\n--- Horarios das Rondas ---\n");

    // --- 2. Processamento das Rondas ---
    
    // 2.1. Ronda Inicial (para fins de demonstracao)
    printf("Horario de inicio: ");
    exibir_horario(hora_inicio, minuto_inicio, formato_saida);

    // 2.2. Calculo e exibicao das rondas com acréscimo
    for (int i = 0; i < num_rondas; i++) {
        
        // Calcula o novo total de minutos
        int minutos_adicionais = acrescimos[i];
        
        // Para simplificar, calculamos o total de minutos desde o inicio do dia
        int total_minutos_inicial = (hora_inicio * 60) + minuto_inicio;
        int total_minutos_ronda = total_minutos_inicial + minutos_adicionais;
        
        // Passamos o total de minutos para a funcao exibir_horario, 
        // que ira normalizar a hora (hh) e os minutos (mm) para nos.
        
        printf("Apos +%d min: ", minutos_adicionais);
        exibir_horario(0, total_minutos_ronda, formato_saida);
    }

    return 0;
}