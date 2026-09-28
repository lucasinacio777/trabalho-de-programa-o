CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o livro.o usuario.o emprestimo.o arquivo.o util.o

biblioteca: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o biblioteca
