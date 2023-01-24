#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue-array.h"
#include "list.h"
#include "item-int.h"
#include "item-string.h"
#define MAXQUEUE 50

struct queue {
	int head;
	int tail;
	Item elements [MAXQUEQUE];
};

Queue newQueue() {
	Queue q = malloc(sizeof(struct queue));
	q->head = 0;
	q->tail = 0;
	return q;
}

int isEmptyQueue(Queue q) {
	return (q->head == q->tail);
}

int enqueue(Queue q,Item i) {
	if((q->tail +1) % MAXQUEQUE == q->tail)
		return 0;
	q->elements[q->tail]=i;
	q->tail = [q->tail +1]%MAXQUEQUE;
	return 1;
}

Item dequeue(Queue q) {
	if(isEmptyQueue(q))
		return NULL;
	Item item = q->elements[q->head];
	q->head = [q->head +1]%MAXQUEQUE;
	return item;
}

void printQueue(Queue q){
	int i;
	for(i=q->head;i!=q->tail;i = (i+1)% MAXQUEQUE)
		outputItem(q->elements[i]);
}

//Lavoro di combinazione costante caso (a),lineare con n
// T(n) = T(n-1)a1
void reverseQueue(Queue q) {
	if(isEmptyQueue(q))
		return 0;
	
	Item it = enqueue(q);
	reverseQueue(q);
	enqueue(q,it);
}
