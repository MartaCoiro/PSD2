#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "songs.h"

struct song{
	char *titolo;
	char *cantante;
	int durata;
	
};

Song creaSong(char *titolo,char *cantante,int durata) {
	Song s = malloc(sizeof(struct song));
	s->titolo = strdup(titolo);
	s->cantante = strdup(cantante);
	s->durata = durata;
	return s;
}

char *titolo(Song s) {
	char *titolo = malloc(sizeof(char) *(1+strlen(s->titolo)));
	strcpy(titolo,s->titolo);
	return titolo;
}

char *cantante(Song s) {
	char *cantante = malloc(sizeof(char) * (1+strlen(s->cantante)));
	strcpy(cantante,s->cantante);
	return cantante;
}

int durata(Song s) {
	return s->durata;
}