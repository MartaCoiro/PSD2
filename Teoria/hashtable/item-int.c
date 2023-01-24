#include "item.h"
#include <stdlib.h>
#include <stdio.h>

Item inputItem(){
	
	int *p=malloc(sizeof(int));
	scanf("%d",p);
	return p;
}

void outputItem(Item item){
	int *p=item;
	printf("%d ",*p);
}

/*int cmpItem(Item item1,Item item2){
	int *p1=item1,*p2=item2;
	
	return *p1-*p2;	
}*/

Item cloneItem (Item item)
{
	int *p = malloc (sizeof (int));
	int *q = item;
	*p = *q;
	return p;
}