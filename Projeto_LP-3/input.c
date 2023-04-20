#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)
#define VALOR_INVALIDO  "O valor inserido é inválido."
#define NUMERO_INVALIDO "O número inserido é inválido."


void cleanBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * Esta função permite obter um valor do tipo inteiro
 * @param minValor
 * @param maxValor
 * @param msg
 * @return valor
 */
int obterInteiro(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanBuffer();
        printf(msg);
    }
    cleanBuffer();
    return valor;
}

/**
 * Esta função permite obter um valor do tipo float
 * @param minValor
 * @param maxValor
 * @param msg
 * @return valor
 */
float obterFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf(msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanBuffer();
        printf(msg);
    }
    cleanBuffer();
    return valor;
}

/**
 * Esta função permite obter um valor do tipo long
 * @param minValor
 * @param maxValor
 * @param msg
 * @return valor
 */
long obterLong(long minValor, long maxValor, char *msg) {
    long valor;
    printf(msg);
    while (scanf("%ld", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(NUMERO_INVALIDO);
        cleanBuffer();
        printf(msg);
    }
    cleanBuffer();
    return valor;
}

/**
 * Esta função permite obter um caracter
 * @param minValor
 * @param maxValor
 * @param msg
 * @return valor
 */
char obterChar(char *msg) {
    char valor;
    printf(msg);
    valor = getchar();
    cleanBuffer();
    return valor;
}

/**
 * Esta função permite ler uma string
 * @param minValor
 * @param maxValor
 * @param msg
 */
void lerString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanBuffer();
        }
    }
}