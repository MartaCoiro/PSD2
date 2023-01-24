#include <stdio.h>
#include "item.h"
#include "list.h"
#include "stack.h"

int main() {
     Stack s = newStack();
     int i;
	 Item e;
     
     for(i = 0; i < 5; i++) {
		 e = inputItem();
          push(s, e);
          printStack(s);
          printf("\n");
     }

     for(i = 0; i < 5+1; i++) {
		 printf("Elemento top: ");
		 e=top(s);
		 if(e) { //Se è diverso da null
			printf("Elemento top: ");
			outputItem());
		 }
          pop(s);
          printStack(s);
          printf("\n");
     }

	return 0;
}
