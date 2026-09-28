#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "util.h"

int livro_cadastrar(Livro livros[], int *total, Livro novo) {
    if (*total >= MAX_LIVROS) {
        printf("Erro: limite de livros atingido.\n");
        return 0;
    }
    if (livro_buscar_codigo(livros, *total, novo.codigo) != -1) {
        printf("Erro: ja existe livro com codigo %d.\n", novo.codigo);
        return 0;
    }
    livros[*total] = novo;
    (*total)++;
    return 1;
}

void livro_listar(const Livro livros[], int total) {
    if (total == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("%-6s %-30s %-20s %-5s %s\n", "Cod", "Titulo", "Autor", "Ano", "Disp.");
    for (int i = 0; i < total; i++) {
        printf("%-6d %-30s %-20s %-5d %d\n", livros[i].codigo, livros[i].titulo,
               livros[i].autor, livros[i].ano, livros[i].quantidade);
    }
}

int livro_buscar_codigo(const Livro livros[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (livros[i].codigo == codigo) return i;
    }
    return -1;
}

int livro_buscar_texto(const Livro livros[], int total, const char *termo, int por_autor) {
    int achados = 0;
    for (int i = 0; i < total; i++) {
        const char *campo = por_autor ? livros[i].autor : livros[i].titulo;
        if (contem_ignorando_caso(campo, termo)) {
            printf("%d | %s | %s | %d | disp: %d\n", livros[i].codigo, livros[i].titulo,
                   livros[i].autor, livros[i].ano, livros[i].quantidade);
            achados++;
        }
    }
    return achados;
}
