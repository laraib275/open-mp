#include<stdio.h>
#include<omp.h>
#include <stdlib.h>
int main() {
	srand(time(NULL));
	
	int i;
	int tid;
	
	//printf("Random number generated : %d \n", n);
	#pragma omp parallel num_threads(4) private(i,tid)
	{
		int n=1+ rand()%10;
		tid= omp_get_thread_num();
		int threads = omp_get_num_threads();
	//	#pragma parallel for
		for(i=0; i<n; i++){
			printf("Hello world from %d of random num %d\n", tid, n);
	}
	}
	 }
	
	

