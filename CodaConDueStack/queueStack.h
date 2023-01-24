#include "stack.h"

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
int enqueue(Queue , Item);
Item enqueue (Queue);
void printQueue(Queue);