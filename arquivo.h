#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

/* Formato CSV com ';' como separador. Retornam 1 em sucesso. */
int salvar_livros(const char *caminho, const Livro l[], int total);
int carregar_livros(const char *caminho, Livro l[], int *total);
int salvar_usuarios(const char *caminho, const Usuario u[], int total);
int carregar_usuarios(const char *caminho, Usuario u[], int *total);
int salvar_emprestimos(const char *caminho, const Emprestimo e[], int total);
int carregar_emprestimos(const char *caminho, Emprestimo e[], int *total);

#endif
