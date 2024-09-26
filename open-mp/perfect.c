#include<stdio.h>
#include<omp.h>
int isperfect(int num){
	int sum=0;
	int i;
	int rem;
	for(i=1; i<num; i++) {
		rem=num%i;
		if(rem==0){
			sum =sum+i;
		}
	}
	if(sum==num){
		return 1;
	}
	return 0;
	
}
int main(){
	long i;
	float t1=omp_get_wtime();
	#pragma omp parallel for
	for(i=1; i<=20000; i++){
		if(isperfect(i)==1){
			printf("%d is perfect number .. thread number : %d \n ", i, omp_get_thread_num());
		}
		
	}
	float t2=omp_get_wtime();
	float time=t2-t1;
	printf("time take : %f sec ", time);
	return 0;
}
