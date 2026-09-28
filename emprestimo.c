#include <stdio.h>
#include "emprestimo.h"

int emprestimo_registrar(Emprestimo emps[], int *total_emps,
                         Livro livros[], int total_livros,
                         const Usuario usuarios[], int total_usuarios,
                         int codigo_livro, int matricula) {
    int il = livro_buscar_codigo(livros, total_livros, codigo_livro);
    if (il == -1) {
        printf("Erro: livro nao encontrado.\n");
        return 0;
    }
    if (usuario_buscar_matricula(usuarios, total_usuarios, matricula) == -1) {
        printf("Erro: usuario nao encontrado.\n");
        return 0;
    }
    if (livros[il].quantidade <= 0) {
        printf("Erro: quantidade insuficiente (nenhum exemplar disponivel).\n");
        return 0;
    }
    if (*total_emps >= MAX_EMPRESTIMOS) {
        printf("Erro: limite de emprestimos atingido.\n");
        return 0;
    }
    emps[*total_emps].codigo_livro = codigo_livro;
    emps[*total_emps].matricula = matricula;
    emps[*total_emps].devolvido = 0;
    (*total_emps)++;
    livros[il].quantidade--;
    return 1;
}

int emprestimo_devolver(Emprestimo emps[], int total_emps,
                        Livro livros[], int total_livros,
                        int codigo_livro, int matricula) {
    for (int i = 0; i < total_emps; i++) {
        if (emps[i].codigo_livro == codigo_livro && emps[i].matricula == matricula
            && !emps[i].devolvido) {
            emps[i].devolvido = 1;
            int il = livro_buscar_codigo(livros, total_livros, codigo_livro);
            if (il != -1) livros[il].quantidade++;
            return 1;
        }
    }
    printf("Erro: emprestimo em aberto nao encontrado.\n");
    return 0;
}

void emprestimo_listar(const Emprestimo emps[], int total) {
    if (total == 0) {
        printf("Nenhum emprestimo registrado.\n");
        return;
    }
    printf("%-8s %-10s %s\n", "Livro", "Matricula", "Status");
    for (int i = 0; i < total; i++) {
        printf("%-8d %-10d %s\n", emps[i].codigo_livro, emps[i].matricula,
               emps[i].devolvido ? "Devolvido" : "Em aberto");
    }
}
