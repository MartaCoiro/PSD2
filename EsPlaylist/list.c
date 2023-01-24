#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "utils.h"

struct list {
	int size;
	struct node *head;
};

struct node {
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

int isEmptyList(List list) {
	return (list->size==0);
}

void addHead(List list, Item item) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->item = item;
	new_node->next=list->head;
	list->head=new_node;
	++(list->size);
}

Item removeHead(List list) {
	if(isEmptyList(list))
		return NULL;
	struct node *temp=list->head;
	list->head=temp->next;
	Item item = temp->item;
	free(temp);
	--(list->size);
	return item;
}

Item getHead(List list) {
	if(isEmptyList(list)) 
		return NULL;
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

Item searchList(List list, Item item, int *pos) {
	struct node *p;
	for(*pos=0,p=list->head;p!=NULL;p=p->next) {
		if(cmpItem(item,p->item)==0) {
			return p->item;
		}
		(*pos)++;
	}
	(*pos)=-1;
	return NULL;
}

Item removeListItem(List list, Item item) {
	struct node *p,*q;
	Item a;
	
	if(isEmptyList(list))
		return NULL;
	for(p=list->head;p!=NULL;p=q,p=p->next) {
		if(cmpItem(item,p->item)==0) {
			if(p==list->head) 
				return removeHead(list);
		
			else {
					q->next=p->next;
					a=p->item;
					free(p);
					(list->size)--;
					return a;
			}
		}
	}
}

Item removeListPos(List list,int pos) {
	struct node *p,*q;
	Item a;
	int i=0;
	
	if(isEmptyList(list))
		return NULL;
	
	for(i=0,p=list->head;p!=NULL,p=q;p=p->next,i++) {
		if(i==pos) {
			if(p==list->head)
				return removeHead(list);
			
			else {
				q->next=p->next;
				a=p->item;
				free(p);
				(list->size)--;
				return a;
			}
		}
	}
}

int addListItem(List list,Item item,int pos) {
	if(pos<0 || pos>list->size) 
		return 0;
	if(pos==0) {
		addHead(list,item);
		return 0;
	}
	
	struct node *p,*new;
	int conta=0;
	
	for(p=list->head;p!=NULL && conta<pos-1;p=p->next,conta++) {
		;
	new=malloc(sizeof(struct node));
	new->item = item;
	new->next=p->next;
	p->next=new;
	(list->size)++;
	return 1;
	}
}

int addListTail(List list,Item i) {
	return addListItem(list,i,list->size);
}

void reverseList(List list) {
	struct node *prev=NULL;
	struct node *p;
	struct node *temp;
	
	for(p=list->head;p!=NULL;p=p->next) {
		temp=p->next;
		p->next=prev;
	}
	list->head=prev;
}

/*void cloneList(List list) {
	List clone = newList();
	struct node *p;
	
	for(p=list->head;p!=NULL;p=p->next) {
		Item item = cloneItem(p->item);
		outputItem(clone,item);
	}
	return clone;
}*/

void selectionSortList(List list) {
	struct node *p,*pos_minimo;
	
	for(p=list->head;p!=NULL;p=p->next) {
		pos_minimo=minimo(p);
		swap(&(pos_minimo->item),&(p->item));
	}
}

struct node *minimo(struct node *p) {
	struct node *i,*min=p;
	
	for(i=p;i!=NULL;i=i->next) {
		if(cmpItem(min->item , i->item)>0)
			min=i;
	}
	return min;
}
		
		
	
	