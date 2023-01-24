#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"
#include "stack.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BTree newTree(){
    return NULL;
}
int isEmptyTree(BTree t){
    if(t==NULL)
        return 1;
    else return 0;
}
BTree buildTree(BTree t1, BTree t2, Item i){
    BTree t=malloc(sizeof(struct node));
    t->value=i;
    t->left=t1;
    t->right=t2;
    
    return t;
}
Item getBTreeRoot(BTree t){
    if(isEmptyTree(t))
        return NULL;
    else return t->value;
}
BTree getLeft(BTree t){
    if(isEmptyTree(t))
        return NULL;
    else return t->left;
}
BTree getRight(BTree t){
    if(isEmptyTree(t))
        return NULL;
    else return t->right;
}
void preOrder(BTree t){
    if(t!=NULL){
        outputItem(t->value);
        preOrder(t->left);
        preOrder(t->right);
    }
}
void postOrder(BTree t){
    if(t!=NULL){
        postOrder(t->left);
        postOrder(t->right);
        outputItem(t->value);
    }
}
void inOrder(BTree t){
    if(t!=NULL){
        inOrder(t->left);
        outputItem(t->value);
        inOrder(t->right);
    }
}

int max(int a,int b) {
	return a>b ? a: b;
}

int height(BTree bt) {
	if(isEmptyTree(bt))
		return 0;
	else if(!getLeft(bt) && !getRight(bt))
		return 0;
	else 
		return 1+max(height(bt->left),height(bt->right));
}

int numNodi(BTree bt) {
	int count = 1;
	if(isEmptyTree(bt))
		return 0;
	else {
		if(!isEmptyTree(bt->left))
			count += numNodi(bt->left);
		if(!isEmptyTree(bt->right))
			count += numNodi(bt->right);
		return count ;
	}
}

void byLevel(BTree bt) {
	BTree left,right;
	Queue q = newQueue();
	enqueue(q,bt);
	while (!isEmptyQueue(q)) {
		BTree node = dequeue (q);
		outputItem(node->value);
		if((left=getLeft(node))!=NULL)
			enqueue(q,left);
		if((right=getRight(node))!=NULL)
			enqueue(q,right);
	}
}

//visita in pre-ordine dell'albero binario passato come parametro (versione iterativa)
void preOrderIter(BTree t) {
	BTree left,right;
	Stack s= newStack();
	
	push(s,t);
	while(!isEmptyStack(s)) {
		BTree node = top(s);
		pop(s);
		outputItem(node->value);
		if((right = getRight(node))!=NULL)
			push(s,right);
		if((left = getLeft(node))!=NULL)
			push(s,left);
	}
}

//visita in post-ordine dell'albero binario passato come parametro (versione iterativa)
void postOrderIter(BTree t) {
	BTree left,right;
	Stack s= newStack();
	
	do {
		while(t) {
			if(right =getRight(t))
				push(s,right);
			push(s,t);
			t=getLeft(t);
		}
		t=top(s);
		pop(s);
		if(getRight(t) && top(s) == getRight(t)) {
			pop(s);
			push(s,t);
			t=getRight(t);
		}
		else {
			outputItem(t->value);
			t=NULL;
		}
	}while(!isEmptyStack(s));
}

//visita simmetrica dell'albero binario passato come parametro (versione iterativa)
void inOrderIter(BTree t) {
	BTree left,right;
	BTree node=t;
	Stack s =newStack();
	int k=0;
	while(!k) {
		if(node !=NULL) {
			push(s,node);
			node =getLeft(node);
		}
		else {
			if(!isEmptyStack(s)) {
				node=top(s);
				pop(s);
				outputItem(node->value);
				node=getRight(node);
			}
			else
				k=1;
		}
	}
}

//Ricerca di un elemento 
int member(BTree t, Item e) {
	if(t == NULL) 
		return 0;
	else {
		if(t->value == 0) 
			return 1;
		
			else { 
				if(member(t->left,e)) 
					return 1;
			else 
				return member(t->right,e);
			}
	}
}

int conta_el(BTree t, Item e) {
	if( t == NULL) 
		return 0;
	else 
		if( e == t->value ) 
			return 1+ conta_el(e,t->left)
					+ conta_el(e,t->right);
		else 
			return conta_el(e,t->left)
					+ conta_el(e,t->right);
}