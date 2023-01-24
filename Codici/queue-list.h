typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue q);
int enqueue(Queue q,Item i) ;
Item dequeue(Queue q) ;
void printQueue(Queue q);