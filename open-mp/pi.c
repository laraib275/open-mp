#include<stdio.h>
#include<omp.h>
int main() {

 long int i, n=90000;
 double sum=0.0, term, pi;

 /* Applying Leibniz Formula */
 #pragma omp parallel for reduction(+:sum)
 for(i=0;i< n;i++)
 {
  term = pow(-1, i) / (2*i+1);
  sum += term;
 }
 pi = 4 * sum;
 printf("\nPI = %.6lf", pi);
 
 return 0;
}
