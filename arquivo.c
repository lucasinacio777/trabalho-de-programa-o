#include <stdio.h>
#include <string.h>
#include "arquivo.h"

int salvar_livros(const char *caminho, const Livro l[], int total) {
    FILE *f = fopen(caminho, "w");
    if (!f) { printf("Erro ao abrir %s para escrita.\n", caminho); return 0; }
    for (int i = 0; i < total; i++)
        fprintf(f, "%d;%s;%s;%d;%d\n", l[i].codigo, l[i].titulo, l[i].autor, l[i].ano, l[i].quantidade);
    fclose(f);
    return 1;
}

int carregar_livros(const char *caminho, Livro l[], int *total) {
    FILE *f = fopen(caminho, "r");
    *total = 0;
    if (!f) return 0; /* primeira execução: arquivo ainda não existe */
    char linha[300];
    while (*total < MAX_LIVROS && fgets(linha, sizeof(linha), f)) {
        Livro x;
        if (sscanf(linha, "%d;%99[^;];%79[^;];%d;%d", &x.codigo, x.titulo, x.autor, &x.ano, &x.quantidade) == 5)
            l[(*total)++] = x;
    }
    fclose(f);
    return 1;
}

int salvar_usuarios(const char *caminho, const Usuario u[], int total) {
    FILE *f = fopen(caminho, "w");
    if (!f) { printf("Erro ao abrir %s para escrita.\n", caminho); return 0; }
    for (int i = 0; i < total; i++)
        fprintf(f, "%d;%s;%s\n", u[i].matricula, u[i].nome, u[i].curso);
    fclose(f);
    return 1;
}

int carregar_usuarios(const char *caminho, Usuario u[], int *total) {
    FILE *f = fopen(caminho, "r");
    *total = 0;
    if (!f) return 0;
    char linha[300];
    while (*total < MAX_USUARIOS && fgets(linha, sizeof(linha), f)) {
        Usuario x;
        if (sscanf(linha, "%d;%79[^;];%59[^\n]", &x.matricula, x.nome, x.curso) == 3)
            u[(*total)++] = x;
    }
    fclose(f);
    return 1;
}

int salvar_emprestimos(const char *caminho, const Emprestimo e[], int total) {
    FILE *f = fopen(caminho, "w");
    if (!f) { printf("Erro ao abrir %s para escrita.\n", caminho); return 0; }
    for (int i = 0; i < total; i++)
        fprintf(f, "%d;%d;%d\n", e[i].codigo_livro, e[i].matricula, e[i].devolvido);
    fclose(f);
    return 1;
}

int carregar_emprestimos(const char *caminho, Emprestimo e[], int *total) {
    FILE *f = fopen(caminho, "r");
    *total = 0;
    if (!f) return 0;
    char linha[100];
    while (*total < MAX_EMPRESTIMOS && fgets(linha, sizeof(linha), f)) {
        Emprestimo x;
        if (sscanf(linha, "%d;%d;%d", &x.codigo_livro, &x.matricula, &x.devolvido) == 3)
            e[(*total)++] = x;
    }
    fclose(f);
    return 1;
}
