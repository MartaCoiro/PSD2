#include <stdio.h>
#define N 10

void insertSortedArray(int *array, int *size, int element) {
	
	int i;
	for(i=*size;i>0;i--) 
		if(element < array[i-1]) 
			array[i] = array[i-1];
		else 
			break;
		
	array[i] = element;
	*size += 1;
	//(*size)++;
}

void insertion_sort(int *array, int size) {
	
	int i;
	for(i=1;i<size;)
		insertSortedArray(array,&i,array[i]);
}

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


int main() {
	int a[N],n;
	printf("Quanti elementi vuoi inserire ?");
	scanf("%d", &n);
	input_array(a,n);
	insertion_sort(a,n);
	output_array(a,n);
	return 0;
	}