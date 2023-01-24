#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"
#define N 30
//(4 + a) * {[1 –(2/x)] * (8 –a)}   è ben bilanciata
//[x –(4y + 3] * (1 –x))  non è ben bilanciata

int isOpen(char ch);
int isClosed(char ch);
int isCorresponding(char ch1,char ch2);
int isBalanced(char *exp);


int main() {
	char exp[N];
	printf("Inserisci l'espressione");
	scanf("%[^\n]",exp);
	
	if(isBalanced(exp))
		printf("L'espressione è ben bilanciata");
	else
		printf("L'espressione non è bilanciata");
	
	return 0;
	
}


int isOpen(char ch) {
	if(ch=='(' || ch=='[' || ch=='{')
		return 1;
	return 0;
}

int isClosed(char ch) {
	if(ch==')' || ch==']' || ch=='}')
		return 1;
	return 0;
}

int isCorresponding(char ch1,char ch2) {
	if((isOpen(ch1) && isClosed(ch2) && (ch2-ch1)==1 || (ch2-ch1)==2))
		return 1;
	return 0;
}

int isBalanced(char *exp) {
	Stack s = newStack();
	
	if(*exp=='\0')
		return 1;
	for(;*exp!='\0';exp++) {
		if(isOpen(*exp)) {
			Item item =exp;
			outputItem(item);
			push(s,item);
		}
		else if(isClosed(*exp)) {
			if(isEmptyStack(s))
				return 0;
			else {
				char *x=top(s);
				pop(s);
				if(!isCorresponding(*x,*exp))
					return 0;
			}
		}
	}
		return isEmptyStack(s);
}
	
	

