#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queueStack.h"
#define MAXQUEUE 50

struct queue {
	Stack s1;
	Stack s2;	
};

Queue newQueue(Queue q) {
	Queue q = malloc(sizeof(struct queue));
	if(!q)
		return ;
	
	q->s1 = newStack();
	q->s2 = newStack();
	
	return q;
}

int isEmptyQueue(Queue q) {
	return isEmptyStack(q->s1);
}

int enqueue(Queue q, Item e) {
	return push(q->s1,e);
}

Item dequeue(Queue q) {
	Item i1;
	if(isEmptyQueue(q))
		return NULL;
	
	while(isEmptyStack(q->s1)) {
		i1= top(q-s1);
		pop(q->s1);
		if(!isEmptyStack(q->s1);
		push(q->s2,i1);
	}
	while(!isEmptyStack(q->s2)) {
		i2 = top(q->s2);
		pop(q->s2);
		push(q->s2,i1);
	}
	return i1;
}

void printQueue(Queue q) {
	printStack(q->s1);
}

List funzione( BTree bt,Item k) {
	List list = newList();
	Stack stack = newStack();
	push(stack,bt);
	
	while(!isEmptyStack(stack)) {
		BTree temp = pop(stack);
		if(!isEmptyQueue(temp->right)) 
			push(stack,temp->right);
		if(!isEmptyStack(temp->left)) 
			push(stack,temp->left)
		if(cmpItem(getBtreeRoot(temp),k)>0)
			addListTail(list,getBtreeRoot(temp));
}

void reverseQueue(Queue q) {
	if(isEmptyQueue(q))
		return ;
	
	Item it = dequeue(q);
	reverseQueue(q);
	enqueue(q,it);
}


List funzione(BTree bt, Item k ) {
	List list = newList();
	Stack stack = newStack();
	push(stack,bt);
	
	while(!isEmptyStack(stack)) {
		BTree temp = pop(stack);
	if(!isEmptyQueue(temp->right))
		push(stack,temp->right);
	if(!isEmptyStack(temp->left)
		push(stack,temp->left);
	if(cmpItem(getBtreeRoot(temp),k)<0)
		addListTail(list,getBtreeRoot(temp));
	}
}

void reverseQueue(Queue q) {
	if(isEmptyQueue(q))
		return;
	Item it = dequeue(q);
	reverseQueue(q);
	enqueue(q,it);
}

	