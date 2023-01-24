#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAX_QUEUE 100
//Implementazione con array circolare
struct queue {
	int head;
	int tail;
	Item elements[MAX_QUEUE];
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

int enqueue(Queue q, Item i) {
	if ((q->tail + 1) % MAX_QUEUE == q->head) //Condizione in cui la coda è piena
		return 0;
	//Se la coda non è piena andiamo ad inserire gli elementi 
	q->elements[q->tail] = i;
	q->tail = (q->tail + 1) % MAX_QUEUE; //Facciamo il modulo perchè riempiamo in modo circolare perchè quando arriva alla fine deve ritornare all'inizio
	return 1;
}

Item dequeue(Queue q) {
	if (isEmptyQueue(q))
		return NULL;
	//Salviamo l'item e lo facciamo avanzare di uno
	Item item = q->elements[q->head];
	q->head = (q->head + 1) % MAX_QUEUE;
	return item;
}

void printQueue(Queue q) {
	int i;
	//Stampiamo da head fino alla casella prima di tail
	for (i = q->head; i != q->tail; i = (i + 1) % MAX_QUEUE)
		outputItem(q->elements[i]);
}
