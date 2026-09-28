#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 200
#define TAM_NOME 80
#define TAM_CURSO 60

typedef struct {
    int matricula;
    char nome[TAM_NOME];
    char curso[TAM_CURSO];
} Usuario;

int usuario_cadastrar(Usuario usuarios[], int *total, Usuario novo);
void usuario_listar(const Usuario usuarios[], int total);
int usuario_buscar_matricula(const Usuario usuarios[], int total, int matricula);
int usuario_buscar_nome(const Usuario usuarios[], int total, const char *termo);

#endif
