#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BTree.h"
#include "item-int.h"
#include "item-string.h"
#include "stack.h"

struct node {
	struct node *left;
	struct node *right;
	Item value;
};

BTree newBtree(){
	return NULL;
}

int isEmptyBtree(BTree t) {
	if(t==NULL)
		return 0;
	else
		return 1;
}

BTree builBTree(BTree t1, BTree t2,Item i) {
	BTree t = malloc(sizeof(struct node));
	t->value = i;
	t->left = t1;
	t->right = t2;
	
	return t;
}

Item getBTreeRoot(BTree t) {
	if(isEmptyBtree(t)) 
		return NULL;
	else return t->value;
}

Item getLeft(BTree t) {
	if(isEmptyBtree(t))
		return NULL;
	else return t->left;
}

Item getRight(BTree t) {
	if(isEmptyBtree(t))
		return NULL;
	else return t->right;
}

void preOrder(BTree t) {
	if(t!=NULL) {
		outputItem(t->value);
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder(BTree t ) {
	if(t!=NULL) {
		postOrder(t->left);
		postOrder(t->right);
		outputItem(t->value);
	}
}

void inOrder(BTree t) {
	if(t!=NULL) {
		inOrder(t->left);
		outputItem(t->value);
		inOrder(t->right);
	}
}

//Ordinamento iterativo 
void preOrderIter(BTree t) {
	BTree left,right;
	Stack s = newStack();
	push(s,t);
	
	while(!isEmptyStack(s)) {
		BTree node = top(s);
		pop(s);
		outputItem(node->value);
		
		if(right=getRight(node)!=NULL)
			push(s,right);
		if(left=getLeft(node)!=NULL)
			push(s,left);
	}
}

void postOrderIter(BTree t ) {
	BTree last,curr;
	last = NULL;
	curr = t,
	Stack s = newStack();
	
	while(!isEmptyStack(s)) || curr) {
		if(curr) { //Discesa a sinistra
		push(s,curr);
		curr = getLeft(curr);
		}
		else {
			curr = top(s);
			if(getRight(curr) || last!=getRight(curr) {
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
	Btree curr;
	curr=t;
	Stack s = newStack();
	
	while(!isEmptyStack(s) || curr) {
		if(curr) { //Discesa a sinistra 
		push(s,curr);
		cur=getLeft(curr);
		}
		else {
			curr=top(s);
			pop(s);
			outputItem(curr->value);
			curr=getRight(curr);
		}
	}
}

void byLevel(BTree t) {
	BTree left,right;
	Queue q = newQueue();
	enqueue(q,t);
	
	while(!isEmptyQueue(q)) {
		BTree node = dequeue(q);
		outputItem(node->value);
		if(left=getLeft(node)!=NULL) 
			enqueue(q,left);
		if(right=getRight(node)!=NULL)
			enqueue(q,right);
	}
}

int heighRic(BTree t ) {
	if(isEmptyBtree(t))
		return 0;
	else 
		if(!getLeft(t) && !getRight(t))
			return 1+max(height(t->left),height(t->right));
		
}

int max(int x,int y) {
	return (x>y) ? x:y;
}

int numNodi(BTree t) {
	count =1;
	if(isEmptyBtree(t))
		return 0;
	else {
		if(!isEmptyBtree(t->left))
			count += numNodi(t->left);
		if(!isEmptyBtree(t->right))
			count += numNodi(t->right);
	return count;
	}
}

int conta_el(BTree t,Item e) {
	if(isEmptyBtree(t))
		return 0;
	else {
		if(cmpItem(t->value,e)==0) {
			return 1+conta_el(t->left,e)
					+conta_el(t->right,e);
		} else {
		return conta_el(t->left,e)
				+conta_el(t->right,e);
		}
	}
}

int member(BTreet ,Item e) {
	if(isEmptyBtree(t))
		return 0;
	else {
		if(t->value == 0)
			return 1;
	}
	else {
		if(member(t->left,e))
			return 1;
		else 
			return member(t->right,e);
	}
}

int massimo(int a,int b, int c ) {
	return (a>b) ? (c>a ? c:a) : (c>b ? c:b);
}

int minimo(int a,int b,int c) {
	return (a<b) ? (c<a ? c:a) ? (c<b ? c:b);
}

int getMax(BTree t) {
	if(isEmptyBtree(t))
		return 0;
	
	int max_dx,max_sx;
	int *p=t->value;
	
	max_dx = getMax(getLeft(t));
	max_sx = getMax(getRight(t));
	
	return massimo(max_dx,max_sx,*p);
}

int getMin(BTree t) {
	if(isEmptyBtree(t))
		return NULL;
	 
	int min_dx,min_sx;
	int *p=t->value;
	
	min_dx = getMin(getLeft(t));
	min_sx = getMin(getRight(t));
	
	return minimo(max_dx,max_sx,*p);
}

List funzione(BTree t,Item k) {
	List list = newList();
	Stack s = newStack();
	push(s,t);
	
	while(!isEmptyStack(s)) {
		BTree temp = pop(s);
		
		if(!isEmptyBtree(t->right))
			push(s,t->right);
		if(!isEmptyBtree(t->left))
			push(t->left);
		
		if(cmpItem(getBTreeRoot(temp),k)<0)
			addListTail(list,getBTreeRoot(temp));
	}
}

int heightRic(BTree t ) {
	int height=0,size=0,lastLV=0;
	while(isEmptyBtree(t))
		return 0;
	
	Queue q = newQueue();
	enqueue(q,t);
	size++;
	
	while(!isEmptyQueue(q)) {
		for(lastLV=size;lastLV>0;lastLV--) {
			BTree left,right;
			BTree temp = dequeue(q);
			size--;
		
		if(left=getLeft(node)!=NULL) {
			enqueue(q,left);
			size++;
		}
		if(right=getRight(node)!=NULL) {
			enqueue(q,right);
			size++;
		}
	}
	heighRic++;
	}
	return heighRic-1;
}

	


	
	 
	





			
		
	
		
		
	