# Introdução a Técnicas de Programação - Unidade 1

**Aluno**: Marcelo Augusto Gomes Bastos de Araújo
**Matrícula**: 20250033007
**Período**: 2025.2

## 📁 Estrutura do Projeto

- `projeto/`: Projeto principal da unidade 1 + Exapansão desse projeto no arquivo **main2.c**
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto 1: Jogo da Velha com IA (Minimax)

**Descrição**: O projeto simula um jogo da velha de 3x3 onde um jogador humano ('X') compete contra o computador ('O'). O cerne do projeto reside na implementação do algoritmo Minimax, que garante que a IA sempre fará o melhor movimento possível, resultando em:

Vitória: Se houver um caminho garantido para vencer.

Empate: Se a vitória não for possível, garantindo no mínimo o empate.

## 🧠 Projeto 2 (Expansão do projeto 1): Jogo da Velha NxN com IA Avançada (Minimax + Alpha-Beta)

**Descrição**: Este projeto é uma expansão do clássico **Jogo da Velha (Tic-Tac-Toe)** desenvolvido em Linguagem C. Diferente da versão tradicional, esta implementação permite jogar em tabuleiros de tamanhos variados (**3x3 até 5x5**) e enfrenta uma Inteligência Artificial otimizada com **Poda Alpha-Beta (Alpha-Beta Pruning)**.

Vitória: Se houver um caminho garantido para vencer.

Empate: Se a vitória não for possível, garantindo no mínimo o empate.

**Repositório**: https://github.com/MarceloAraujo71/Entrega-U1-ITP.git

### Funcionalidades Implementadas:
- 1. Inicialização e Interface
inicializar_tabuleiro(): Prepara o tabuleiro 3x3, preenchendo todas as posições com espaços vazios (' ').

exibir_tabuleiro(): Apresenta o estado atual do tabuleiro de forma clara no console, usando caracteres de separação (|, -).

Entrada do Usuário: Gerencia a leitura das jogadas do jogador humano ('X'), validando se as coordenadas (Linha e Coluna) estão dentro dos limites (1 a 3) e se a posição escolhida está vazia.

2. Lógica do Jogo
tem_movimentos(): Verifica se ainda há espaços vazios disponíveis no tabuleiro. Usada para determinar a possibilidade de empate.

checar_vitoria(): Examina todas as linhas, colunas e diagonais do tabuleiro para determinar se algum jogador atingiu três em linha.

Retorna 10 se a IA ('O') venceu.

Retorna -10 se o Jogador ('X') venceu.

Retorna 0 se não há vencedor.

3. Inteligência Artificial (Algoritmo Minimax)
minimax(profundidade, maximizando_jogador): Esta é a função central que implementa o algoritmo Minimax de forma recursiva e com backtracking.

Simulação Completa: Avalia todas as possíveis jogadas futuras a partir do estado atual do jogo.

Maximização: Quando é a vez da IA, busca o movimento que maximize sua pontuação (INT_MIN).

Minimização: Quando é a vez do Jogador, assume que o humano fará o movimento que minimize a pontuação da IA (INT_MAX).

Otimização: Ajusta a pontuação final pela profundidade da jogada, incentivando vitórias mais rápidas e adiando derrotas.

encontrar_melhor_movimento(): Itera sobre todos os espaços vazios e usa a função minimax para calcular a pontuação de cada movimento possível. Seleciona e retorna o movimento que resulta no melhor valor Minimax para a IA.

### Conceitos da U1 Aplicados:
- Estruturas condicionais: checar_vitoria(); minimax(); main(); encontrar_melhor_movimento();
- Estruturas de repetição: inicializar_tabuleiro(); exibir_tabuleiro(); tem_movimentos(); checar_vitoria(); minimax(); encontrar_melhor_movimento();
- Vetores: char tabuleiro[3][3];
- Funções: inicializar_tabuleiro(); exibir_tabuleiro(); tem_movimentos(); checar_vitoria(); minimax(); encontrar_melhor_movimento();

## 📚 Listas de Exercícios

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-11: Implementações

### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial

### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings:
- ✅ Problema 1: Campo minado 1D
- ✅ Problema 2: Detecção de placas
- ✅ Problema 3: OpenMeet

### Semana 8 - Repetições Aninhadas:
- ✅ Problema 1: Estou com sorte (ou não)
- ✅ Problema 2: Os dias mais chuvosos
- ✅ Problema 3: Esse sim é piloto

### Semana 9 - Matrizes:
- ✅ Problema 1: Campo Agrícola
- ✅ Problema 2: Sugestão de amigos
- ✅ Problema 3: Campeonato de empates
- ✅ Problema 4: Uma pechincha!

### Semana 10 - Alocação e Ponteiros:
- ✅ Problema 1: Soma de Vetores
- ✅ Problema 2: Ocorrências no vetor
- ✅ Problema 3: Sopa de letrinhas

## 🎯 Principais Aprendizados

Lógica de Controle de Fluxo: Domínio de como o programa toma decisões (condicionais if/else, switch) e como executa tarefas repetitivas ou iterativas (laços for, while) para resolver problemas matemáticos e lógicos.

Manipulação de Estruturas de Dados: Capacidade de armazenar e organizar conjuntos de dados, seja em listas simples (vetores), tabelas (matrizes) ou textos (strings), permitindo a criação de programas mais complexos como jogos de tabuleiro e análise de dados.

Modularização de Código: Aprendizado sobre como dividir problemas grandes em partes menores e reutilizáveis através de funções, tornando o código mais limpo e organizado.

Gerenciamento de Memória: Compreensão de como o computador acessa dados diretamente via ponteiros e como solicitar memória extra durante a execução (alocação dinâmica), essencial para programas flexíveis.

Integração de Algoritmos: Habilidade de combinar todos os conceitos anteriores (estruturas, funções e lógica) para implementar algoritmos completos, como sistemas de busca, ordenação e inteligência artificial.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão 8.1.0
- **Editor**: Visual Studio Code (VS Code)