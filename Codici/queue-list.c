#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue-list.h"
#include "list.h"
#include "item-int.h"
#include "item-string.h"

struct queue {
	List elements;
};

Queue newQueue() {
	Queue q = malloc(sizeof(struct queue));
	q->elements = newList();
	return q;
}

int isEmptyQueue(Queue q) {
	return isEmptyList(q->elements);
}

int enqueue(Queue q,Item i) {
	return addListTail(q->elements,i);
}

Item dequeue(Queue q) {
	return removeHead(q->elements);
}

void printQueue(Queue q){
	printList(q->elements);
}