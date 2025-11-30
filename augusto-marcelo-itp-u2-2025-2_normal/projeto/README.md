# ♟️ Jogo da Velha (Tic-Tac-Toe) com Inteligência Artificial (Minimax)

Este projeto é a implementação do clássico **Jogo da Velha (Tic-Tac-Toe)** em Linguagem C, apresentando um adversário de computador que joga de forma **perfeita** utilizando o algoritmo **Minimax**.

O algoritmo Minimax simula todos os movimentos possíveis no futuro, garantindo que o computador **nunca perca** (ou ele vence, ou o jogo termina em empate).

---

## ⚙️ Instruções de Compilação e Execução

O projeto é composto por um único arquivo (`main.c`) e foi desenvolvido para ser compilado com o **GCC** (GNU Compiler Collection).

### 1. Pré-requisitos

Certifique-se de ter o compilador **GCC** instalado e configurado em seu sistema (Windows, macOS ou Linux).

### 2. Compilação do Código

Abra o terminal na pasta do projeto e use o seguinte comando para compilar o arquivo `main.c`:

```bash
gcc main.c -o jogodavelha





# 🧠 Jogo da Velha NxN com IA Avançada (Minimax + Alpha-Beta)

Este projeto é uma expansão do clássico **Jogo da Velha (Tic-Tac-Toe)** desenvolvido em Linguagem C. Diferente da versão tradicional, esta implementação permite jogar em tabuleiros de tamanhos variados (**3x3 até 5x5**) e enfrenta uma Inteligência Artificial otimizada com **Poda Alpha-Beta (Alpha-Beta Pruning)**.

A IA ajusta sua estratégia e profundidade de cálculo baseada no tamanho do tabuleiro, garantindo um jogo desafiador sem sacrificar a performance.

---

## 🚀 Novas Funcionalidades

* **Tabuleiro Dinâmico:** O jogador pode escolher o tamanho do tabuleiro no início do jogo (3x3, 4x4 ou 5x5).
* **Poda Alpha-Beta:** Uma otimização crítica do algoritmo Minimax que "corta" caminhos de decisão inúteis, tornando a IA muito mais rápida e eficiente.
* **Profundidade Adaptativa:**
    * **3x3:** A IA calcula até o fim do jogo (invencível).
    * **4x4 e 5x5:** A IA utiliza um limite de profundidade (6 jogadas à frente) e heurísticas para garantir que o computador responda rapidamente, mantendo um nível de dificuldade alto.

---

## ⚙️ Instruções de Compilação e Execução

O projeto continua composto por um único arquivo (`main.c`) e pode ser compilado facilmente com o **GCC**.

### 1. Pré-requisitos

Certifique-se de ter o compilador **GCC** instalado e configurado em seu sistema (Windows, macOS ou Linux).

### 2. Compilação do Código

Abra o terminal na pasta do projeto e use o seguinte comando:

```bash
gcc main.c -o jogodavelha_avancado