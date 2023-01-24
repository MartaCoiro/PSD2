#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "item-int.h"

struct list {
	int size;
	struct node *head;
	
};

struct node {
	Item value;
	struct node *next;
	struct node *prev; //serve per la reverseListRec
	struct node *tail;
};

List newList() {
	List list = malloc(sizeof(struct node));
	list->size=0;
	list->head=NULL;
	list->tail=NULL;
	return list;
	
}

int isEmptyList(List list) {
	return (list->size==0);
}

void addHead(List list ,Item item) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->item=item;
	new_node->next=list->head;
	list->head=new_node;
	++(list->size);
}

Item removeHead(List list) {
	if(isEmptyList(list))
		return NULL;
	struct node *temp = list->head;
	list->head=temp->next;
	Item item = temp->item;
	free(temp);
	--(list->size);
	return item;
}

Item removeHeadOttimizzata(List list) {
	if(isEmptyList(list)==1)
		return NULL;
	struct node *temp= malloc(sizeof(struct node));
	Item app;
	list->head=temp->next;
	app=temp->item;
	free(temp);
	--(list->size);
	if(list->size ==0) 
		list->tail= NULL;
	return app;
	
}

Item getHead(List list) {
	if(isEmptyList(list))
		return NULL;
	return list->head->item;
}

int sizeList(List list) {
	return list->size;
}

void printListIter(List list ) {
	struct node *p;
	for(p=list->head;p!=NULL;p=p->next) 
		outputItem(p->item);
}

void printRec(struct node *p) {
	if(p!=NULL) {
		outputItem(p->item);
		printRec(p->next);
	}
}

void printConRec(List list) {
	return printRec(list->head);
}

Item searchList(List list,Item item, int *pos) {
	struct node *p; // = searchRic(list->head,item,pos); richiamo alla ricorsiva 
	for(*pos=0,p=list->head;p!=NULL;p=p->next) {
		if(cmpItem(item,p->item)<0) {
			return p->item;
		}
		(*pos)++;
	}
	*pos=-1;
	return NULL;
}

Item searchRic(struct node *p,Item item,int *pos) {
	if(p!=NULL) {
		if(cmpItem(item,p->item)==0)
			return cloneItem(p->item);
		else {
			(*pos)++;
			searchRic(p->next,item,pos);
		}
	}else {
		return NULL;
	}
}

Item removeListItem(List list,Item item) {
	if(isEmptyList(list))
		return NULL;
	struct node *p,*q;
	Item a; 
	
	for(p=list->head;p!=NULL; q=p,p=p->next) {
		if(cmpItem(item,p->item)) ==0) {
			if(p==list->head) 
				return removeHead(list);
			else {
				q->next=p->next;
				a=p->next;
				free(p);
				(list->size)--;
				return a;
			}
		}
	}
	return NULL;
}

Item removeListPos(List list,int pos) {
	if(isEmptyList(list))
		return NULL;
	struct node *p,*q;
	int i;
	Item a;
	
	for(i=0,p=list->head;p!=NULL;q=p,p=p>next,i++) {
		if(i==pos) {
			if(p==list->head) 
				return removeHead(list);
			else {
				q->next=p->next;
				a=p->next;
				free(p);
				(list->size)--;
				return a;
			}
		}
	}
	return NULL;
}

int addListItem(List list, Item item, int pos) {
	if(pos<0 || pos>list->size) 
		return 0;
	if(pos==0)  {
		addHead(list,item);
		return 1;
	}
	
	struct node *p;
	struct node *new = malloc(sizeof(struct node));
	int count =0;
	
	for(p=list->head;p!=NULL && count<pos-1; p=p->next,count++) 
		;
		new->item = item;
		new->next = p->next;
		p->next = new;
		(list->size)++;
		return 1;
	}

int addListTail(List l,Item i) {
	return addListItem(l,i,l->size);
}

void addListTailOttimizzata(List list,Item item) {
	struct node *new = malloc(sizeof(struct node));
	new->next= NULL;
	new->item = item;
	
	if((list->size)==0)
		list->head = new;
	else
		list->tail->next = new;
	list->tail=new;
	(list->size)++;
	return 1;
}

void reverseListIter(List list ) {
	struct node *p;
	struct node *prev=NULL;
	struct node *temp;
	
	for(p=list->head;p!=NULL;p=p->next) {
		temp = p->next;
		p->next = prev;
	}
	list->head=prev;
}

void reverseListRec(struct node *head,struct node *tail) {
	if(head!=tail) {
		swap(head->item,tail->item);
		
		if(head->item!=tail) 
			reverseListRec(head->next,tail->prev);
	}
}

void reverseListConRec(List list) {
	if(!isEmptyList(list))
		reverseListRec(list->head);
}

void cloneListIter(List list ) {
	List clone = newList();
	struct node *p;
	
	for(p=list->head;p!=NULL;p=p->next) {
		Item item = cloneItem(p->item);
		addListTail(clone,item);
	}
	return clone;
}

void cloneListRic(struct node *p,List clone) {
	if(p!=NULL) {
		Item item = cloneItem(p->item);
		addListTail(clone,item);
		cloneListRic(p->next,clone);
	}
}

void cloneListConRic(List list)  {
	List clone = newList();
	cloneListRic(list->head,clone);
	return clone;
}