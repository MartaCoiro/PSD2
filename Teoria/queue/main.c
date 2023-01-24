#include <stdio.h>
#include "item.h"
#include "list.h"
#include "queue.h"

int main() {
     Queue q = newQueue();
     int i;
     for(i = 0; i < 5; i++) {
          if (!enqueue(q, inputItem()))
            fprintf(stderr,"Coda piena!\n");
          printQueue(q);
          printf("\n");
     }

     for(i = 0; i < 5; i++) {
          dequeue(q);
          printQueue(q);
          printf("\n");
     }

	return 0;
}
