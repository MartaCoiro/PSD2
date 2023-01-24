#include <stdio.h>
#include "item.h"
#include "bst.h"

int main(){
	 BST t = newBST();
	 int a[]={20,10,30,15,5,25,40,3,6,35};
	 for(int i=0;i<sizeof(a)/sizeof(int);i++){
		 
		 Item item ;
		 insertBST(&t, &a[i]);
	
	
	printf("Min :");
	outputItem(min(t));
	
	Item m = max(t);
	printf("\nMax");
	outputItem(max(t));
	
	printf("Inserisci un item");
	m = inputItem();
	deleteBST(&t,m);
	printf("Cancellato nodo, minimo");
	m = min(t);
	outputItem(m);
	
	printf("Inserisci il valore da cercare :");
	Item e;
	e=inputItem();
	if(search(t,e)) 
		printf("Trovato\n");
	else 
		printf("Non trovato\n");
	}

	/*i = 10;
	Item it = &i;
	deleteBST(&t,it);
	printPerLevel(t);	*/
}