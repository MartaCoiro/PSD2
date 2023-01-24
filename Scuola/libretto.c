#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"
#include "esame.h"
#include "item.h"
#include "list.h"
#include "utils.h"


struct libretto {
	char *nome;
	char * cognome;
	int matricola;
	List esami;
}

Libretto creaLibretto(char *nome,char * cognome, int matricola){
	Libretto l = malloc(sizeof(struct libretto));
	l->nome = strdup(nome);
	l->cognome = strdup(cognome);
	l->matricola = matricola;
	return l;
	
	
}


void addEsame(Libretto l,Esame e){
	addHead(l->esami,e);
	
}



void sortEsame(Libretto l){
	selectionSortList(l->esami);
	
}

void printEsami(Libretto l) {
	printf("Nome studente: %s\n",l->nome);
	printf("Cognome studente: %s\n",l->cognome);
	printf("Matricola studente: %d\n",l->matricola);
	printList(l->esami);
}

