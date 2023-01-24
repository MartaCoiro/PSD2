#include <stdio.h>
#include "item.h"
#include "list.h"

int main() {
    List l = newList();
    int n=5,i;
    Item item;
	Item prova;
	int pos;
    for (i=0;i<n;++i) {
        item=inputItem();
        addListTail(l,inputItem());
    }
	printf("La taglia della lista e' %d \n", sizeList(l));
	printList(l);
	
	reverseList(l); //Fa il reverse della lista
	/*printf("\n");
	printf("Rimosso il nodo");
	outputItem(removeHead(l));
	printf("Rimosso il nodo");
	outputItem(removeHead(l));
	printf("Rimosso il nodo");
	outputItem(removeHead(l));
	printf("\n");
	printList(l);*/
	
	printf("\n");
	printf("inserisci posizione: ");
	scanf("%d", &pos);
	printf("inserisci item: ");
	item=inputItem();
	addListItem(l,item,pos);
	//removeListItemPos(l,pos);
	printList(l);
	return 0;
}