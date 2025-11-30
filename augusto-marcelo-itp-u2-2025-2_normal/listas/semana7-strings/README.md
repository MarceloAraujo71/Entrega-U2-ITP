# 💻 Instruções de Compilação e Execução (Linguagem C)

Este repositório contém os seguintes exercícios em Linguagem C, envolvendo manipulação de strings, vetores e laços de repetição:

* **`problema1.c`**: Campo minado 1D.
* **`problema2.c`**: Detecção de placas.
* **`problema3.c`**: OpenMeet.

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