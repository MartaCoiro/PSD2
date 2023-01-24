#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#define CARD 100

Item inputItem() {
	char *a;
	a=malloc(sizeof(char)*CARD);
	scanf("%s",a);
	return a;
}

void outputItem(Item item) {
	char *a=item;
	printf("%s",a);
}

int cmpItem(Item i1,Item i2) {
	char *p = i1;
	char *q = i2;
	return strcmp(p,q);
}


	