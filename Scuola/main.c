#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"
#include "esame.h"
#include "item.h"
#include "list.h"
#include "utils.h"
#define MAX 100

int main() {
	char nome = "Libretto1";
	int i,n=2;
	
	
	Libretto libretto =  creaLibretto(nome);
	Esame esame;
	
	for(i=0;i<n;i++) {
		printf("Inserisci materia");
		esame = inputItem();
		addEsame(libretto,esame);
	}
	
	sortEsame(libretto);
	printLibretto(libretto);
	
	return 0;
}
		
		
	