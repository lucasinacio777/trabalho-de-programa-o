#ifndef UTIL_H
#define UTIL_H

/* Lê uma linha do stdin, remove o '\n'. */
void ler_linha(char *destino, int tamanho);
/* Lê um inteiro com validação (repete até ser válido). */
int ler_inteiro(const char *prompt);
/* Busca de substring manual, ignorando maiúsculas/minúsculas. */
int contem_ignorando_caso(const char *texto, const char *termo);

#endif
