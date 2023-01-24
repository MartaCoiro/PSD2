#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack-list.h"
#include "list.h"

struct stack {
	List elements ;
};

Stack newStack() {
	Stack s = malloc(sizeof(struct stack));
	s->elements = newList();
	return s;
	
}

int isEmptyStack(Stack s) {
	return (isEmptyList(s->elements));
}

int push(Stack s ,Item i) {
	addHead(s->elements,i);
	return 1;
}

int pop(Stack s) {
	if (removeHead(s->elements)== NULL)
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