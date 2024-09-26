#include<stdio.h>
#include<omp.h>
#define n 100
int main(){
	int a[n];
	int b[n];
	int c[n];
	int i, j;
	
	for(i=0; i<n; i++){
		a[i]=2;
	}
	
		for(i=0; i<n; i++){
		b[i]=1;
	}
	
	#pragma omp parallel for
	for(i=0; i<n; i++){
	printf(" thread num %d\n",  omp_get_thread_num());
		c[i]=a[i]-b[i];
	}
			for(i=0; i<n; i++){
		printf("%d \n", c[i]);
	}
	
	
}
