#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
void input_array(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void output_array(int a[], int n) {
	int i;
	for(i=0;i<n;i++) 
		printf("%d ",a[i]);
  	
}


int min(int a[],int n) {
	int min=0;
	int i;
	for(i=1;i<n;i++) 
		if(a[i]<a[min])
			min=i;
	return min;
}

void selection_sort(int a[], int n) {
	int i, m;
	for(i=0;i<n;i++) {
		m=min(a+i, n-i);
		swap(&a[i], &a[m+i]);
	}
}

void bubble_sort(int a[], int n){
	int i,j;
	
	for(i = 1; i < n; i++) 
		for(j = 0; j < n - i; j++) 
			if(a[j] > a[j+1])
				swap(&a[j],&a[j+1]);
}

void adaptive_bubble_sort(int a[], int n){
	int i,j,ordinato = 0;
	
	for(i = 1; i < n && !ordinato; i++) {
		ordinato = 1;
		for(j = 0; j < n - i; j++) 
			if(a[j] > a[j+1]) {
				swap(&a[j],&a[j+1]);
				ordinato = 0;
		}
	}
}

void insert_array(int a[], int *n, int el, int pos){
	int i;
	if(pos<0||pos>*n)
		return;
	for(i=*n;i>pos;i--)
		a[i]=a[i-1];
	a[pos]=el;
	++*n;
}


void insert_sorted_array(int a[], int *n, int el){
	int i;
	
	for(i=*n;i>0 && a[i-1]>el;i--)
		a[i]=a[i-1];
	a[i]=el;
	++*n;
}


void insertion_sort(int a[],int n){
	int i=1;
	while(i<n)
		insert_sorted_array(a,&i,a[i]);
}

int compare_arrays(int a [], int b [],int  n1, int n2){
		int i;
		if(n1!=n2)
			return 0;
		for(i=0; i<n1 ;i++)
			if(a[i]!= b[i])
				return 0;
		return 1;
}

int input_array_str(int *arr,char* line){
	int i=0,n=0;
	while(sscanf(line,"%d%n",&arr[i],&n)==1){
		line+=n;
		i++;
	}	
	return i;
}


int *input_array_dyn(int *size, char* line){
	int i=0,n=0;
	*size = conta_spazi(line) + 1;
	
	int *arr = malloc((*size) * sizeof(int));
	
	if (arr == NULL) {
		fprintf(stderr, "Couldn't allocate %d bytes\n", ((*size) * sizeof(int)));
		exit(EXIT_FAILURE);
	}
	
	while(sscanf(line,"%d%n",&arr[i],&n)==1){
		line+=n;
		i++;
	}
	
	return arr;
}