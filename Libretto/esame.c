#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "esame.h"
#include "list.h"


struct esame {
	char *materia;
	char *data;
	int voto;
};

Esame creaEsame(char *materia, char * data, int voto) {
	Esame esame = malloc(sizeof(struct esame));
	esame->materia = strdup(materia);
	esame->data = strdup(data);
	if(voto>=18 || voto<=31) {
		esame->voto=voto;
	} else {
		if(voto<18) 
		printf("Esame non superato");
	}
	return esame;
}

char *materia(Esame esame) {
	char *materia = malloc(sizeof(char) * (1+strlen(esame->materia)));
	strcpy(materia,esame->materia);
	return materia;
}

char *data(Esame esame) {
	char *data = malloc(sizeof(char) *(1+strlen(esame->data)));
	strcpy(data,esame->data);
	return data;
}

int voto(Esame esame) {
	return esame->voto;
}