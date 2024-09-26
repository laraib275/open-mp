#include <stdio.h>
#include <omp.h>

int main() {
    int i;

    double t1 = omp_get_wtime(); // Start timing
    omp_set_num_threads(5); // Set the number of threads

    #pragma omp parallel 
    {
        int tid = omp_get_thread_num(); // Get the thread ID

        // Each thread executes a portion of the loop
        if (tid == 0) {
        	#pragma omp parallel for
            for (i = 1; i <= 20; i++) {
                printf("%d : from thread num : %d \n", i, tid);
            }
        } else if (tid == 1) {
        	#pragma omp parallel for
            for (i = 21; i <= 40; i++) {
                printf("%d : from thread num : %d \n", i, tid);
            }
        } else if (tid == 2) {
        	#pragma omp parallel for
            for (i = 41; i <= 60; i++) {
                printf("%d : from thread num : %d \n", i, tid);
            }
        } else if (tid == 3) {
        	#pragma omp parallel for
            for (i = 61; i <= 80; i++) {
                printf("%d : from thread num : %d \n", i, tid);
            }
        } else if (tid == 4) {
        	#pragma omp parallel for
            for (i = 81; i <= 100; i++) {
                printf("%d : from thread num : %d \n", i, tid);
            }
        }
    }

    double t2 = omp_get_wtime(); // End timing
    printf("Time taken: %f seconds\n", t2 - t1); // Use %f for floating point

    return 0;
}

