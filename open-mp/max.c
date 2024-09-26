#include<stdio.h>
#include<omp.h>
#include <limits.h>
#include <float.h>
#define n 10
long arr[n];
int main() {
	int i;
	int local_min=INT_MIN;
	for(i=0; i<n; i++){
		arr[i]=i+1;
	}
	#pragma omp parallel
	{
	int min=INT_MIN;
	#pragma omp parallel for
	for(i=0; i<=n; i++){
		if(arr[i]>min){
		min=arr[i];
		}
	}
	#pragma omp critical 
	{
	
	if(local_min<min){
		local_min=min;
	}
} }
printf("Maximum value : %d ", local_min);

}
	
		
