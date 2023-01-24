#include <stdio.h>
#include "list.h"
#include "esame.h"
#include "libretto.h"
#define MAX 100

int main(){
	int i, n = 2;
	char* nome = "Katia";
	char* cognome = "Buonocore";
	int matricola = 0234710245;
	char materia[MAX];
	Esame b;
	
	/*dichiarazione liste*/
	
	Libretto list = createLibretto(nome,cognome,matricola);
	Esame esame;
	
	/*riempire lista esami*/
	
	for(i=0;i<n;i++){
		printf("\nInserisci esame:");
		esame = inputItem();	/*riempio*/
		addEsame(list, esame);	/*incorporo l'esame nella lista esami che si trova in libretto*/
	}
	
	/*riordinare gli esami in ordine alfabetico*/
		
	sortLibretto(list);
	
	printf("stampa:\n");
	printLibretto(list);
	
	/*cercare un esame*/
	
	printf("\ninserisci materia:\n");
	scanf("%s", materia);
	
	b=searchMateria(list,materia);
	outputItem(b);
	
	return 0;
}