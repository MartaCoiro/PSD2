#include <stdio.h>
#include "list.h"
#include "esame.h"
#include "libretto.h"
#define MAX 100

int main() {
	int i, n=2;
	char *nome = "Marta";
	char *cognome = "Coiro";
	int matricola = 0234123470;
	char materia[MAX];
	Esame es;
	
	/*dichiarazione liste*/
	
	Libretto libretto = creaLibretto(nome,cognome,matricola);
	Esame esame;
	
	/*riempire lista esami*/
	
	for(i=0;i<n;i++){
		printf("\nInserisci esame:");
		esame = inputItem();	/*riempio*/
		addEsame(libretto, esame);	/*incorporo l'esame nella lista esami che si trova in libretto*/
	}
	
	/*riordinare gli esami in ordine alfabetico*/
		
	sortLibretto(libretto);
	
	printf("Ecco il tuo libretto:\n");
	printLibretto(libretto);
	
	/*cercare un esame*/
	
	/*printf("\nInserisci materia:\n");
	scanf("%s", materia);
	
	es=searchMateria(list,materia);
	outputItem(es);*/
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	