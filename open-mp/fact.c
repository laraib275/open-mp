#include<stdio.h>
#include<omp.h>
int main() {
	int i;
	long long fact=1;
	long n=10;
	#pragma omp parallel for reduction(*:fact)
	for(i=2; i<=n; i++){
		fact=fact*i;
	}
	printf("Factorial of num : %lld by threaad : %d\n", fact, omp_get_thread_num());
	
}
