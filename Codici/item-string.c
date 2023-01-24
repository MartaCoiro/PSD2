#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item-string.h"
#define CARD 100

Item inputItem() {
	char *a = malloc(sizeof(char) *CARD);
	scanf("%s",a);
	return a;
}

void outputItem(Item item) {
	char *a = item;
	printf("%s",a);
	
}

void cmpItem(Item i1,Item i2) {
	char *a = i1;
	char *b = i2;
	return strcpy(a,b);
}

