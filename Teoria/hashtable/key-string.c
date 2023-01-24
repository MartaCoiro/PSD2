#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key.h"
#define LEN 30

int equals(Key k1, Key k2){
	char* s1 = k1;
	char* s2 = k2;
	return (strcmp(s1, s2)==0);
}

int hashValue(Key k, int m){
	int a = 128, h = 0;
	char *s = k;
	for(; *s!='\0'; s++)
		h = (h*a + *s) % m;
	return h;
}

Key inputKey(){
	char *s;
	s = malloc(sizeof(char) * LEN);
	scanf("%s", s);
	return s;
}

void outputKey(Key k){
	char *s = k;
	printf("%s ", s);
}
