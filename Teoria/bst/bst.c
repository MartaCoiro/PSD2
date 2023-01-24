#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
#include "queue.h"

struct node {
	Item value;
	struct node *left;
	struct node *right;
};

BST newBST(){
	return NULL;
}
int isEmptyBST(BST t){
	if(t==NULL)
		return 1;
	else
		return 0;
}
BST getLeft(BST t){
	if(isEmptyBST(t))
		return NULL;
	else 
		return t->left;
}
BST getRight(BST t){
	if(isEmptyBST(t))
		return NULL;
	else
		return t->right;
}
Item getItem(BST t){
	if(isEmptyBST(t))
		return NULL;
	return t->value;
}
Item search(BST t, Item e){
	if(isEmptyBST(t))
		return NULL;
	int cmp=cmpItem(e,t->value);
	if(cmp==0)
		return t->value;
	else if(cmp<0)
		return search(t->left,e);
	else if(cmp>0)
		return search(t->right,e);	
}
Item min(BST t){
	if(isEmptyBST(t))
		return NULL;
	if(t->left != NULL)
		return min(t->left);
	else 
		return t->value;
}
Item max(BST t){
	if(isEmptyBST(t))
		return NULL;
	if(t->right != NULL)
		return max(t->right);
	else 
		return t->value;
}
void insertBST(BST * t, Item e){
	if(isEmptyBST(*t)){
		*t=malloc(sizeof(struct node));
		//Inizializzamo i campi
		(*t)->value=e; //Agganciamo l'item da inserire nel campo value
		(*t)->left=NULL;
		(*t)->right=NULL;
	}
	int value;
	if(value<0)
		insertBST(&((*t)->left),e); //Li passiamo per riferimento con &
	else if(value>0)
		insertBST(&((*t)->right),e);
}

Item deleteBST(BST *t, Item e){//Passiamo un BST per riferimento perchè la cancellazione deve modificare questo valore
	if(isEmptyBST(*t))
		return NULL;
	int cmp=cmpItem(e,(*t)->value);
	if(cmp==0)
	{
		//Se il nodo ha al più un solo sottoalbero o quello sinistro o quello destro
		if(isEmptyBST((*t)->right)) //Manca il sottoalbero destro
		{
			BST tmp = (*t);//Salviamo il puntatore in tmp
			Item i = tmp->value; //Salviamo nell'item
			*t = (*t)->left; //Agganciamo il figlio destro
			free(tmp);
			return i;
		}
		else if(isEmptyBST((*t)->left))//Manca il sottoalbero sinistro
		{
			BST tmp = (*t);
			*t = (*t)->right;
			Item i = tmp->value;
			free(tmp);
			return i;
		}
		else
		{
			//Cerchiamo il max nel sottoalbero sinistro e lo 
			//salviamo in un Item
			Item i = max((*t)->left);
			Item r = (*t)->value;
			(*t)->value = i; //Sostituzione dell'item nel nodo corrente
			//Chiamiamo ricorsivamente la cancellazione 
			deleteBST(&((*t)->left),i);
			return r;
		}		
	}	
	else if(cmp<0)
		return deleteBST(&((*t)->left),e);
	else if(cmp>0)
		return deleteBST(&((*t)->right),e);	
}

void printPerLevel(BST t){
    if(isEmptyBST(t))
        return;

    Queue q = newQueue();

    enqueue(q,t);
    while(!isEmptyQueue(q))
    {
        BST node = dequeue(q);
        outputItem(node->value);

        if(node->left != NULL)
            enqueue(q,node->left);
        if(node->right != NULL)
            enqueue(q,node->right);
    }
} 