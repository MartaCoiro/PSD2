#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libretto.h"
#include "esame.h"
#include "list.h"


struct libretto{
	char *nome;
	char *cognome;
	int matricola;
	List esami;
};

Libretto creaLibretto(char *nome, char *cognome, int matricola) {
	Libretto libretto = malloc(sizeof(struct libretto));
	libretto->nome= strdup(nome);
	libretto->cognome = strdup(cognome);
	libretto->matricola = matricola;
	libretto->esami = newList();
	return libretto;
}

void addEsame(Libretto libretto, Esame esame) {
	addHead(libretto->esami,esame);
}

void sortLibretto(Libretto libretto){
	selectionSortList(libretto->esami);
}

void printLibretto(Libretto libretto) {
	printf("\nNome studente: %s \n",libretto->nome);
	printf("\nCognome studente: %s \n",libretto->cognome);
	printf("\nMatricola studente: %d \n",libretto->matricola);
	printList(libretto->esami);
}

Esame searchMateria(Libretto p, Item item){
	int pos;
	return searchList(p->esami,item,&pos);
}

	