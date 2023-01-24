#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"
#include "esame.h"
#include "item.h"
#include "list.h"
#include "utils.h"
#define MAX 50

Item inputItem() {
	char *materia[20];
	char *data[20];
	int voto;
	
	printf("Inserisci materia:\n");
	fflush(stdin);
	scanf("[^\n]",materia);
	
	printf("Inserisci data:\n");
	fflush(stdin);
	scanf("[^\n],data);
	
	printf("Inserisci voto");
	fflush(stdin);
	scanf("%d\n",voto);
	
	return creaEsame(materia,data,voto);
	
}

void outputItem(Item item) {
	Esame e = item;
	printf("%s %s %d \n",materia(e),data(e),voto(e));
}

int cmpItem(Item i1,Item i2) {
	Esame e1 = i1;
	Esame e2 = i2;
	return strcpy(materia(e1),materia(e2));
}