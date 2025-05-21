#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include <math.h>

typedef struct
{
    int n;
    double **A;
    double *b;
    double *x;
} SistemaLinear;

void algoritmo_linhas_paralelo(SistemaLinear *s, int num_threads);
SistemaLinear criar_sistema_triangular_superior(int n);
SistemaLinear criar_sistema_baguncado(SistemaLinear triangular_sup);
void printar_sistema_com_solucao(SistemaLinear *s);
void liberar_sistema(SistemaLinear *s);
void eliminacao_gaussiana_seq(SistemaLinear *s);
void eliminacao_gaussiana_par(SistemaLinear *s, int num_ranks);
int verificar_solucoes_iguais(SistemaLinear *s1, SistemaLinear *s2);

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 0;

    double start_time, end_time;
    double segs_seq, segs_par;
    int num_ranks = atoi(argv[1]);
    int n = atoi(argv[2]);

    // Cria sistemas
    SistemaLinear triangular_superior = criar_sistema_triangular_superior(n);
    SistemaLinear sist_correto = criar_sistema_baguncado(triangular_superior);
    SistemaLinear sist_seq = criar_sistema_baguncado(triangular_superior);
    SistemaLinear sist_par = criar_sistema_baguncado(triangular_superior);

    algoritmo_linhas_paralelo(&sist_correto, num_ranks);

    start_time = omp_get_wtime();
    eliminacao_gaussiana_seq(&sist_seq);
    end_time = omp_get_wtime();
    segs_seq = end_time - start_time;
    algoritmo_linhas_paralelo(&sist_seq, num_ranks);
    if (n <= 10) {
        printf("\nSistema resolvido sequencialmente:\n");
        printar_sistema_com_solucao(&sist_seq);
    }
    printf("Tempo sequencial: %.5lf\tSolução: %s\n", 
           segs_seq, 
           verificar_solucoes_iguais(&sist_correto, &sist_seq) ? "Correta" : "Errada");

    start_time = omp_get_wtime();
    eliminacao_gaussiana_par(&sist_par, num_ranks);
    end_time = omp_get_wtime();
    segs_par = end_time - start_time;
    algoritmo_linhas_paralelo(&sist_par, num_ranks);
    
    if (n <= 10) {
        printf("\nSistema resolvido paralelamente:\n");
        printar_sistema_com_solucao(&sist_par);
    }
    printf("Tempo paralelo: %.5lf\tSpeedup: %.2fx\tSolução: %s\n", 
           segs_par, 
           segs_seq/segs_par,
           verificar_solucoes_iguais(&sist_correto, &sist_par) ? "Correta" : "Errada");

    liberar_sistema(&triangular_superior);
    liberar_sistema(&sist_correto);
    liberar_sistema(&sist_seq);
    liberar_sistema(&sist_par);

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

void algoritmo_linhas_paralelo(SistemaLinear *s, int num_threads)
{
    int lin, col;
    int n = s->n;
    double sum = 0.0;

#pragma omp parallel num_threads(num_threads) default(none) private(lin) shared(col, s, n, sum)
    {
        for (lin = n - 1; lin >= 0; lin--)
        {
#pragma omp for schedule(runtime) reduction(+ : sum)
            for (col = lin + 1; col < n; col++)
                sum -= s->A[lin][col] * s->x[col];
#pragma omp single
            {
                sum += s->b[lin];
                s->x[lin] = sum / s->A[lin][lin];
                sum = 0.0;
            }
        }
    }
}

void eliminacao_gaussiana_seq(SistemaLinear *s)
{
    int n = s->n;
    double **A = s->A;
    double *B = s->b;
    int i, j, k;
    double max;
    int max_row;

    for (k = 0; k < n - 1; k++)
    {
        max = fabs(A[k][k]);
        max_row = k;

        for (i = k + 1; i < n; i++)
        {
            if (fabs(A[i][k]) > max)
            {
                max_row = i;
                max = fabs(A[i][k]);
            }
        }

        if (max_row != k)
        {
            double *aux_row = A[k];
            A[k] = A[max_row];
            A[max_row] = aux_row;

            double aux_var = B[k];
            B[k] = B[max_row];
            B[max_row] = aux_var;
        }

        for (i = k + 1; i < n; i++)
        {
            double fator = A[i][k] / A[k][k];
            for (j = k; j < n; j++)
            {
                A[i][j] -= fator * A[k][j];
            }
            B[i] -= fator * B[k];
        }
    }
}

void eliminacao_gaussiana_par(SistemaLinear *s, int num_ranks)
{
    int n = s->n;
    double **A = s->A;
    double *B = s->b;
    double max;
    int i, j, k, max_row;

#pragma omp parallel default(none) num_threads(num_ranks) private(i, j, k) shared(n, A, B, max, max_row)
    {
        for (k = 0; k < n - 1; k++)
        {
#pragma omp single
            {
                max = fabs(A[k][k]);
                max_row = k;
            }
            double local_max = max;
            int local_max_row = max_row;

#pragma omp for nowait
            for (i = k + 1; i < n; i++)
            {
                double current = fabs(A[i][k]);
                if (current > local_max)
                {
                    local_max = current;
                    local_max_row = i;
                }
            }

#pragma omp critical
            {
                if (local_max > max)
                {
                    max = local_max;
                    max_row = local_max_row;
                }
            }

#pragma omp single
            {
                if (max_row != k)
                {
                    double *aux_row = A[k];
                    A[k] = A[max_row];
                    A[max_row] = aux_row;

                    double aux_var = B[k];
                    B[k] = B[max_row];
                    B[max_row] = aux_var;
                }
            }
        }
#pragma omp for
        for (i = k + 1; i < n; i++)
        {
            double fator = A[i][k] / A[k][k];
            for (j = k; j < n; j++)
            {
                A[i][j] -= fator * A[k][j];
            }
            B[i] -= fator * B[k];
        }
    }
}

int verificar_solucoes_iguais(SistemaLinear *s1, SistemaLinear *s2)
{
    if (s1->n != s2->n)
    {
        return 0;
    }

    const double tol = 1e-10;

    for (int i = 0; i < s1->n; i++)
    {
        if (fabs(s1->x[i] - s2->x[i]) > tol)
        {
            return 0;
        }
    }

    return 1;
}