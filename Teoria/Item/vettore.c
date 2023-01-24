#include <stdio.h>
#include "utils.h"
#include "item.h"

void input_array(Item *a, int n) {
	int i;
	for(i=0; i<n ; i++) 
		//scanf("%d", &a[i]); utilizziamo la funzione di inputItem
		a[i] = inputItem();
	
}

void output_array(Item *a, int n) {
	int i;
	for(i=0; i<n ; i++) 
		//printf("%d ", a[i]); utilizziamo la funzione outputItem
		outputItem(a[i]);
}


void bubbleSort(Item *array, int n) {
	int i,j;
	for(i=1;i<n;i++) //nella prima iterata scambiamo elementi adiacenti fino alla fine
		for(j=0;j<n-i;j++) //faremo un'iterazione in meno, perchè non arriviamo all'ultimo elemento ma sempre al penultimo
			//if(array[j]>array[j+1]) //perchè scambiamo elementi adiacenti
				if(compareItem(array[j],array[j+1])>0)
				
				swap(&array[j],&array[j+1]);
			
}

  