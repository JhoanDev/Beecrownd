#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int n;
    double **A;
    double *b; // termos independentes
    double *x; // solucao para cada termo
} SistemaLinear;

SistemaLinear criar_sistema(int n);
void liberar_sistema(SistemaLinear *s);
void algoritmo_linhas(SistemaLinear *s);
void algorimo_colunas(SistemaLinear *s);
void printa_solucao(SistemaLinear *s);
void printar_sistema_com_solucao(SistemaLinear *s);
void algoritmo_linhas_paralelo(SistemaLinear *s, int num_threads);
void algorimo_colunas_paralelo(SistemaLinear *s, int num_threads);

int main(int argc, char *argv[])
{
    double start_time, end_time;
    double segs;
    int count_ranks = atoi(argv[1]);
    int n = atoi(argv[2]);

    SistemaLinear sist_1 = criar_sistema(n);
    SistemaLinear sist_2 = criar_sistema(n);
    SistemaLinear sist_3 = criar_sistema(n);
    // SistemaLinear sist_4 = criar_sistema(n);

    start_time = omp_get_wtime();
    algoritmo_linhas(&sist_1);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Algoritmo linhas sequencial demorou: %.5lfs\n", segs);
    if (n < 10)
    {
        printar_sistema_com_solucao(&sist_1);
        printf("=====================================================\n");
    }

    start_time = omp_get_wtime();
    algoritmo_linhas_paralelo(&sist_3, count_ranks);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Algoritmo linhas paralelo demorou: %.5lfs\n", segs);
    if (n < 10)
    {
        printar_sistema_com_solucao(&sist_3);
        printf("=====================================================\n");
    }

    start_time = omp_get_wtime();
    algorimo_colunas(&sist_2);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Algoritmo colunas sequencial demorou: %.5lfs\n", segs);

    if (n < 10)
    {
        printar_sistema_com_solucao(&sist_2);
        printf("=====================================================\n");
    }

    start_time = omp_get_wtime();
    algorimo_colunas_paralelo(&sist_2, count_ranks);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Algoritmo colunas paralelo demorou: %.5lfs\n", segs);

    if (n < 10)
    {
        printar_sistema_com_solucao(&sist_2);
        printf("=====================================================\n");
    }

    liberar_sistema(&sist_1);
    liberar_sistema(&sist_2);

    return 0;
}

SistemaLinear criar_sistema(int n)
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

void printa_solucao(SistemaLinear *s)
{
    int i;
    for (i = 0; i < s->n; i++)
    {
        printf("[%d] = %.2f\n", i, s->x[i]);
    }
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

void algoritmo_linhas_paralelo(SistemaLinear *s, int num_threads)
{
    int lin, col;
    int n = s->n;
    double sum;

#pragma omp parallel num_threads(num_threads) default(none) private(lin) shared(col, s, n, sum)
    {
        for (lin = n - 1; lin >= 0; lin--)
        {
            sum = 0;
#pragma omp for schedule(runtime) reduction(- : sum)
            for (col = lin + 1; col < n; col++)
                sum -= s->A[lin][col] * s->x[col];
#pragma omp single
            {
                sum += s->b[lin];
                s->x[lin] = sum / s->A[lin][lin];
            }
        }
    }
}

void algoritmo_linhas(SistemaLinear *s)
{
    int lin, col;
    int n = s->n;
    for (lin = n - 1; lin >= 0; lin--)
    {
        s->x[lin] = s->b[lin];
        for (col = lin + 1; col < n; col++)
            s->x[lin] -= s->A[lin][col] * s->x[col];
        s->x[lin] /= s->A[lin][lin];
    }
}

void algorimo_colunas_paralelo(SistemaLinear *s, int num_threads)
{
    int lin, col;
    int n = s->n;

#pragma omp parallel num_threads(num_threads) default(none) private(lin, col) shared(s, n)
    {
#pragma omp for schedule(runtime)
        for (lin = 0; lin < n; lin++)
            s->x[lin] = s->b[lin];
#pragma omp barrier
        for (col = n - 1; col >= 0; col--)
        {
            s->x[col] /= s->A[col][col];
#pragma omp for schedule(runtime)
            for (lin = 0; lin < col; lin++)
                s->x[lin] -= s->A[lin][col] * s->x[col];
        }
    }
}

void algorimo_colunas(SistemaLinear *s)
{
    int lin, col;
    int n = s->n;

    for (lin = 0; lin < n; lin++)
        s->x[lin] = s->b[lin];

    for (col = n - 1; col >= 0; col--)
    {
        s->x[col] /= s->A[col][col];
        for (lin = 0; lin < col; lin++)
            s->x[lin] -= s->A[lin][col] * s->x[col];
    }
}

/*

**(i) Orientado a linhas:**

for (lin = n-1; lin >= 0; lin--) {
    x[lin] = b[lin];
    for (col = lin+1; col < n; col++)
        x[lin] -= A[lin][col]*x[col];
    x[lin] /= A[lin][lin];
}

**(ii) Orientado a colunas:**

for (lin = 0; lin < n; lin++)
    x[lin] = b[lin];

for (col = n-1; col >= 0; col--) {
    x[col] /= A[col][col];
    for (lin = 0; lin < col; lin++)
        x[lin] -= A[lin][col]*x[col];
}


(a) O laço externo do algoritmo orientado a linhas pode ser paralelizado? não, tem dependencia do valor do laco de dentro

(b) O laço interno do algoritmo orientado a linhas pode ser paralelizado? sim

(c) O segundo laço externo do algoritmo orientado a colunas pode ser paralelizado? não, pode ser que duas threads alterem o mesmo valor  no vetor s->x

(d) O laço interno do algoritmo orientado a colunas pode ser paralelizado?

(e) Escreva um programa OpenMP para cada loop que puder ser paralelizado. Pode usar `#pragma omp single` se necessário.

(f) Adicione `schedule(runtime)` ao laço paralelo e teste com diferentes políticas. Com 10.000 variáveis, qual escalonamento oferece melhor desempenho?




*/