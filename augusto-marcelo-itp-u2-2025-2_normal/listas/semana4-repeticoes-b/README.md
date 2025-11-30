# 💻 Instruções de Compilação e Execução (Linguagem C)

Este repositório contém os seguintes exercícios em Linguagem C, focados em estruturas condicionais, *switch/case* e manipulação de variáveis:

* **`questao1.c`**: Análise de código - Loop aninhado 1.
* **`questao2.c`**: Análise de código - Loop aninhado 2.
* **`questao3.c`**: Análise de código - Loop aninhado 3.
* **`questao4.c`**: Análise de código - Loop aninhado 4.
* **`questao5.c`**: Padrão numérico triangular
* **`questao6.c`**: Trios pitagóricos
* **`questao7.c`**: Números primos em intervalo
* **`questao8.c`**: Compra de placas de alumínio
* **`questao9.c`**: Modificação da questão 8
* **`questao10.c`**: Pacote promocional
* **`questao11.c`**: Problema das 4 rainhas

Os códigos devem ser compilados utilizando o compilador **GCC** (GNU Compiler Collection).

## Pré-requisitos

Certifique-se de que o **GCC** (ou MinGW no Windows) esteja instalado e configurado em seu sistema.

## Compilação e Execução Manual (Terminal)

1.  **Navegue até o diretório** onde os arquivos estão localizados.

2.  **Compile o arquivo desejado** usando o GCC. O *flag* `-o` define o nome do arquivo executável de saída.

    ```bash
    # Sintaxe geral
    gcc nome_do_arquivo.c -o nome_do_executavel
    
    # Exemplo: Compilando o problema5.c
    gcc problema5.c -o desconto
    ```

3.  **Atenção: Para códigos que usam funções da biblioteca matemática** (como `sqrt()`, `pow()`, ou `fabs()` nos arquivos `problema1.c`, `problema7.c` e `problema8.c`), você **DEVE** incluir o *flag* `-lm` (linkar biblioteca matemática):

    ```bash
    # Exemplo: Compilando o problema7.c
    gcc problema7.c -o bhaskara -lm
    ```

4.  **Execute o programa** gerado a partir do mesmo terminal:

    ```bash
    # Em Linux/macOS
    ./nome_do_executavel
    
    # Exemplo (Linux/macOS)
    ./bhaskara
    
    # Em Windows (via Prompt de Comando ou PowerShell)
    nome_do_executavel.exe
    
    # Exemplo (Windows)
    bhaskara.exe
    ```

## Compilação via VS Code Tasks

Se você estiver utilizando o **Visual Studio Code** e suas *Tasks* de *build* configuradas, utilize o atalho:

1.  Abra o arquivo `.c` desejado.
2.  Pressione **`Ctrl + Shift + B`** (ou `Cmd + Shift + B` no macOS).
3.  Selecione a *Task* padrão do GCC.
4.  Lembre-se que, para os arquivos que precisam do `-lm`, talvez seja necessário configurar uma *Task* específica para incluir esse *flag* ou compilar manualmente via terminal (passo 3 acima).