#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

struct list{
	int size;
	struct node *head;
	struct node *tail;
};

struct node{
	Item item;
	struct node *next;
};

List newList() {
	List list = malloc(sizeof(struct node));
	list->head= NULL;
	list->tail=NULL;
	list->size =0;
	return list;
}

int isEmpty(List list) {
	return (list->size==0);
}

void addHead(List list, Item item) {
	struct node *new = malloc(sizeof(struct node));
	new->item=item;
	new->next=list->head;
	list->head= new;
	++(list->size);
}

Item removeHead(List list) {
	if(isEmpty(list))
		return 0;
	struct node *temp = list->head;
	list->head = temp->next;
	Item item = temp->item;
	free(temp);
	--(list->size);
	return item;
}

Item getHead(List list) {
	if(isEmpty(list))
		return 0;
	return list->head->item;
}

int sizeList(List list) {
	return list->size;
}

void printList(List list) {
	struct node *p;
	for(p=list->head;p!=NULL;p=p->next)
		outputItem(p->item);
}

void addListTail(List list,Item item) {
	struct node *new = malloc(sizeof(struct node));
	new->next = NULL;
	new->item = item;
	if((list->size)==0)
		list->head = new;
	else 
		list->tail->next=new;
	list->tail=new;
	(list->size)++;
	//return 1;
}
