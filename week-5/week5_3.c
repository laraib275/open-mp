#include <stdio.h>
#include <omp.h>

#define N 100000  // Size of the array

int main() {
    int arr[N];
    int i, last_val;

    // Define the number of threads
    int num_threads = 4;
    
    // Set the number of threads for OpenMP
    omp_set_num_threads(num_threads);

    // Split the parallel region and for loop, then apply 'nowait' to the for loop
    #pragma omp parallel 
    {
        #pragma omp for lastprivate(i) nowait
        for (i = 0; i < N; i++) {
            int thread_id = omp_get_thread_num();
            arr[i] = i + 1;  
            printf("Thread %d initialized arr[%d] = %d\n", thread_id, i, arr[i]);
        }
    }

    // Capture the last value initialized by the last thread
    last_val = i;
    printf("Last value initialized by a thread: %d\n", last_val);

    return 0;
}



