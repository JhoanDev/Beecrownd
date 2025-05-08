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
void printa_solucao(SistemaLinear *s);
void printar_sistema_com_solucao(SistemaLinear *s);
void minha_implementacao(SistemaLinear *s, int num_threads);
void algoritmo_linhas(SistemaLinear *s);

int main(int argc, char *argv[]) {
    double start_time, end_time;
    int count_ranks = atoi(argv[1]);
    int n = atoi(argv[2]);

    // Criar dois sistemas IDÊNTICOS
    SistemaLinear sist_paralelo = criar_sistema(n);
    SistemaLinear sist_sequencial = criar_sistema(n);
    
    // Medição versão paralela
    start_time = omp_get_wtime();
    minha_implementacao(&sist_paralelo, count_ranks);
    end_time = omp_get_wtime();
    printf("Time paralelo: %.5lfs\n", end_time - start_time);

    // Medição versão sequencial
    start_time = omp_get_wtime();
    algoritmo_linhas(&sist_sequencial);
    end_time = omp_get_wtime();
    printf("Time sequencial: %.5lfs\n", end_time - start_time);

    // Verificação (opcional) - comparar soluções
    if (n < 10) {
        printf("Solução paralela:\n");
        printar_sistema_com_solucao(&sist_paralelo);
        printf("\nSolução sequencial:\n");
        printar_sistema_com_solucao(&sist_sequencial);
    }

    liberar_sistema(&sist_paralelo);
    liberar_sistema(&sist_sequencial);

    return 0;
}

// 3 4 5 = 0
// 0 5 2 = 5
// 0 0 2 = 4

// s->x [0,5,2(v)]

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

void minha_implementacao(SistemaLinear *s, int threads)
{
    int n = s->n;
    double *x = s->x;
    double *b_copy = (double*)malloc(n * sizeof(double));
    
    #pragma omp parallel num_threads(threads)
    {
        #pragma omp for
        for (int i = 0; i < n; i++) {
            b_copy[i] = s->b[i];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            #pragma omp master
            x[i] = b_copy[i] / s->A[i][i];
            #pragma omp barrier
            
            #pragma omp for schedule(static)
            for (int j = i - 1; j >= 0; j--) {
                b_copy[j] -= x[i] * s->A[j][i];
            }
        }
    }
    free(b_copy);
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
