#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include <math.h>

const double eps = 1e-1;

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
    srand(time(NULL));

    // Cria sistemas
    SistemaLinear sist_correto = criar_sistema_triangular_superior(n);
    SistemaLinear sist_seq = criar_sistema_baguncado(sist_correto);
    SistemaLinear sist_par = criar_sistema_baguncado(sist_correto);

    start_time = omp_get_wtime();
    eliminacao_gaussiana_seq(&sist_seq);
    end_time = omp_get_wtime();
    segs_seq = end_time - start_time;
    if (n <= 10)
    {
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

    if (n <= 10)
    {
        printf("\nSistema resolvido paralelamente:\n");
        printar_sistema_com_solucao(&sist_par);
    }
    printf("Tempo paralelo: %.5lf\tSpeedup: %.2fx\tSolução: %s\n",
           segs_par,
           segs_seq / segs_par,
           verificar_solucoes_iguais(&sist_correto, &sist_par) ? "Correta" : "Errada");

    liberar_sistema(&sist_correto);
    liberar_sistema(&sist_seq);
    liberar_sistema(&sist_par);

    return 0;
}
SistemaLinear criar_sistema_baguncado(SistemaLinear triangular_sup)
{
    SistemaLinear sistema;
    int n = triangular_sup.n;
    sistema.n = n;

    // Aloca e copia a matriz A
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
    for (int i = 0; i < n; i++)
    {
        sistema.b[i] = triangular_sup.b[i];
    }

    sistema.x = (double *)malloc(n * sizeof(double));
    memset(sistema.x, 0, n * sizeof(double));

    for (int iter = 0; iter < n; iter++)
    {
        int linha_destino = rand() % n;
        int linha_origem = rand() % n;
        double fator = (double)(rand() % 100 + 1) / 100.0;

        for (int j = 0; j < n; j++)
        {
            sistema.A[linha_destino][j] += fator * sistema.A[linha_origem][j];
        }
        sistema.b[linha_destino] += fator * sistema.b[linha_origem];
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

void eliminacao_gaussiana_seq(SistemaLinear *s)
{
    const double EPS = 1e-8;
    int n = s->n;
    double **A = s->A;
    double *B = s->b;

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            double fator = A[i][j] / A[j][j];

            if (fabs(fator) < EPS)
                continue;

            double y = fator * B[j];
            double t = B[i] - y;
            B[i] = t;

            for (int k = j; k < n; k++)
            {
                y = fator * A[j][k];
                t = A[i][k] - y;
                A[i][k] = t;
            }
        }
    }
}

void eliminacao_gaussiana_par(SistemaLinear *s, int num_threads)
{
    const double EPS = 1e-8;
    int n = s->n;
    double **A = s->A;
    double *B = s->b;

#pragma omp parallel num_threads(num_threads) default(none) shared(A, B, n, EPS)
    {
        for (int j = 0; j < n - 1; j++)
        {
#pragma omp for schedule(guided)
            for (int i = j + 1; i < n; i++)
            {
                double fator = A[i][j] / A[j][j];
                if (fabs(fator) < EPS) continue;
                double y = fator * B[j];
                B[i] -= y;
                for (int k = j; k < n; k++)
                {
                    A[i][k] -= fator * A[j][k];
                }
            }
        }
    }
}

int verificar_solucoes_iguais(SistemaLinear *s1, SistemaLinear *s2)
{
    if (s1->n != s2->n)
    {
        printf("Sistemas de tamanhos diferentes (n1=%d, n2=%d)\n", s1->n, s2->n);
        return 0;
    }

    int ok = 1;
    double max_diff = 0.0;
    int max_diff_index = -1;

    for (int i = 0; i < s1->n; i++)
    {
        double diff = fabs(s1->x[i] - s2->x[i]);
        if (diff > max_diff)
        {
            max_diff = diff;
            max_diff_index = i;
        }
        if (diff > eps)
        {
            ok = 0;
        }
    }

    if (!ok)
    {
        printf("Diferença máxima encontrada: %.6e na posição %d\n", max_diff, max_diff_index);
        printf("Valores: s1[%d]=%.6f, s2[%d]=%.6f\n",
               max_diff_index, s1->x[max_diff_index],
               max_diff_index, s2->x[max_diff_index]);
    }

    return ok;
}