#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "utils.h"
#include "item-song.h"

struct list{
	int size;
	struct node *head;
	
};

struct node{
	Item item;
	struct node *next;
};

struct node *minimo(struct node *p);

List newList() {
	List list = malloc(sizeof(struct list));
	list->size=0;
	list->head=NULL;
	return list;
}

int isEmpty(List list){
	return list->head == NULL;
}

void addHead(List list, Item item){
	struct node *x = malloc(sizeof(struct node));
	x->next = list->head;
	x->item = item;
	list->head = x;
	list->size++;
}

Item getHead(List list){
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
		
	return list->head->item;
}

int sizeList(List list){
	return list->size;
}

void printList(List list){
	struct node *p;
	for(p = list->head; p != NULL; p = p->next)
		outputItem(p->item);
} 


void selectionSortList(List list) {
	struct node *p, *pos_minimo;
	for(p=list->head;p!=NULL;p=p->next) {
		pos_minimo=minimo(p);
		swap(&(pos_minimo->item),&(p->item));
	}
}

struct node *minimo(struct node *p) {
	struct node *i,*min=p;
	for(i=p;i!=NULL;i=i->next) {
		if(cmpItem(min->item,i->item)>0) 
			min=i;
	}
	return min;
}

Item removeListItem(List list, Item item) {
	struct node *prev,*p;
	
	
	if(isEmpty(list)==1) {
		return NULL;
	}
	
	for(p=list->head; p!=NULL, prev=p; p=p->next) {
		if(cmpItem(item,p->item)==0) {
			if(p==list->head) 
				return removeHead(list);
			else {
				prev->next = p->next;
				Item i=p->item;
				free(p);
				(list->size)--;
				return i;
			}
		}
	}
}

Item removeHead(List list) {
	if(isEmpty(list) == 1) {
		return 0;
	}
	struct node *temp=list->head;
	list->head=temp->next;
	Item app = temp->item;
	free(temp);
	(list->size)--;
	return app;
}

Item searchList(List list, Item item,int *pos){
	struct node *p;
	*pos=0;
    for (p=list->head; p != NULL; p = p-> next){
		if(cmpItem(item,p->item) == 0)
			return p->item;
		++*pos
		;
	}
	*pos=-1;
	return NULL;
}
	
