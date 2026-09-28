#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void ler_linha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    size_t n = strlen(destino);
    if (n > 0 && destino[n - 1] == '\n') destino[n - 1] = '\0';
}

int ler_inteiro(const char *prompt) {
    char buf[32];
    char *fim;
    while (1) {
        printf("%s", prompt);
        ler_linha(buf, sizeof(buf));
        long v = strtol(buf, &fim, 10);
        if (buf[0] != '\0' && *fim == '\0') return (int)v;
        printf("Entrada invalida. Digite um numero.\n");
    }
}

static char minusculo(char c) {
    return (c >= 'A' && c <= 'Z') ? (char)(c + 32) : c;
}

int contem_ignorando_caso(const char *texto, const char *termo) {
    int nt = (int)strlen(texto);
    int nb = (int)strlen(termo);
    if (nb == 0) return 1;
    for (int i = 0; i + nb <= nt; i++) {
        int j = 0;
        while (j < nb && minusculo(texto[i + j]) == minusculo(termo[j])) j++;
        if (j == nb) return 1;
    }
    return 0;
}
