#include <stdio.h>
#include "item.h"
#include "list.h"
#include "entry.h"
#include "hashtable.h"
#include "key.h"


int main(){
	HashTable h = newHashtable(5);
	int i;
	for(i=0; i<3;i++){
		printf("Inserisci un nome: ");
		Key k = inputKey();
		printf("Inserisci l'eta': ");
		Item e = inputItem();
		Entry entry = newEntry(k, e);
		insertHash(h, entry);
	}
	printf("Inserisci un nome da cercare: ");
	Key k = inputKey();
	Entry temp = searchHash(h, k);
	if(temp != NULL){
		Item e = getValue(temp);
		printf("La sua eta' e': ");
		outputItem(e);
	}
	else
		printf("Non e' presente\n");
	return 0;
}