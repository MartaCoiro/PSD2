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