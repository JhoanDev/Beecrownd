#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int value;
    struct no *prox;
} No;

No **create_table(int size)
{
    No **new_hash_table = (No **)malloc(size * sizeof(No *));
    int i;
    for (i = 0; i < size; i++)
    {
        new_hash_table[i] = (No *)malloc(sizeof(No));
        new_hash_table[i]->prox = NULL;
        new_hash_table[i]->value = -1;
    }
    return new_hash_table;
}

void insert_value(No **hash_table, int value, int size)
{
    int key = value % size;
    No *aux = hash_table[key]->prox;
    No *ant = hash_table[key];

    if (hash_table[key]->value == -1)
    {
        hash_table[key]->value = value;
    }
    else
    {
        while (aux != NULL)
        {
            ant = aux;
            aux = aux->prox;
        }
        No *new = (No *)malloc(sizeof(No));
        new->prox = NULL;
        new->value = value;
        ant->prox = new;
    }
}

void print_table(No **hash_table, int size)
{
    int i;
    No *aux = NULL;
    for (i = 0; i < size; i++)
    {
        printf("%d -> ", i);
        if (hash_table[i]->value != -1)
        {
            printf("%d -> ", hash_table[i]->value);
            aux = hash_table[i]->prox;
            while (aux != NULL)
            {
                printf("%d -> ", aux->value);
                aux = aux->prox;
            }
        }
        printf("\\");
        printf("\n");
    }
}

void free_table(No **hash_table, int size)
{
    No *aux;
    No *ant;
    int i;
    for (i = 0; i < size; i++)
    {
        aux = hash_table[i];
        while (aux != NULL)
        {
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
    }
    free(hash_table);
}

int main()
{
    int tests, i, j, table_size, qnt_numbers, value;
    No **hash_table;
    scanf("%d", &tests);
    for (i = 0; i < tests; i++)
    {
        scanf("%d %d", &table_size, &qnt_numbers);
        hash_table = create_table(table_size);
        for (j = 0; j < qnt_numbers; j++)
        {
            scanf("%d", &value);
            insert_value(hash_table, value, table_size);
        }
        print_table(hash_table, table_size);
        free_table(hash_table, table_size);
        if (i != tests - 1)
        {
            printf("\n");
        }
    }
    return 0;
}