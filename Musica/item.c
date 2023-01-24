#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "songs.h"
#include "playlist.h"


Item inputItem() {
	char titolo[20];
	char cantante[20];
	int durata;
	
	printf("Inserisci titolo : \n");
	fflush(stdin);
	scanf("%[^\n]",titolo);
	
	printf("Inserisci cantante :");
	fflush(stdin);
	scanf("%[^\n]",cantante);
	
	printf("Inserisci durata : \n");
	fflush(stdin);
	scanf("%d",durata);
	
	return creaSong(titolo,cantante,durata);
}

void outputItem(Item item) {
	Song s = item;
	printf("%s %s %d \n",titolo(s),cantante(s),durata(s));
}

int cmpItem(Item i1,Item i2) {
	Song s1 = i1;
	Song s2 = i2;
	return strcmp(titolo(s1),titolo(s2));
}


	
	