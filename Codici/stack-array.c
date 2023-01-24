#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack-array.h"
#include "list.h"
#include "item-int.h"
#include "item-string.h"
#define MAXSTACK 50

struct stack {
	Item elements [MAXSTACK];
	int top;
};

Stack newStack() {
	Stack s = malloc(sizeof(struct stack));
	s->top=0;
	return s;
}

int isEmptyStack(Stack s) {
	return (s->top==0);
}

int push(Stack s ,Item i) {
	if(s->top <MAXSTACK) {
		s->elements[s->top]=i;
		++(s->top);
		return 0;
	}
	else
		return 1;
}

Item pop(Stack s) {
	if(isEmptyStack(s))
		return 0;
	else {
		--(s->top);
		return 1;
	}
}

Item top(Stack s) {
	if(isEmptyStack(s))
		return 0;
	else return s->elements[(s->top)-1];
}

void printStack(Stack s) {
	int i;
	for(i=s->top-1;i>=1;i--)
		outputItem(s->elements[i]);
}