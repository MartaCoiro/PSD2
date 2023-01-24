#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define NCHAR 20 

Item inputItem() {
	char *p; //Dichiariamo un puntatore ad un item
	p = malloc(NCHAR * sizeof(char)); //Allochiamo la memoria, possiamo scrivere fino a 19 caratteri perchè l'ultimo è quello di fine riga
	scanf("%s",p); //Leggiamo il contenuto di p, gli passiamo l'indirizzo che è esattamente parsfnm
	return p;
}


void outputItem(Item i) {
	char *p=i;
	printf("%s ", p);
}


int compareItem(Item i1, Item i2){
	char *p1=i1;
	char *p2=i2;
	return strcmp(p1,p2);
	
}