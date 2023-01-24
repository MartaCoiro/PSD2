#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item-int.h"
#include "item-string.h"
#include "item-generic.h"

void inputArray(int *a,int n) {
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void inputArray(Item a[],int n) {
	int i;
	for(i=0;i<n;i++) 
		a[i]=inputItem();
}

void outputArray(int *a,int n) {
	int i;
	for(i=0;i<n;i++) 
		printf("%d",a[i]);
}

void outputArray(Item a[],int n) {
	int i;
	for(i=0;i<n;i++) 
		outputItem(a[i]);
}

void selectionSort(int *a,int n) {
	int i,m;
	for(i=0;i<n-1;i++) {
		m=min(a+1,n-i)+i;
		swap(&a[i],&a[m]);
	}
}

void selectionSortItem(Item *a,int n) {
	int i,m;
	for(i=0;i<n-1;i++) {
		m=min(a+1,n-i)+i;
		swap(&a[i],&a[m]);
	}
}

int minimo(int *a,int n) {
	int i,min=0;
	for(i=1;i<n;i++)
		if(a[i]<a[min])
			min=i;
		return min;
}

void selectionSortMax(int a[],int n) {
	int max=0,i,j;
	for(j=o;j<n=j++) {
		for(i=0,max=0;i<n-j;i++)
			if(a[i]>a[max])
				max=i;
			swap(&a[max],&a[n-j-1]);
	}
}

//Specifica sintattica e semantica
/*Dati in ingresso : sequenza v di n interi
   Precondizione   : n>0
  Dati in usicta   : sequenza v1 di n interi
   Post-condizione : v1 è una permutazione di v dove per ogni i in v, v[i]<v[i+1]
   
   DIZIONARIO DEI DATI
   IDENTIFICATORE-TIPO-DESCRIZIONE
   v->array->array in ingresso
   v1->array->array in uscita
   n->intero->dimensione della sequenza 
   i->intero->indice per scandire la sequenza
   j->intero->indice per scandire la sequenza
   max->intero->indice del più grande valore di v nel range [0,n-j]
   
   COMPLESSITA' 
   Lavoro di combinazione lineare T(n)=T(n-h)+bn+d,n>1 */
   

void insertSortedArray(int *array,int *size,int element) {
	int i;
	for(i=*size;i>0;i--)
		if(element<array[i]) 
			array[i]=array[i-1];
		else
			break;
		array[i]=element;
		size+=1;
}

void insertionSort(int *a,int n) {
	int i;
	for(i=1;i<size;)
		insertSortedArray(array,&i,array[i]);
}

void bubbleSort(int *array,int n) {
	int i,j;
	for(i=1;i<n;i++) {
		for(j=0;j<n-1;j++)
			if(array[j]>array[j+1])
				swap(&array[j],&array[j+1])
	}
}

void bubbleSortAdaptive(int *a,int n) {
	int i,j,contatore=0,ordinato=0;
	for(i=1;i<n && !ordinato ;i++) {
		ordinato=1;
		for(j=0;j<n-1;j++) {
			contatore++;
			if(array[j]>array[j+1]) {
				ordinato=0;
				swap(&array[j],&array[j+1])
			}
		}
	}
	return contatore;
}

int ricercaBinaria(int *array,int n,int element) {
	int inizio=0,centro,fine=n-1;
	
	while(fine>=inizio) {
		centro=(inizio+fine)/2;
		
		if(element==array[centro])
			return centro;
		else if(element<array[centro])
			fine = centro-1;
		else if(element>array[centro])
			inizio = centro+1;
	}
	return -1;
}

//Complessità computazionale
/* T(n)=T(n/2)+c 
lavoro di combinazione costante con partizionamento dei dati,caso 1.b*/

int ricercaBinariaRic1(int *array,int inizio,int fine,int k) {
	int centro;
	if(inizio>fine) 
		return -1;
	else {
		centro=(inizio+fine)/2;
		if(k==array[centro])
			return centro;
		else if(k<array[centro])
			return ricercaBinariaRic1(array,inizio,centro-1,k);
		else if(k>array[centro])
			return ricercaBinariaRic1(array,fine,centro+1,k);
	}
	
}

int ricercaBinariaRic(int *array,int size,int k) {
	return ricercaBinariaRic1(array,0,size-1,k);
}

//Complesssità ,lavoro di combinazione lineare,quadratico con n,n>1
/* T(n) = T(n-1) +bn +d, n>1 */
void selectionSortRicorsivo(Item a[],int n) {
	if(n==1)
		return 0;
	int min = minimo(a+1,n-1)+1;
	if(cmpItem(a[min],a[0])<0)
		swap(&a[0],&a[min]);
	selectionSortRicorsivo(a+1,n-1);
}

int min(Item *a,int n) {
	int i,min=0;
	for(i=0;i<n;i++) {
		if(cmpItem(a[i],a[min])<0)
			min = i;
		return min;
}



	







			
		
	
		

		
			



