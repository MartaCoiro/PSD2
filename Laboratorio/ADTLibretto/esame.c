#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "list.h"
#include "esame.h"

struct esame{
	char *materia;
	char *data;
	int  voto;
};

Esame initEsame(char *materia, char *data, int voto){
	Esame s = malloc(sizeof(struct esame));
	s->materia = strdup(materia);
	s->data = strdup(data);
	if((voto>=18)&&(voto<=30))
		s->voto = voto;
	else if(voto==31){
		s->voto=30;
		printf("30 e lode\n");
		}
		else {s->voto=0;
			printf("esame non superato\n");
		}
	return s;
}
char* materia(Esame s){
	char *materia = malloc(sizeof(char) * (1+strlen(s->materia)));
	strcpy(materia, s->materia);
	return materia;
}

char* data(Esame s){
	char *data = malloc(sizeof(char) * (1+strlen(s->data)));
	strcpy(data, s->data);
	return data;
}

int voto(Esame s){
	return s->voto;
}
