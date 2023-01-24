#include <stdio.h>
#include "utils.h"

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

int min(int *a, int n) {
	int i;
	for(i=1;i<n;i++) 
		if(a[i]<a[min]
			min = i;
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

void bubbleSort(int *array, int n) {
	int i,j;
	for(i=1;i<n;i++) //nella prima iterata scambiamo elementi adiacenti fino alla fine
		for(j=0;j<n-i;j++) //faremo un'iterazione in meno, perchè non arriviamo all'ultimo elemento ma sempre al penultimo
			if(array[j]>array[j+1]) //perchè scambiamo elementi adiacenti
				swap(&array[j],&array[j+1]);
			
}

int adaptiveBubbleSort(int *array, int n) {
	int i,j, ordinato=0, contatore=0; // ci contiamo quanti scambi fa;
	for(i=1;i<n && !ordinato;i++) { //nella prima iterata scambiamo elementi adiacenti fino alla fine
		ordinato=1;
		for(j=0;j<n-i;j++){ //faremo un'iterazione in meno, perchè non arriviamo all'ultimo elemento ma sempre al penultimo
			contatore++;
			if(array[j]>array[j+1]) { //perchè scambiamo elementi adiacenti
				ordinato=0;
				swap(&array[j],&array[j+1]);
			}
		}
	}	
	return contatore;	
}