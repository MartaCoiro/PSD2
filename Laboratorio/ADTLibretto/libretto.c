#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libretto.h"
#include "list.h"
#include "esame.h"

struct libretto{
	char* nome;
	char* cognome;
	int matricola;
	List esami;
};

Libretto createLibretto(char* nome,char* cognome,int matricola){
	Libretto p = malloc(sizeof(struct libretto));
	p->nome = strdup(nome);//strdup restituisce un puntatore a una copia del buffer name
	p->cognome = strdup(cognome);
	p->matricola = matricola;
	p->esami = newList();
	return p;
}

void addEsame(Libretto p, Esame s){
	addHead(p->esami, s);
}

void sortLibretto(Libretto p){
	selectionSortList(p->esami);
}

void printLibretto(Libretto p){
	printf("Nome studente: %s\n", p->nome);
	printf("Cognome studente: %s\n", p->cognome);
	printf("Matricola studente: %d\n", p->matricola);
	printList(p->esami);
}

Esame searchMateria(Libretto p, Item item){
	int pos;
	return searchList(p->esami,item,&pos);
}