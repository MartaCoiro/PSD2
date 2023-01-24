#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"


Item inputItem() {
	int *p;
	p=malloc(sizeof(int));
	scanf("%d",p);
	return p;
}

void outputItem(Item item) {
	int *p=item;
	printf("%d",*p);
}

void cmpItem(Item i1,Item i2) {
	int *p = i1;
	int *q = i2;
	return *p-*q;
}