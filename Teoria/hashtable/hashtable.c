#include <stdlib.h>
#include "hashtable.h"
#include "list.h"
#include "entry.h"
#include "key.h"

#define N 20

struct hashtable{
	int size;
	List *entries;
};

HashTable newHashtable(int size){
	int i;
	HashTable new = malloc(sizeof(struct hashtable));
	new->size = size;
	new->entries = malloc(sizeof(List) * size);
	for(i=0; i<size; i++)
		new->entries[i] = newList();
	return new;
}

int insertHash(HashTable h, Entry e){
	int indice = hashValue(getKey(e), h->size);
	addHead(h->entries[indice], e);
	return 1;
}

Entry searchHash(HashTable h, Key k){
	int indice = hashValue(k, h->size);
	int pos;
	Entry e = newEntry(k, NULL);
	return searchList(h->entries[indice], e, &pos);
}

Entry deleteHash(HashTable h, Key k){
	int indice = hashValue(k, h->size);
	Entry e = newEntry(k, NULL);
	return removeListItem(h->entries[indice], e);
}
