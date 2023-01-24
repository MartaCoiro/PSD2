#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item-int.h"

Item inputItem() {
	int *p= malloc(sizeof(struct node));
	scanf("%d",p);
	return p;
}

void outputItem(Item item) {
	int *p = item;
	printf("%d",*p);
}

void cmpItem(Item i1,Item i2) {
	int *p = i1;
	int *q = i2;
	return *p1-*p2;
}

void cloneItem(Item item) {
	int *p = malloc(sizeof(struct node));
	int *q = item;
	*p = *q;
	return p;
}
