#include <stdio.h>
#include "usuario.h"
#include "util.h"

int usuario_cadastrar(Usuario usuarios[], int *total, Usuario novo) {
    if (*total >= MAX_USUARIOS) {
        printf("Erro: limite de usuarios atingido.\n");
        return 0;
    }
    if (usuario_buscar_matricula(usuarios, *total, novo.matricula) != -1) {
        printf("Erro: ja existe usuario com matricula %d.\n", novo.matricula);
        return 0;
    }
    usuarios[*total] = novo;
    (*total)++;
    return 1;
}

void usuario_listar(const Usuario usuarios[], int total) {
    if (total == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    printf("%-10s %-30s %s\n", "Matricula", "Nome", "Curso");
    for (int i = 0; i < total; i++) {
        printf("%-10d %-30s %s\n", usuarios[i].matricula, usuarios[i].nome, usuarios[i].curso);
    }
}

int usuario_buscar_matricula(const Usuario usuarios[], int total, int matricula) {
    for (int i = 0; i < total; i++) {
        if (usuarios[i].matricula == matricula) return i;
    }
    return -1;
}

int usuario_buscar_nome(const Usuario usuarios[], int total, const char *termo) {
    int achados = 0;
    for (int i = 0; i < total; i++) {
        if (contem_ignorando_caso(usuarios[i].nome, termo)) {
            printf("%d | %s | %s\n", usuarios[i].matricula, usuarios[i].nome, usuarios[i].curso);
            achados++;
        }
    }
    return achados;
}
