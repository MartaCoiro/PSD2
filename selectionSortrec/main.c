#include <stdio.h>
#include "vettore.h"
#include "item.h"


int main(){
	int i, n = 5;
	Item  arr[5];
	printf("Introduci il vettore di 5 elementi: ");
	input_array(arr, n);
	selection_sort_ric(arr, n);
	printf("Vettore ordinato: ");
	output_array(arr, n);
}
