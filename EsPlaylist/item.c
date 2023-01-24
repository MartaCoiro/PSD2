#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "playlist.h"
#include "song.h"
#include "item.h"


Item inputItem() {
	char title[20];
	char artist[20];
	int duration;
	
	printf("Inserisci il titolo della canzone :");
	fflush(stdin);
	scanf("\n%[^\n]",title);
	
	printf("Inserisci il nome del cantante :");
	fflush(stdin);
	scanf("\n%[^\n]",artist);
	
	printf("Inserisci la durata : ");
	fflush(stdin);
	scanf("%d", &duration);
	
	return creaSong(title,artist,duration);
}

void outputItem(Item item) {
	Song s = item;
	printf("%s %s (%d sec.)\n",title(s),artist(s),duration(s));
}

int cmpItem(Item i1,Item i2) {
	Song s1= i1;
	Song s2= i2;
	return strcmp(title(s1),title(s2));
}
	
	
	
	
	