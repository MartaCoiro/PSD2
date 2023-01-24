#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "song.h"
#include "list.h"

struct playlist{
	char *nome;
	List songs;
	
};

Playlist creaPlaylist(char *nome) {
Playlist p = malloc(sizeof(struct playlist));
p->nome=strdup(nome);
p->songs = newList();
return p;
}

void addCanzone(Playlist p, Song s) {
	addHead(p->songs,s);
}

void removeCanzone(Playlist p, char *titolo) {
	Song s = nuovaCanzone(titolo, "", 0);
	removeListItem(p->songs,s);
}

void sortPlaylist(Playlist p) {
	selectionSortList(p->songs);
}

void printPlaylist(Playlist p){
	printf("%s \n", p->nome);
	printList(p->songs);
}

Song searchCanzone(Playlist p, Item item){
	int pos;
	return searchList(p->songs,item,&pos);
}

