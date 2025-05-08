#ifndef FILA_H
#define FILA_H

typedef struct no No;
typedef struct fila Fila;

Fila *cria_fila();
void fila_insere(Fila *f, char *linha);
char *fila_retira(Fila *f);
void fila_libera(Fila *f);

#endif