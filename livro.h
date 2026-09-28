#ifndef LIVRO_H
#define LIVRO_H

#define MAX_LIVROS 200
#define TAM_TITULO 100
#define TAM_AUTOR 80

typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int quantidade;
} Livro;

/* Retorna 1 em sucesso, 0 em falha (cheio ou código duplicado). */
int livro_cadastrar(Livro livros[], int *total, Livro novo);
void livro_listar(const Livro livros[], int total);
/* Busca sequencial manual: retorna índice ou -1. */
int livro_buscar_codigo(const Livro livros[], int total, int codigo);
/* Imprime todos os livros cujo título/autor contém o termo. Retorna qtd. */
int livro_buscar_texto(const Livro livros[], int total, const char *termo, int por_autor);

#endif
