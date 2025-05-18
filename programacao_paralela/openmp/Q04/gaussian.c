#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int n;
    double **A;
    double *b;
    double *x;
} SistemaLinear;

SistemaLinear criar_sistema_triangular_superior(int n);
SistemaLinear criar_sistema_baguncado(SistemaLinear triangular_sup);
void printar_sistema_com_solucao(SistemaLinear *s);
void liberar_sistema(SistemaLinear *s);

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 0;

    int num_ranks = atoi(argv[1]);
    int n = atoi(argv[2]);

    SistemaLinear triangular_superior = criar_sistema_triangular_superior(n);
    SistemaLinear sist_1 = criar_sistema_baguncado(triangular_superior);

    printar_sistema_com_solucao(&triangular_superior);
    printar_sistema_com_solucao(&sist_1);

    return 0;
}



SistemaLinear criar_sistema_baguncado(SistemaLinear triangular_sup)
{
    SistemaLinear sistema;
    int n = triangular_sup.n;
    sistema.n = triangular_sup.n;
    double *aux = (double *)malloc(sizeof(double) * (n + 1));
    unsigned int seed = time(NULL);

    sistema.A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        sistema.A[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
            sistema.A[i][j] = triangular_sup.A[i][j];
        }
    }

    sistema.b = (double *)malloc(n * sizeof(double));
    sistema.x = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        sistema.b[i] = triangular_sup.b[i];
        sistema.x[i] = 0.0;
    }

    int i, j, linha;
    for (i = 0; i < n; i++)
    {
        aux[i] = sistema.A[0][i];
    }
    aux[n] = sistema.b[0];

    srand(seed);

    for (i = 0; i < n; i++)
    {
        linha = rand() % n;

        for (j = 0; j < n; j++)
            sistema.A[linha][j] += aux[j];
        sistema.b[linha] += aux[n];
    }
    return sistema;
}

void printar_sistema_com_solucao(SistemaLinear *s)
{
    printf("Sistema (A | b):\n");
    for (int i = 0; i < s->n; i++)
    {
        for (int j = 0; j < s->n; j++)
        {
            printf("%6.2f ", s->A[i][j]);
        }
        printf(" | %6.2f  (x[%d] = %.6lf)\n", s->b[i], i, s->x[i]);
    }
}

SistemaLinear criar_sistema_triangular_superior(int n)
{
    SistemaLinear sistema;
    sistema.n = n;

    sistema.A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        sistema.A[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
            sistema.A[i][j] = (j < i) ? 0.0 : (1.0 + (i + j) % 10);
        }
    }

    sistema.b = (double *)malloc(n * sizeof(double));
    sistema.x = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        sistema.b[i] = n + i;
        sistema.x[i] = 0.0;
    }

    return sistema;
}

void liberar_sistema(SistemaLinear *s)
{
    if (s == NULL)
        return;

    for (int i = 0; i < s->n; i++)
    {
        free(s->A[i]);
    }
    free(s->A);

    free(s->b);
    free(s->x);

    s->n = 0;
    s->A = NULL;
    s->b = NULL;
    s->x = NULL;
}