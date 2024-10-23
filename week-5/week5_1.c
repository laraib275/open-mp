#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_SIZE 10000000
long long sequential_sum(int* arr, int size) {
    long long sum = 0;
    int i;
    for ( i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

long long parallel_sum(int* arr, int size, int num_threads) {
    long long sum = 0;

    // Set the number of threads
    omp_set_num_threads(num_threads);
 int i;
    #pragma omp parallel for reduction(+:sum)
   
    for ( i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
	int i;
    int* array=(int*)malloc(ARRAY_SIZE*sizeof(int));
    //-int array[ARRAY_SIZE];
    srand(time(0));
    for ( i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 1;
    }
    double start_time = omp_get_wtime();
    long long seq_sum = sequential_sum(array, ARRAY_SIZE);
    double end_time = omp_get_wtime();
    double seq_time = end_time - start_time;

    printf("Sequential sum: %lld\n", seq_sum);
    printf("Sequential time: %f seconds\n", seq_time);
int num_threads;
    for ( num_threads = 2; num_threads <= 8; num_threads *= 2) {
        start_time = omp_get_wtime();
        long long par_sum = parallel_sum(array, ARRAY_SIZE, num_threads);
        end_time = omp_get_wtime();
        double par_time = end_time - start_time;

        printf("\nParallel sum with %d threads: %lld\n", num_threads, par_sum);
        printf("Parallel time with %d threads: %f seconds\n", num_threads, par_time);

        double speedup = seq_time / par_time;
        double efficiency = speedup / num_threads;

        printf("Speedup with %d threads: %f\n", num_threads, speedup);
        printf("Efficiency with %d threads: %f\n", num_threads, efficiency);
    }

    return 0;
}
