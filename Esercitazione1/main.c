#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "vettore.h"
#define N 10

int main() {
	int a[N],n;
	
	printf("Quanti elementi vuoi inserire?");
	scanf("%d",&n);
	inputArray(a,n);
	selection_sort_max(a,n);
	outputArray(a,n);
	
	
	
	return 0;
}