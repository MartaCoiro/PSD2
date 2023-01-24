#include <stdio.h>
#include "utils.h"
#include "item.h"
#define N 100

void output_array(Item *a, int n) {
	int i;

	for(i = 0; i < n; i++)
		outputItem(a[i]);

	printf("\n");
}

int minimo(Item *a, int n) {
	int min = 0, i;

	for(i=1; i<n; i++)
		if (cmpItem(a[i],a[min])<0)
			min=i;

    return min;
}

void selection_sort(Item a[], int n) {
	int i = 0,
		min;

	for(; i < n - 1; i++) {
		min = minimo(a + i, n - i);

		swap(&a[i], &a[min + i]);
	}
}

void selection_sort_ric(Item a[], int n) {   // T(n)=T(n-1)+b*(n-1) +d QUADRATICO con n per n>1.
                                                                   
	if(n==1)                                 
		return;
	int min=minimo(a+1,n-1)+1;
	
	if(cmpItem(a[min],a[0])<0)
		swap(&a[0],&a[min]);
	
	selection_sort_ric(a+1,n-1);
}


void input_array(Item a[], int n) {
	int i=0;

	for (; i<n; i++)
		a[i]=inputItem();
}
