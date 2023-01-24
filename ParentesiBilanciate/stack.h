#include "item.h"
typedef struct stack *Stack;

Stack newStack();
int isEmptyStack(Stack s);
int push(Stack s,Item i);
int pop(Stack s);
Item top(Stack s);
void printStack(Stack s);