#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem() {
	int *p; //Dichiariamo un puntatore ad un item
	p = malloc(sizeof(int)); //Allochiamo la memoria
	scanf("%d",p); //Leggiamo il contenuto di p, gli passiamo l'indirizzo che è esattamente parsfnm
	return p;
}


void outputItem(Item i) {
	int *p=i;
	printf("%d ", *p);
}


int compareItem(Item i1, Item i2){
	int *p1=i1;
	int *p2=i2;
	return *p1 - *p2;
	
}