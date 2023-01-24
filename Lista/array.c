#include <stdio.h>
#include "item.h"
#include "utils.h"
#define N 50

void input_array(Item *a, int n){
	int i;
	for(i=0; i<n; i++)
		a[i]=inputItem();
}

void output_array(Item *a, int n){
	int i;
	for(i=0; i<n; i++)
		outputItem(a[i]);
}




void bubble_sort(Item *a, int n){
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(cmpItem(a[j],a[j+1])>0)
				swap(&a[j],&a[j+1]);
}


