#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
        return 0;

    double ini, end;
    ini = omp_get_wtime();

    unsigned int seed = time(NULL), thread_seed;
    int count_ranks = atoi(argv[1]);
    long long int num_lancamentos = atoi(argv[2]);
    int i;
    int qtd_circ = 0;
    double x, y, distancia_quadrada, estimativa_pi;

#pragma omp parallel num_threads(count_ranks) default(none) \
private(x, y, distancia_quadrada, thread_seed) shared(num_lancamentos, qtd_circ, seed)
    {
        thread_seed = seed + omp_get_thread_num();
#pragma omp for reduction(+ : qtd_circ)
        for (i = 0; i < num_lancamentos; i++)
        {
            x = (rand_r(&thread_seed) / (double) RAND_MAX - 0.5) * 2;
            y = (rand_r(&thread_seed) / (double) RAND_MAX - 0.5) * 2;

            distancia_quadrada = x * x + y * y;
            if (distancia_quadrada <= 1)
                qtd_circ++;
        }
    }

    estimativa_pi = 4.0 * qtd_circ / (double)num_lancamentos;

    printf("%.10lf\n", estimativa_pi);
    end = omp_get_wtime();
    printf("%.5lfs\n", end - ini);
    return 0;
}