#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"
#include "arquivo.h"
#include "util.h"

#define ARQ_LIVROS "data/livros.csv"
#define ARQ_USUARIOS "data/usuarios.csv"
#define ARQ_EMPRESTIMOS "data/emprestimos.csv"

static Livro livros[MAX_LIVROS];
static Usuario usuarios[MAX_USUARIOS];
static Emprestimo emprestimos[MAX_EMPRESTIMOS];
static int n_livros = 0, n_usuarios = 0, n_emprestimos = 0;

static void salvar_tudo(void) {
    salvar_livros(ARQ_LIVROS, livros, n_livros);
    salvar_usuarios(ARQ_USUARIOS, usuarios, n_usuarios);
    salvar_emprestimos(ARQ_EMPRESTIMOS, emprestimos, n_emprestimos);
}

static void menu_cadastrar_livro(void) {
    Livro l;
    l.codigo = ler_inteiro("Codigo: ");
    printf("Titulo: "); ler_linha(l.titulo, TAM_TITULO);
    printf("Autor: "); ler_linha(l.autor, TAM_AUTOR);
    l.ano = ler_inteiro("Ano: ");
    l.quantidade = ler_inteiro("Quantidade disponivel: ");
    if (l.quantidade < 0) { printf("Erro: quantidade invalida.\n"); return; }
    if (livro_cadastrar(livros, &n_livros, l)) { printf("Livro cadastrado!\n"); salvar_tudo(); }
}

static void menu_cadastrar_usuario(void) {
    Usuario u;
    u.matricula = ler_inteiro("Matricula: ");
    printf("Nome: "); ler_linha(u.nome, TAM_NOME);
    printf("Curso: "); ler_linha(u.curso, TAM_CURSO);
    if (usuario_cadastrar(usuarios, &n_usuarios, u)) { printf("Usuario cadastrado!\n"); salvar_tudo(); }
}

static void menu_emprestar(void) {
    int cod = ler_inteiro("Codigo do livro: ");
    int mat = ler_inteiro("Matricula do usuario: ");
    if (emprestimo_registrar(emprestimos, &n_emprestimos, livros, n_livros,
                             usuarios, n_usuarios, cod, mat)) {
        printf("Emprestimo registrado!\n");
        salvar_tudo();
    }
}

static void menu_devolver(void) {
    int cod = ler_inteiro("Codigo do livro: ");
    int mat = ler_inteiro("Matricula do usuario: ");
    if (emprestimo_devolver(emprestimos, n_emprestimos, livros, n_livros, cod, mat)) {
        printf("Devolucao registrada!\n");
        salvar_tudo();
    }
}

static void menu_buscar(void) {
    char termo[100];
    printf("Buscar por: 1) Titulo  2) Autor  3) Nome de usuario  4) Matricula\n");
    int op = ler_inteiro("Opcao: ");
    int achados = 0;
    switch (op) {
        case 1:
        case 2:
            printf("Termo: "); ler_linha(termo, sizeof(termo));
            achados = livro_buscar_texto(livros, n_livros, termo, op == 2);
            break;
        case 3:
            printf("Termo: "); ler_linha(termo, sizeof(termo));
            achados = usuario_buscar_nome(usuarios, n_usuarios, termo);
            break;
        case 4: {
            int m = ler_inteiro("Matricula: ");
            int i = usuario_buscar_matricula(usuarios, n_usuarios, m);
            if (i != -1) {
                printf("%d | %s | %s\n", usuarios[i].matricula, usuarios[i].nome, usuarios[i].curso);
                achados = 1;
            }
            break;
        }
        default:
            printf("Opcao invalida.\n");
            return;
    }
    if (achados == 0) printf("Nenhum resultado encontrado.\n");
}

int main(void) {
    carregar_livros(ARQ_LIVROS, livros, &n_livros);
    carregar_usuarios(ARQ_USUARIOS, usuarios, &n_usuarios);
    carregar_emprestimos(ARQ_EMPRESTIMOS, emprestimos, &n_emprestimos);

    int op;
    do {
        printf("\n===== BIBLIOTECA =====\n"
               "1. Cadastrar livro\n2. Cadastrar usuario\n3. Registrar emprestimo\n"
               "4. Registrar devolucao\n5. Listar livros\n6. Listar usuarios\n"
               "7. Listar emprestimos\n8. Buscar\n0. Sair\n");
        op = ler_inteiro("Opcao: ");
        switch (op) {
            case 1: menu_cadastrar_livro(); break;
            case 2: menu_cadastrar_usuario(); break;
            case 3: menu_emprestar(); break;
            case 4: menu_devolver(); break;
            case 5: livro_listar(livros, n_livros); break;
            case 6: usuario_listar(usuarios, n_usuarios); break;
            case 7: emprestimo_listar(emprestimos, n_emprestimos); break;
            case 8: menu_buscar(); break;
            case 0: salvar_tudo(); printf("Ate logo!\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (op != 0);
    return 0;
}
