#include "utils.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a=*b;
	*b=temp;
}

void swap(Item *a, Item *b) {
	Item temp = *a;
	*a = *b;
	*b = temp;
}