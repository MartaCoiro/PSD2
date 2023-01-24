#include <stdio.h> //Parentesi angolari per librerie già presenti in C
#include "vettore.h" //Virgolette prendiamo delle librerie locali
#define N 10

int main() {
	int a[N],n, cont;
	printf("Quanti elementi vuoi inserire ?");
	scanf("%d", &n);
	input_array(a,n);
	//insertion_sort(a,n);
	//bubbleSort(a,n);
	cont=adaptiveBubbleSort(a,n);
	output_array(a,n);
	printf("Abbiamo fatto %d confronti \n", cont);
	return 0;
	}