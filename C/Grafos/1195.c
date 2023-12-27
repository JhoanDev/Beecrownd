#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
} No;

void adicionar_no(No **arvore, int d)
{
    if (*arvore == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = d;
        novo->dir = novo->esq = NULL;
        *arvore = novo;
    }
    else if ((*arvore)->dado < d)
    {
        adicionar_no(&((*arvore)->dir), d);
    }
    else if ((*arvore)->dado > d)
    {
        adicionar_no(&((*arvore)->esq), d);
    }
}

void imprimir_preordem(No *arvore)
{
    if (arvore != NULL)
    {
        printf(" %d", arvore->dado);
        imprimir_preordem(arvore->esq);
        imprimir_preordem(arvore->dir);
    }
}

void imprimir_inordem(No *arvore)
{
    if (arvore != NULL)
    {
        imprimir_inordem(arvore->esq);
        printf(" %d", arvore->dado);
        imprimir_inordem(arvore->dir);
    }
}

void imprimir_posordem(No *arvore)
{
    if (arvore != NULL)
    {
        imprimir_posordem(arvore->esq);
        imprimir_posordem(arvore->dir);
        printf(" %d", arvore->dado);
    }
}

void liberar_arvore(No *arvore)
{
    if (arvore != NULL)
    {
        liberar_arvore(arvore->esq);
        liberar_arvore(arvore->dir);
        free(arvore);
    }
}

int main()
{
    int casos, i, n, j, dado;
    scanf("%d", &casos);
    for (i = 0; i < casos; i++)
    {
        scanf("%d", &n);
        No *arvore = NULL;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dado);
            adicionar_no(&arvore, dado);
        }
        printf("Case %d:", i + 1);
        printf("\nPre.:");
        imprimir_preordem(arvore);
        printf("\nIn..:");
        imprimir_inordem(arvore);
        printf("\nPost:");
        imprimir_posordem(arvore);
        printf("\n\n");
        liberar_arvore(arvore);
    }
    return 0;
}
