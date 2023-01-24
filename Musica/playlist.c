#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "list.h"
#include "songs.h"

struct playlist{
	char *nome;
	List songs;
};

Playlist creaPlaylist(char *nome) {
	Playlist p = malloc(sizeof(struct playlist));
	p->nome = strdup(nome);
	p->songs = newList();
	return p;
}

void sortSong(Playlist p) {
	selectionSortList(p->songs);
}

void addSong(Playlist p,Song s) {
	addHead(p->songs,s);
}

void printPlaylist(Playlist p) {
	printf("La tua playlist e' %s\n",p->nome);
	printList(p->songs);
	
}

