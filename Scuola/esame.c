#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"
#include "esame.h"
#include "item.h"
#include "list.h"
#include "utils.h"

Esame creaEsame(char *nome,char *data,int voto) {
	Esame e = malloc(sizeof(struct esame));
	e->nome = strdup(nome);
	e->data = strdup(data);
	if((voto>= 18 ) && (voto<=30))
		e->voto = voto;
	else if(voto == 31) {
		e->voto = 30;
		printf("30 e lode");
		else if(voto == 0) 
			printf("Bocciato");
	
	}
	
	return e;
}

char *nome(Esame e) {
	char *nome = malloc(sizeof(char) * (1+strlen(e->nome));
	strcpy(nome,e->nome);
	return nome;
}

char *data(Esame e) {
	char *data = malloc(sizeof(char) * (1+strlen(e->data));
	strcpy(data,e->data);
	return data;
}

int voto(Esame e) {
	return e->voto;
}