#include <stdio.h>
#include "vettore.h"
#define N 10

int main() {
	int A[N];
	int n=5;
	input_array(A,n);
	bubble_sort(A,n);
	output_array(A,n);
	return 0;	
}