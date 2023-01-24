#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "list.h"
#include "item.h"

struct list{
	int size;
	struct node *head;
	
};

struct node{
	Item item;
	struct node *next;
	
};

List newList() {
	List list = malloc(sizeof(struct list));
	list->head = NULL;
	list->size = 0;
	return list;
}

int isEmptyList(List list) {
	return (list->size==0);
}

void addHead(List list,Item item) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->item = item;
	new_node->next = list->head;
	list->head = new_node;
	(list->size)++;
}

Item removeHead(List list) {
	if(isEmptyList(list))
		return 0;
	
	struct node *temp = list->head;
	list->head = temp->next;
	Item item = temp->item;
	free(temp);
	(list->size)--;
	return item;
}

Item getHead(List list) {
	if(isEmptyList(list)) 
		return NULL;
	return list->head->item;
}

void printList(List list) {
	struct node *p;
	for(p=list->head;p!=NULL;p=p->next) 
		outputItem(p->item);
}
	
		