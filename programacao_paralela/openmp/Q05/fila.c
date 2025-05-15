#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no
{
    char *linha;
    No *prox;
};

struct fila
{
    No *inicio;
    No *fim;
    int tam;
};

Fila *cria_fila()
{
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    if (!nova)
        return NULL;
    nova->fim = NULL;
    nova->inicio = NULL;
    nova->tam = 0;
    return nova;
}

void fila_insere(Fila *f, char *linha)
{
    No *novo_no = (No *)malloc(sizeof(No));

    if (!novo_no)
        exit(1);

    novo_no->linha = linha;
    novo_no->prox = NULL;

    if (f->tam == 0)
        f->inicio = novo_no;
    else
        f->fim->prox = novo_no;

    f->fim = novo_no;
    f->tam++;
}

char *fila_retira(Fila *f)
{
    if (f->tam == 0)
        return NULL;

    No *aux = f->inicio;
    char *line = aux->linha;

    f->inicio = aux->prox;
    if (!f->inicio)
        f->fim = NULL;

    f->tam--;
    free(aux);
    return line;
}

void fila_libera(Fila *f)
{
    while (f->tam > 0)
    {
        char *linha = fila_retira(f);
        free(linha);
    }
    free(f);
}

int fila_vazia(Fila *f)
{
    if (f->tam)
        return 0;
    return 1;
}