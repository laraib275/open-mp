#include<stdio.h>
#include<omp.h>
int main() {
	
	int i;
	int tid;
	omp_set_num_threads(3);
	
	#pragma omp parallel for private(tid)
	
	for(i=0; i<=100; i++){
		tid=omp_get_thread_num();
		printf("%d by thread num : %d \n", i, tid);
	}
}
