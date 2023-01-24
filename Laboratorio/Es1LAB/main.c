#include <stdio.h>
#include "vettore.h"


int main() {
	int A[N];
	int n=5, el;
	int i;
	printf("Inserisci l'array");
	input_array(A,n);
	selection_sort(A,n);
	output_array(A,n);
	
	printf("Inserisci il numero da cercare");
	scanf("%d", &el);
	
	printf("Posizione dell'elemento : %d\n", search_element(A,n,el));
	
	return 0;
}