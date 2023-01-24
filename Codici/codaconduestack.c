#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue{
	Stack s1;
	Stack s2;
};

Queue newQueue() {
	Queue q = malloc(sizeof(struct queue));
	if(!q) 
		return NULL;
	
	q->s1 = newStack();
	q->s2 = newStack();
	
	return q;
}

int isEmptyQueue(Queue q) {
	return isEpmtyStack(q->s1);
}

int enqueque(Queue q,Item i) {
	return push(q->s1,i );
}

Item dequeue(Queue q) {
	while(isEmptyQueue(q))
		return NULL;
	
	while(!isEpmtyStack(q->s1)) {
		Item it = top(q->s1);
		pop(q->s1);
		if(!isEpmtyStack(q->s1))
			push(q->s2,it);
	}
	
	while(!isEpmtyStack(q->s2)) {
		Item it2 = top(q->s2);
		pop(q->s2);
		push(q->s1,it2);
	}
	return it;
}

void printQueue(Queue q) {
	printStack(q->s1);
}
