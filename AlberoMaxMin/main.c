#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "btree.h"
#include "item.h"
#include "list.h"

int main() {
	BTree th,ta,tc,td,tl,tp,ts,to,tq;
	
	//Partiamo dal livello più basso
	to=buildTree(NULL,NULL,"o");
	tq=buildTree(NULL,NULL,"q");
	td=buildTree(NULL,NULL,"d");
	tl=buildTree(to,tq,"l");
	tp=buildTree(NULL,NULL,"p");
	ts=buildTree(NULL,NULL,"s");
	ta=buildTree(td,tl,"a");
	tc=buildTree(tp,ts,"c");
	th=buildTree(ta,tc,"h");
	
	printf("La visita in pre-order e':\n");
	preOrderIter(th);
	
	printf("\nLa visita in post-order e':\n");
	postOrderIter(th);
	
	printf("\nLa visita in in-order e':\n");
	inOrderIter(th);
	
	char max = getMax(th);
	printf("\nIl valore massimo e' :%c",max);
	
	char min = getMin(th);
	printf("\nIl valore minimo e' :%c",min);
	
	int h = height(th);
	printf("\nL'altezza dell'albero e' : %d",h);
	
	int num_Nodi = numNodi(th);
	printf("\nIl numero dei nodi e': %d",num_Nodi);
	
	printf("\nInserisci elemento da cercare: ");
	Item elemento = inputItem();
	
	if(ricercaEl(th,elemento))
		printf("Elemento trovato");
	else 
		printf("Elemento non trovato");
	
	printf("\nInserisci elemento da contare:");
	Item conta = inputItem();
	printf("\nElemento trovato %d volte",(conta,th)); 

	
	
	
	
	return 0;
}
	