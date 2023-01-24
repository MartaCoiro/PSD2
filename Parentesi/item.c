#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item inputItem() {
	int *p=malloc(sizeof(int));
	scanf("%d",p);
	return p;
	
}

void outputItem(Item i) {
	int *p=i;
	printf("%d",*p);
}

int cmpItem(Item item1, Item item2) {
	int *p1=item1,*p2=item2;
	
	return *p1-*p2;
	
}