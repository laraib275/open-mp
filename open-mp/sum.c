#include<stdio.h>
#include<omp.h>
#define n 100000
int main() {
	int arr[n];
	 int sum=0;
	 int i;
	 for(i=0; i<n; i++) {
	 	arr[i]=1;
	 }
	 
	 #pragma  omp parallel for reduction(+:sum)
	 
	 	for(i=0; i<n; i++ ){
	 		sum=sum+arr[i];
		 }
	 
	 
	 printf("Sum : %d ", sum);
	 }
