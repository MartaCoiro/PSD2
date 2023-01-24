
#include <stdio.h>
#include "utils.h"

int min(int a[], int n); //Dichiarazione locale perchè non sta negli altri moduli

void input_array(int a[], int n) {
	int i;
	for(i=0; i<n ; i++) 
		scanf("%d", &a[i]);
}

void output_array(int a[], int n) {
	int i;
	for(i=0; i<n ; i++) 
		printf("%d ", a[i]);
}

void selection_sort(int a[], int n) {
	int i, m;
	for(i=0; i<n ; i++) {
		m = min(a+i , n-i);
		swap(&a[i], &a[m+i]);
	}
	
}

void delete_element(int a[], int *n, int pos) {
	int i;
	for(i=pos; i<*n-1; i++) 
		a[i] = a[i+1];
	--*n;
}

void insert_array(int a[], int *n, int el, int pos){
	int i;
	if(pos<0 || pos>*n) 
		return;
	for(i=*n; i>pos; i--)
		a[i] = a[i-1];
	a[pos] = el;
	++*n;
}

int search_element(int a[], int n, int el){
	int i;
	for(i=0; i<n; i++) 
		if(a[i] == el)
			return i;
		return -1;
}

int min( int a[], int n) {
	int min =0;
	int i;
	for(i=1; i<n ; i++) 
		if(a[i] <a[min])
			min=i;
		return min;
}
