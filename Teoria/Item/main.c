#include <stdio.h> //Parentesi angolari per librerie già presenti in C
#include "vettore.h" //Virgolette prendiamo delle librerie locali
#include "item.h"
#define N 10

int main() {
	Item a[N];
	int n=5;
	input_array(a,n);
	bubbleSort(a,n);
	output_array(a,n);
	return 0;
	}