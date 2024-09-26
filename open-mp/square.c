#include<stdio.h>
#include<omp.h>
#define n 100
int main() {
	int arr[n];
	int c[n];
	 long square=1;
	 int i;
	
	 for(i=0; i<n; i++) {
	 	arr[i]=i+1;
	 }
	 
	 #pragma omp parallel for 
	 
	 	for(i=0; i<n; i++ ){
	 	c[i]=arr[i]*arr[i];
	 
		}
		
		for(i=0; i<n; i++){
			printf("%d \n ",c[i]);
		}

	 
}

