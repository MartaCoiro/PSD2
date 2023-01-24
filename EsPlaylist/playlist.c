#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "playlist.h"
#include "song.h"


struct playlist {
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

void printPlaylist(Playlist p ) {
	printf("Ecco la tua playlist:%s\n",p->nome);
	printList(p->songs);
}
	