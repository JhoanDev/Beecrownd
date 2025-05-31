#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define comm MPI_COMM_WORLD

void Usage(char prog_name[]);
void Get_args(char *argv[], int *bin_count_p, float *min_meas_p, float *max_meas_p, int *data_count_p);
void Gen_data(float min_meas, float max_meas, float data[], int data_count, int my_rank);
void Gen_bins(float min_meas, float max_meas, float bin_maxes[], int bin_counts[], int bin_count);
int Which_bin(float data, float bin_maxes[], int bin_count, float min_meas);
void Print_histo(float bin_maxes[], int bin_counts[], int bin_count, float min_meas, int data_count);

int main(int argc, char *argv[]) {
    int bin_count, i, bin;
    float min_meas, max_meas;
    float *bin_maxes;
    int *bin_counts = NULL, *local_bin_counts;
    int data_count, my_rank, comm_sz, rest, local_data_count, chunk;
    float *data;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    if (my_rank == 0) {
        if (argc != 5)
            Usage(argv[0]);
        Get_args(argv, &bin_count, &min_meas, &max_meas, &data_count);
    }

    MPI_Bcast(&bin_count, 1, MPI_INT, 0, comm);
    MPI_Bcast(&min_meas, 1, MPI_FLOAT, 0, comm);
    MPI_Bcast(&max_meas, 1, MPI_FLOAT, 0, comm);
    MPI_Bcast(&data_count, 1, MPI_INT, 0, comm);

    rest = data_count % comm_sz;
    chunk = data_count / comm_sz;
    local_data_count = chunk;
    if (my_rank < rest) {
        local_data_count++;
    }

    bin_maxes = (float *)malloc(bin_count * sizeof(float));
    local_bin_counts = (int *)malloc(bin_count * sizeof(int));
    data = malloc(local_data_count * sizeof(float));

    Gen_data(min_meas, max_meas, data, local_data_count, my_rank);
    Gen_bins(min_meas, max_meas, bin_maxes, local_bin_counts, bin_count);

    for (i = 0; i < local_data_count; i++) {
        bin = Which_bin(data[i], bin_maxes, bin_count, min_meas);
        local_bin_counts[bin]++;
    }

    if (my_rank == 0) {
        bin_counts = (int *)malloc(bin_count * sizeof(int));
    }
    MPI_Reduce(local_bin_counts, bin_counts, bin_count, MPI_INT, MPI_SUM, 0, comm);

    if (my_rank == 0) {
        Print_histo(bin_maxes, bin_counts, bin_count, min_meas, data_count);
        free(bin_counts);
    }

    free(data);
    free(bin_maxes);
    free(local_bin_counts);

    MPI_Finalize();
    return 0;
}

void Usage(char prog_name[]) {
    fprintf(stderr, "usage: %s ", prog_name);
    fprintf(stderr, "<bin_count> <min_meas> <max_meas> <data_count>\n");
    exit(0);
}

void Get_args(char *argv[], int *bin_count_p, float *min_meas_p, float *max_meas_p, int *data_count_p) {
    *bin_count_p = strtol(argv[1], NULL, 10);
    *min_meas_p = strtof(argv[2], NULL);
    *max_meas_p = strtof(argv[3], NULL);
    *data_count_p = strtol(argv[4], NULL, 10);
}

void Gen_data(float min_meas, float max_meas, float data[], int data_count, int my_rank) {
    int i;
    srandom(time(NULL) + my_rank);
    for (i = 0; i < data_count; i++) {
        data[i] = min_meas + (max_meas - min_meas) * random() / ((double)RAND_MAX);
    }
}

void Gen_bins(float min_meas, float max_meas, float bin_maxes[], int bin_counts[], int bin_count) {
    float bin_width;
    int i;

    bin_width = (max_meas - min_meas) / bin_count;

    for (i = 0; i < bin_count; i++) {
        bin_maxes[i] = min_meas + (i + 1) * bin_width;
        bin_counts[i] = 0;
    }
}

int Which_bin(float data, float bin_maxes[], int bin_count, float min_meas) {
    int bottom = 0, top = bin_count - 1;
    int mid;
    float bin_max, bin_min;

    while (bottom <= top) {
        mid = (bottom + top) / 2;
        bin_max = bin_maxes[mid];
        bin_min = (mid == 0) ? min_meas : bin_maxes[mid - 1];

        if (data >= bin_max) {
            bottom = mid + 1;
        } else if (data < bin_min) {
            top = mid - 1;
        } else {
            return mid;
        }
    }

    fprintf(stderr, "Data = %f doesn't belong to a bin!\n", data);
    fprintf(stderr, "Quitting\n");
    exit(-1);
}

void Print_histo(float bin_maxes[], int bin_counts[], int bin_count, float min_meas, int data_count) {
    int i, j;
    float bin_max, bin_min;
    const int limite_de_data = 100;

    if (data_count > limite_de_data) {
        printf("Exibindo contagem numérica (total de dados > %d)\n", limite_de_data);
        printf("--------------------------------------------\n");
        for (i = 0; i < bin_count; i++) {
            bin_max = bin_maxes[i];
            bin_min = (i == 0) ? min_meas : bin_maxes[i - 1];
            printf("%.3f-%.3f:\t%d\n", bin_min, bin_max, bin_counts[i]);
        }
    } else {
        for (i = 0; i < bin_count; i++) {
            bin_max = bin_maxes[i];
            bin_min = (i == 0) ? min_meas : bin_maxes[i - 1];
            printf("%.3f-%.3f:\t", bin_min, bin_max);
            for (j = 0; j < bin_counts[i]; j++) {
                printf("X");
            }
            printf("\n");
        }
    }
}