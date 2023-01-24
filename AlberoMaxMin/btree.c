#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "btree.h"
#include "item.h"
#include "list.h"


struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BTree newTree(){ //Creiamo un bTree vuoto
    return NULL;
}
int isEmptyTree(BTree t){
    if(t==NULL)
        return 1;
    else return 0;
}
BTree buildTree(BTree t1, BTree t2, Item i){
    BTree t=malloc(sizeof(struct node));
    t->value=i; //Memorizziamo i dati sul nodo
    t->left=t1; //Colleghiamoo il sottoalbero sinistro
    t->right=t2; //Colleghiamo il sottoalbero destro
    
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
/*void preOrder(BTree t){
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
}*/

int maxC(char a,char b,char c) {
	return a>b ? (c>a ? c:a) :(c>b ? c:b) ;
}
char getMax(BTree t) {
	if(isEmptyTree(t)) 
		return -1;
		
	char max_dx,max_sx;
	char *p = t->value;
	
	max_sx = getMax(getLeft(t));
	max_dx = getMax(getRight(t));
	
	return maxC(max_sx,max_dx,*p);
	
}

int min(char a,char b, char c) {
	a<b ? (c<a ? c:a) : (c<b ? c:b);
}

char getMin(BTree t) {
	if(isEmptyTree(t))
		return -1;
	
	char max_dx,max_sx;
	char *p = t->value;
	
	max_sx = getMin(getLeft(t));
	max_dx = getMin(getRight(t));
	
	return (max_sx,max_dx,*p);
}

int height(BTree t) {
	if(isEmptyTree(t))
		return 0;
	else if(!getLeft(t) && !getRight(t))
		return 0;
	else 
		return 1+max(height(t->left),height(t->right));
}

int max(int a,int b) {
	return a>b ? a:b ;
}

int numNodi(BTree b) {
	int count=1;
	if(isEmptyTree(b)) 
		return 0;
	
	else {
		if(!isEmptyTree(b->left))
			count += numNodi(b->left);
		if(!isEmptyTree(b->right))
			count += numNodi(b->right);
		return count;
	}
}

int ricercaEl(BTree t,Item e) {
	if(isEmptyTree(t))
		return 0;
	else {
		if(t->value == 0)
			return 1;
	
	else {
		if(ricercaEl(t->left,e)) 
			return 1;
		else 
			return ricercaEl(t->right,e);
		}
	}
}

int conta_el(BTree t,Item i) {
	if(isEmptyTree(t)) {
		return 0;
	}else {
		if(cmpItem(t->value,i)==0) { 
			return 1+conta_el(t->left,i) +conta_el(t->right,i);
		}else {
			return conta_el(t->left,i)+conta_el(t->right,i);
		}
	}
}

void preOrderIter(BTree t) {
	BTree left,right;
	Stack s = newStack();
	push(s,t);
	
	while(!isEmptyStack(s)) {
		BTree node = top(s);
		outputItem(node->value);
		pop(s);
		if((right=getRight(node))!=NULL)
			push(s,right);
		if((left=getLeft(node))!=NULL)
			push(s,left);
	}
}

void postOrderIter(BTree t) {
	BTree last,curr;
	curr = t;
	last = NULL;
	Stack s = newStack();
	
	while(!isEmptyStack(s) || curr) {
		if(curr) {
			push(s,curr);
			curr = getLeft(curr);
		} else {
			curr = top(s);
			if(getRight(curr) && last!=getRight(curr)) {
				curr=getRight(curr);
			}
			else {
				last=curr;
				outputItem(curr->value);
				pop(s);
				curr=NULL;
			}
		}
	}
}

void inOrderIter(BTree t) {
	BTree curr;
	curr = t;
	Stack s = newStack();
	
	while(!isEmptyStack(s) || curr) {
		if(curr) {
			push(s,curr);
			curr=getLeft(curr);
		} else {
			curr=top(s);
			pop(s);
			outputItem(curr->value);
			curr=getRight(curr);
		}
	}
}

/*List funzione(BTree t, Item i) {
	List list = newList();
	Stack s = newStack();
	push(s,t);
	
	while(!isEmptyStack(s)) {
		BTree node = pop(stack);
		if(!isEmptyTree(temp->right))
			push(s,temp->right);
		if(!isEmptyTree(temp->left))
			push(s,temp->left);
		if(cmpItem(getBTreeRoot(temp),k)<0)
			addListTail(list,getBTreeRoot(temp));
	}
}*/
			
			

	
	
	
	