#include <stdio.h>
#include "item.h"
#include "btree.h"

int main(){
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
	
    
    printf("La visita in preordine :");
    preOrder(th);
    printf("\n");
    
    printf("La visita in postordine :");
    postOrder(th);
    printf("\n");
    
    printf("La visita simmetrica :");
    inOrder(th);
    printf("\n");
    
    
}

