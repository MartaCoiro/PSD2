#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAXSTACK 50

//Implementazione stack con array
struct stack {
	Item elements[MAXSTACK];
	int top;
};

Stack newStack() {
	Stack stack = malloc(sizeof(struct stack));
	stack->top = 0;
	return stack;
}

int isEmptyStack(Stack s) {
	return (s->top == 0);
}

int push(Stack s, Item i) {
	if(s->top < MAXSTACK) {
		s->elements[s->top] = i;
		++(s->top);
		return 1;
	} else
		return 0;
}

int pop(Stack s) {
	if(isEmptyStack(s))
		return 0;
	else {
		--(s->top);
		return 1;
	}
}

Item top(Stack s) { ////Facciamo prima top per leggere l'elemento da cancellare e poi facciamo la pop cioè l'eliminazione
	if(isEmptyStack(s))
		return NULL;
	else
		return s->elements[(s->top) - 1];
}

void printStack(Stack s) {
	int i;
	for(i = s->top - 1; i >= 0; i--)
		outputItem(s->elements[i]);
}
