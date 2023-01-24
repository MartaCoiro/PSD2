#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "key.h"
#include "entry.h"


int cmpItem(Item i1,Item i2){
	Entry e1 = i1;
	Entry e2 = i2;
	int b = equals(getKey(e1), getKey(e2));
	return !b;
}