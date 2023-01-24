#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "utils.h"

struct list {
	int size;
	struct node *head;
};

struct node {
	Item item; /
	
	/Oppure value
	struct node *next;
	
};

List newList() {
    List list = malloc(sizeof(struct list)); //Allochiamo lo spazio necessario per la struttura lista
    //Creiamo una lista vuota
	list->size=0;
    list->head=NULL;
    return list;
}

int isEmpty(List list) {
	//Controlliamo se la lista è vuota o con head = null oppure la size =0
	//isEmpty è vero quando la lista è vuota
    return (list->size==0);
    //return (list->head==NULL);
}

void addHead(List list, Item item) {
    struct node *new_node = malloc(sizeof(struct node));
	//Aggancio l'item al nuovo nodo
    new_node->item=item;
    new_node->next=list->head;
	//Aggiorniamo la nuova head
    list->head=new_node;
    ++(list->size);
}

Item removeHead(List list) {
    if (isEmpty(list)) 
		return NULL; 
    struct node *temp_node = list->head;
    list->head=temp_node->next; //Agganciamo la testa al nodo successivo
    Item item=temp_node->item; //Prima di essere eliminato il nodo lo salviamo e alla fine lo restituiamo
    free(temp_node);
    --(list->size); // Decrementiamo la size 
    return item;
}

Item getHead(List list){
    if (isEmpty(list)) return NULL;
    return list->head->item;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    struct node *p;
    for (p=list->head;p!=NULL;p=p->next) 
        outputItem(p->item);
}

Item searchList(List list, Item item, int *pos){ //Restituisce l'item trovato perchè operiamo su dati strutturati
	struct node *p;
	for(*pos=0,p=list->head;p != NULL; p=p->next){ //Scorriamo la lista 
		if(cmpItem(item,p->item)==0){ //Facciamo una cmpItem nell'If in modo che quando lo troviamo lo restituiamo
			return p->item;
		}
		(*pos)++;
	}
	*pos=-1;
	return NULL;
}

Item removeListItem(List list, Item item){
	struct node *p, *q; // q si ferma al nodo precedente a quello da eliminare
	Item a;
	if(isEmpty(list)){ //Controlliamo se la lista è vuota
		fprintf(stderr,"lista vuota \n");
		return NULL;
	}
	for(p=list->head; p != NULL; q=p,p=p->next){ //Scorriamo la lista e inseriamo anche il nodo q(vedi spiegazione sopra)
		if(cmpItem(item,p->item)==0){ //In questo modo ci accertiamo che siamo sul nodo da eliminare
			if(p==list->head) //Vediamo se stiamo cancellando il primo elemento ossia il nodo di testa, se lo facciamo dobbiamo aggiornare il puntatore alla testa
				return removeHead(list);
			else{
				q->next=p->next; //Aggiorniamo q facendolo puntare al successivo di p
				a=p->item; //Prima di liberare la memoria salviamo l'item contenuto in p
				free(p);
				(list->size)--; //Decrementiamo la size
				return a; //Ritorniamo l'item
			}
		}
	}
	return NULL;
}

Item removeListPos(List list, int pos){
	struct node *p, *q;
	Item a;
	int i=0; //Variabile contatore che porta p sull'item da eliminare
	if(isEmpty(list)){
		fprintf(stderr,"lista vuota \n");
		return NULL;
	}
	for(i=0,p=list->head; p != NULL; q=p,p=p->next, i++){
		if(i==pos){
			if(p==list->head)
				return removeHead(list);
			else{
				q->next=p->next;
				a=p->item;
				free(p);
				(list->size)--;
				return a;
			}
		}
	}
	return NULL;
}

/*int addListItem(List l, Item i, int pos){ //Inserimento in un punto qualunque della lista
	if(pos<0 || pos> l->size){ //Controlliamo la posizione 
		fprintf(stderr,"posizione non valida");
		return 0;
	}

	//Controlliamo l'inserimento in testa e procediamo con l'eliminazione
	if(pos==0){
		addHead(l,i);
		return 1;
	}
	
	int nodo=0;
	struct node *p;
	
	for(p = l->head; nodo<pos-1; p = p->next, nodo++)
		;
	//Gestiamo il caso generale 
	struct node *newNode=malloc(sizeof(struct node)); //creiamo un nuovo nodo
	newNode->next = p->next; //Lo agganciamo al successivo di n
	newNode->i=Item; //Ci mettiamo l'item all'interno
	p->next = newNode; //Agganciamo n al nuovo nodo
	
	(l->size)++;
	
	return 1;
	
	}*/
	
	int addListItem(List list, Item item, int pos) //INserimento in un punto qualunque della lista
{
	if(pos<0 || pos>list->size) 
		return 0;
	if(pos==0)
	{
		addHead(list, item);
		return 1;
	}
		
	struct node *p, *new;
	int conta=0;
	for(p=list->head; p!=NULL && conta<pos-1 ;p=p->next, conta++)
		;
	new=malloc(sizeof(struct node));
	new->item=item;
	new->next=p->next;
	p->next=new;
	list->size++;

	return 1;
}

int addListTail(List l, Item i){ //Inserimento alla fine
	return addListItem(l, i , l->size);
}

void reverseList(List list)
{
	struct node *prev=NULL;
	struct node *p;
	struct node *temp;
	for(p=list->head;p;prev=p,p=temp)
	{
		temp= p->next; //Salviamo il successivo di p in un nodo temporaneo
		p->next=prev; //Aggiorniamo il puntatore e lo facciamo puntare a prev
	}
	list->head=prev; //Riassegniamo la testa a prev
}

List cloneList(List list)
{
	List clone= newList();
	struct node *p;
	for (p = list -> head; p; p = p -> next)
	{
		Item item=cloneItem(p->item);
		addListTail(clone,item);
	}
	return clone;
}