#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "song.h"
#include "playlist.h"
#include "item-song.h"

Item inputItem() {
	char titolo[20];
	char nome_cantante[20];
	int durata;
	
	printf("\nInserisci il titolo della canzone:");
	fflush(stdin);
	scanf("\n%[^\n]", titolo);
	
	printf("Inserisci il nome del cantante:");
	fflush(stdin);
	scanf("\n%[^\n]", nome_cantante);
	
	printf("Inserisci la durata:");
	fflush(stdin);
	scanf("\n%d", &durata);
	
	return nuovaCanzone( titolo, nome_cantante, durata);
}

void outputItem(Item item) {
	Song s = item;
	printf("%s %s (%d sec.) \n", titolo(s), nome_cantante(s), durata(s));
}

int cmpItem(Item item1, Item item2){
	Song s1 = item1;
	Song s2 = item2;
	return strcmp(titolo(s1), titolo(s2));
}