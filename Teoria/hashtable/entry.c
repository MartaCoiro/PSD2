#include <stdlib.h>
#include "entry.h"
#include "key.h"
#include "item.h"

struct entry{
	Key key;
	Item value;
};

Entry newEntry(Key k, Item i){
	Entry new = malloc(sizeof(struct entry));
	new->key = k;
	new->value = i;
	return new;
}

Key getKey(Entry e){
	if(e==NULL) return NULL;
	return e->key;
}

Item getValue(Entry e){
	if(e==NULL) return NULL;
	return e->value;
}