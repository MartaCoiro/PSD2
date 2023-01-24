#include <stdio.h>
#include <stdlib.h>
#include "esame.h"
#include <string.h>
#include "item.h"

Item inputItem(){
	char materia[20];
	char data[20];
	int voto;
	
	printf("\nMateria: ");
	fflush(stdin); //forza la scrittura dei dati bufferizzati sullo stream
	scanf("%[^\n]", materia);

	printf("Data: ");
	fflush(stdin);
	scanf("%[^\n]", data);

	printf("Voto: ");
	fflush(stdin);
	scanf("%d", &voto);

	return initEsame(materia, data, voto);
}

void outputItem(Item item){
	Esame s = item;
	printf("\n%s %s %d ", materia(s), data(s), voto(s));
}

int cmpItem(Item item1, Item item2){
	char *s1 = item1;
	Esame s2 = item2;
	return strcmp(s1, materia(s2));
}
