#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int card;
    struct lista *prox;
} Lista;

typedef struct pilha
{
    int totalrestante;
    Lista *topo;
    Lista *base;
} Pilha;

Pilha *cria_pilha()
{
    Pilha *nova = (Pilha *)malloc(sizeof(Pilha));
    nova->topo = NULL;
    nova->totalrestante = 0;
    return nova;
}

void push(Pilha *p, int card)
{
    Lista *new = (Lista *)malloc(sizeof(Pilha));
    if (p->topo == NULL)
    {
        p->base = new;
    }
    new->card = card;
    new->prox = p->topo;
    p->topo = new;
    p->totalrestante++;
}

int pop_and_move_to_base(Pilha *p)
{
    int discartada;
    Lista *l = p->topo;
    discartada = p->topo->card;
    p->base->prox = l->prox;
    p->base = l->prox;
    p->topo = l->prox->prox;
    p->base->prox = NULL;
    free(l);
    p->totalrestante--;
    return discartada;
}

void free_pilha(Pilha *p){
    Lista *l = p->topo;
    Lista *libera;
    while (l->prox != NULL)
    {
        libera = l;
        l = l->prox;
        free(libera);
    }
    free(l);
    free(p);
}

int main()
{
    int cardsmax,i,j;
    while (1)
    {
        scanf("%d", &cardsmax);
        if (cardsmax == 0)
            break;
        Pilha *p = cria_pilha();
        int vet[150];
        for (i = cardsmax; i > 0; i--)
        {
            push(p,i);
        }
        i = 0;
        while (p->totalrestante >= 2)
        {
            vet[i] = pop_and_move_to_base(p);
            i++;
        }
        printf("Discarded cards: ");
        for (j = 0; j < i; j++)
        {
            if (j == 0)
            {
                printf("%d",vet[j]);
            }
            else{
                printf(", %d", vet[j]);
            }
        }
        printf("\nRemaining card: %d\n", p->topo->card);
        free_pilha(p);
    }

    return 0;
}
