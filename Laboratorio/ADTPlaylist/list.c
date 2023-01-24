#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "utils.h"


struct list {
	int size;
	struct node *head;
};

struct node {
	Item item;
	struct node *next;
};

struct node * minimo (struct node *p);

List newList(){
	
	List list = malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	
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

Item removeHead(List list){
	Item app;
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}	
	struct node *temp = list->head;
	list->head = temp->next;
	app=temp->item;
	free(temp);
	list->size--;
	return app;
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

void bubbleSortList(List list){//antonioZizzari_sort
	struct node *p,*s;
	for(p=list->head;p!=NULL;p=p->next)
		for(s=p->next;s!=NULL; s=s->next)
			if(cmpItem(p->item,s->item)>0)
				swap(&(p->item),&(s->item));
}

void selectionSortList(List list){
	struct node *p, *pos_minimo;
	for (p=list->head; p != NULL; p = p-> next){
		pos_minimo = minimo(p);
		swap(&(pos_minimo->item), &(p->item));
	}
}

struct node * minimo (struct node *p){
	struct node *i, *min = p;
	for (i = p; i != NULL; i = i->next){
		if ((cmpItem(min->item, i->item)) > 0)
			min = i;
	}
	return min;
}


Item searchList(List list, Item item, int *pos){
	struct node *p;
	*pos=0;
    for (p=list->head; p != NULL; p = p-> next){
		if(cmpItem(item,p->item) == 0)
			return p->item;
		++*pos;
	}
	*pos=-1;
	return NULL;
}


Item removeListItem(List list, Item item){
	struct node *prev, *p;
	Item i;
	
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
	
	for (p=list->head; p != NULL; prev = p, p = p-> next){
		if(cmpItem(item,p->item) == 0) {
			if(p == list->head)
				return removeHead(list);
			else {
				prev->next = p->next;
				i = p->item;
				free(p);
				list->size--;
				return i;
			}
		}
	}
	
	return NULL;
}

Item removeListItemPos(List list, int pos){
	struct node *prev, *p;
	Item i;
	int j;
	
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
	j = 0;
	for (p=list->head; p != NULL; prev = p, p = p-> next, j++){
		if(j==pos) {
			if(pos == 0)
				return removeHead(list);
			else {
				prev->next = p->next;
				i = p->item;
				free(p);
				list->size--;
				return i;
			}
		}
	}
	
	return NULL;
}

int addListItem(List list, Item item, int pos){
	if (pos == 0)
	{
		addHead(list, item);
		return 1;
	}
	if (pos > sizeList(list))
		return 0;
	struct node *p;
	int i;
	for (p = list -> head, i = 0; p; i++, p = p -> next)
	{
		if (i == pos-1)
		{
			struct node *new = malloc(sizeof(struct node));
			new -> next = p -> next;
			p -> next = new;
			new -> item = item;
			list -> size++;
			return 1;
		}
	}
	return 0;
} // 0 <= pos <= sizeList(list)

int addListTail(List list, Item item)
{
	return addListItem(list, item, sizeList(list));
}

void reverseList(List list)
{
	struct node *prev=NULL;
	struct node *p;
	struct node *temp;
	for(p=list->head;p;prev=p,p=temp)
	{
		temp= p->next;
		p->next=prev;
	}
	list->head=prev;
}

List cloneList(List list)
{
	List clone= newList();
	struct node *p;
	for (p = list -> head; p; p = p -> next)
	{
		Item item=cloneItem(p->item);
		addListTail(clone,item);
	}
	return clone;
}