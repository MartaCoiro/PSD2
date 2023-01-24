#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "list.h"

struct song {
	char *titolo;
	char *nome_cantante;
	int durata;
};

Song nuovaCanzone(char *titolo, char *nome_cantante, int durata) {
	Song song = malloc(sizeof(struct song));
	song->titolo= strdup(titolo);
	song->nome_cantante = strdup(nome_cantante);
	song->durata = durata;
	
	return song;
	
}

char *titolo(Song s) {
	char *titolo = malloc(sizeof(char) *(1+strlen(s->titolo)));
	strcpy(titolo,s->titolo);
	return titolo;
	
}

char *nome_cantante(Song s) {
	char *nome_cantante = malloc(sizeof(char) *(1+strlen(s->nome_cantante)));
	strcpy(nome_cantante,s->nome_cantante);
	return nome_cantante;
	
}

int durata(Song s) {
	return s->durata;
	
}

