#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"
//Implementazione stack con lista concatenata
struct stack {
	List elements;
};

Stack newStack() {
	Stack stack = malloc(sizeof(struct stack));
	stack->elements = newList();

	return stack;
}

int isEmptyStack(Stack s) {
	return (isEmpty(s->elements));
}

int push(Stack s, Item i) {
	addHead(s->elements, i);
	return 1;
}

int pop(Stack s) {
	if(removeHead(s->elements) == NULL)
		return 0;
	else
		return 1;
}

Item top(Stack s) {  
	return getHead(s->elements);
}

void printStack(Stack s) {
	printList(s->elements);
}
