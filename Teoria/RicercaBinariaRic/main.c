#include <stdio.h> //Parentesi angolari per librerie già presenti in C
#include "vettore.h" //Virgolette prendiamo delle librerie locali
#define N 10

int main() {
	int a[N],n, cont,el, valore;
	printf("Quanti elementi vuoi inserire ?");
	scanf("%d", &n);
	input_array(a,n);
	
	printf("\nInserisci elemento da cercare: ");
	scanf("%d", &el);
	valore=RicercaBinariaRic(a,n,el);
	//Oppure chiamiamo la ricerca lineare
	
	if(valore <0 ) 
		printf("Elemento non trovato");
	else 
		printf("Elemento trovato in posizione %d ", valore);
	return 0;
	}