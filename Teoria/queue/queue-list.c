#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"
//Implementazione con lista
struct queue {
	List elements;
};

Queue newQueue(){
	Queue q = malloc(sizeof(struct queue));
	q->elements = newList(); //Inizializziamo la coda
	return q;
}

int isEmptyQueue(Queue q){ //La coda è vuota quando la lista di elementi è vuota
	return isEmpty(q->elements);
}

int enqueue(Queue q, Item i){
	return addListTail(q->elements, i);
}

Item dequeue(Queue q) {
	return removeHead(q->elements);
}

void printQueue(Queue q){
	printList(q->elements);
}
