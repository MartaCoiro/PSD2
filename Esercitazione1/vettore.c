#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utils.h"

void inputArray(int *a,int n) {
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void outputArray(int *a,int n) {
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

void selection_sort_max(int a[],int n) {
	int i,j,max=0;
	for(j=0;j<n;j++) {
		for(i=0,max=0;i<n-j;i++)
			if(a[i]>=a[max])
				max=i;
			swap(&a[max],&a[n-j-1]);
	}
}

//Specifica sintattica e semantica
/* Dati in ingresso : sequenza v di n interi
	  Precondizione : n>0
   Dati in uscita 	: sequenza v1 di n interi
    Post-condizione : v1 è una permutazione di v,dove per ogni i in v risulta che v[i]<v[i+1]
	
	DIZIONARIO DEI DATI
	IDENTIFICATORE-TIPO-DESCRIZIONE
	v->array->sequenza di interi
	v1->array->sequenza di interi
	n->intero->dimensione della sequenza 
	i->intero->indice per scandire la sequenza
	j->intero->indice per scandire la sequenza
	max->intero-> indice del più grande valore di v nel range [0,dim-j]
	
	Complessità 
	Lavoro di combinazione lineare
	T(n)=T(n-h) + bn + d, n>h*/
		