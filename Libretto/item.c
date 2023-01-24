#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "esame.h"
#include "item.h"
#include "libretto.h"


Item inputItem(){
	char materia[20];
	char data[10];
	int voto;
	
	printf("\nMateria: ");
	fflush(stdin); //forza la scrittura dei dati bufferizzati sullo stream
	scanf("\n%[^\n]", materia);

	printf("Data: ");
	fflush(stdin);
	scanf("\n%[^\n]", data);

	printf("Voto: ");
	fflush(stdin);
	scanf("\n%d", &voto);

	return creaEsame(materia, data, voto);
}

void outputItem(Item item){
	Esame s = item;
	printf(" %s - %s -%d\n", materia(s),data(s),voto(s));


}

int cmpItem(Item item1, Item item2){
	Esame s1 = item1;
	Esame s2 = item2;
	return strcmp(materia(s1), materia(s2));
}