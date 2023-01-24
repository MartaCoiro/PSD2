#include <stdio.h>
#include <stdlib.h>
#include <string-h>
#include "item.h"
#include "song.h"

Item inputItem(){
	char title[20];
	char artist[20];
	int duration;
	printf("\nTitle: ");
	fflush(stdin); //forza la scrittura dei dati bufferizzati sullo stream
	scanf("%[^\n]", title);

	printf("Artist: ");
	fflush(stdin);
	scanf("%[^\n]", artist);

	printf("Duration: ");
	fflush(stdin);
	scanf("%d", &duration);

	return initSong(title, artist, duration);
}

void outputItem(Item item){
	Song s = item;
	printf("\n%s - %s (%d sec.)", artist(s), title(s), duration(s));
}

int cmpItem(Item item1, Item item2){
	Song s1 = item1;
	Song s2 = item2;

	return strcmp(title(s1), title(s2));
}

Item cloneItem (Item item){}
