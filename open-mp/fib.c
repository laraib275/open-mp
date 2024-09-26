#include<stdio.h>
#include<omp.h>
int main() {
	long n=10;
	int i;
	#pragma omp parallel for ordered
	for(i=0; i<n; i++){	
	#pragma omp ordered	
		printf("%d ", fib(i));
	}
}
int fib(int num){
	if(num==0){
		return 0;
	}
	if(num==1){
		return 1;
	}
	int j ;
	int x=0; int y=1;
	int sum=0;
	for (j = 2; j <= num; j++){
		sum=x+y;
		x=y;
		y=sum;
	}
	return sum;
}
