# Sistema de Biblioteca em C

1ª entrega: cadastro de livros/usuários, empréstimos e devoluções, busca sequencial e persistência em CSV.

## Compilar e executar
    make
    ./biblioteca

## Estrutura
- `livro.c/.h` – cadastro, listagem e busca de livros
- `usuario.c/.h` – cadastro, listagem e busca de usuários
- `emprestimo.c/.h` – empréstimos e devoluções
- `arquivo.c/.h` – leitura/escrita em `data/*.csv`
- `util.c/.h` – leitura segura de entrada e busca de substring manual
- `main.c` – menu interativo
