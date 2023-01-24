#include <stdio.h>
#define N 50

void swap( int *a , int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void input_array(int *a, int n) {
	int i;
	for(i=0; i<n ; i++) 
		scanf("%d", &a[i]);
}

void output_array(int *a, int n) {
	int i;
	for(i=0; i<n ; i++) 
		printf("%d ", a[i]);
}

int min( int *a, int n) {
	int min=0, i;
	for(i=1; i<n ; i++) 
		if(a[i] <a[min])
			min=i;
	
	return min;
}



void selection_sort(int *a, int n) {
	int i;
	int m;
	for(i=0;i<n-1;i++) {
		m = min(a+i,n-i)+i;
		swap(&a[i],&a[m]);
	}
	
}

int main() {
	int a[N];
	int n=5, m;
	input_array(a,n);
	selection_sort(a,n);
	output_array(a,n);
	return 0;
	}