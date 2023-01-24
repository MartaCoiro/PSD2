#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"

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
