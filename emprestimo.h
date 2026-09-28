#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "livro.h"
#include "usuario.h"

#define MAX_EMPRESTIMOS 500

typedef struct {
    int codigo_livro;
    int matricula;
    int devolvido; /* 0 = em aberto, 1 = devolvido */
} Emprestimo;

int emprestimo_registrar(Emprestimo emps[], int *total_emps,
                         Livro livros[], int total_livros,
                         const Usuario usuarios[], int total_usuarios,
                         int codigo_livro, int matricula);
int emprestimo_devolver(Emprestimo emps[], int total_emps,
                        Livro livros[], int total_livros,
                        int codigo_livro, int matricula);
void emprestimo_listar(const Emprestimo emps[], int total);

#endif
