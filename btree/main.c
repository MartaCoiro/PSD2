#include <stdio.h>
#include "item.h"
#include "btree.h"
#include "queue.h"
#include "stack.h"

int main(){
    Item h,a,c,d,l,o,q,p,s;
	int b,i;
	
    
    h="h";a="a";c="c";d="d";l="l";o="o";q="q";p="p";s="s";
    
    BTree bto=buildTree(NULL,NULL,o);
    BTree btq=buildTree(NULL,NULL,q);
    BTree btp=buildTree(NULL,NULL,p);
    BTree bts=buildTree(NULL,NULL,s);
    BTree btd=buildTree(NULL,NULL,d);
    BTree btl=buildTree(bto,btq,l);
    BTree bta=buildTree(btd,btl,a);
    BTree btc=buildTree(btp,bts,c);
    BTree bth=buildTree(bta,btc,h);
    
    printf("La visita in preordine :");
    preOrder(bth);
    printf("\n");
    
    printf("La visita in postordine :");
    postOrder(bth);
    printf("\n");
    
    printf("La visita simmetrica :");
    inOrder(bth);
    printf("\n");
	
	b=height(bth);
	printf("L'altezza e':%d\n",b);
	
	i=numNodi(bth);
	printf("Numero di nodi e':%d\n",i);

	
	printf("La visita per livelli e':\n");
	byLevel(bth);
	printf("\n");
	
	printf("La visita in pre-ordine e':");
	preOrderIter(bth);
	printf("\n");
	
	printf("La visita in post-ordine e':");
	postOrderIter(bth);
	printf("\n");
	
	printf("La visita simmetrica e':");
	inOrderIter(bth);
	printf("\n");
	
	printf("Inserisci elemento da cercare:");
	Item e;
	e=inputItem();
	if(member(bth,e)) 
		printf("Trovato\n");
	else 
		printf("Non trovato\n");
	
	printf("Inserisci elemento da contare:");
	Item m;
	m=inputItem();
	printf("Trovato %d volte\n",conta_el(bth,m));
	
	
	
    
    
}

