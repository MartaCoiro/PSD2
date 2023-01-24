#include <stdio.h>
#include "item.h"
#include "list.h"

int main() {
 	List A = newList();
	int n=5, i, pos;
	Item s;
	printf("Inserire la lista \n");
	for (i=0; i<n; i++)
		addHead(A, inputItem());

	printList(A);
	printf("\nInserire l'item da inserire e la posizione: \n");
	s=inputItem();
	scanf("%d",&i);
	addListItem(A, s, i);
	printList(A);

	/*List B = cloneList(A);
	printf("Clone non ordinato\n");
	printList(B);
  printf("Clone ordinato\n");
  sortList(B);
  printList(B);
  printf("Clone invertito\n");
  reverseList(B);
  printList(B);

  printf("\nInserire l' item da cercare: ");
	s=inputItem();
  if(searchList(B, s, &pos) == NULL) {
    printf("Elemento non trovato\n");
  } else {
    printf("Elemento trovato alla posizione %d\n", pos);
  }*/

  return 1;
}
