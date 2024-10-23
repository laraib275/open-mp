#include <stdio.h>
#include <omp.h>

#define N 1000  // Reduced size of the array for testing

int main() {
    int arr[N];
    int i, chunk_size, last_idx;

    // Initialize the array with values
    for (i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    // Define the number of threads
    int num_threads = 4;
    
    // Set the number of threads for OpenMP
    omp_set_num_threads(num_threads);

    // Calculate the chunk size (the number of elements each thread will process)
    chunk_size = N / num_threads;

    // Parallel region for doubling the values in the array using multiple threads
    #pragma omp parallel firstprivate(chunk_size) 
    {
        int thread_id = omp_get_thread_num();
        int start_idx = thread_id * chunk_size;  

        #pragma omp for lastprivate(i) nowait
        for (i = start_idx; i < N; i++) {
            arr[i] = arr[i] * 2;

            #pragma omp critical
            {
                printf("Thread %d doubled arr[%d] = %d\n", thread_id, i, arr[i]);
            }
        }
    }

    printf("\nFinal array after doubling:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    // Capture the last index processed by the last thread
    last_idx = i;
    printf("\nLast index processed: %d\n", last_idx);

    return 0;
}

