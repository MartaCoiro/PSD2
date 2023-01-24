#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define CARD 100

Item inputItem(){
    char *a=malloc(sizeof(char)*CARD);
    scanf("%s",a);
    return a;
}

void outputItem(Item item){
    char *a=item;
    printf("%s ",a);
}

int cmpItem(Item item1,Item item2){
    char *a=item1;
    char *b=item2;
    return strcmp(a,b); 
}