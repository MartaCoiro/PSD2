#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playlist.h"
#include "list.h"
#include "song.h"

//Definiamo la struttura playlist 
struct playlist{
	char *name;
	List songs;
};


Playlist createPlaylist(char* name){
	Playlist p = malloc(sizeof(struct playlist));
	p->name = strdup(name);//strdup restituisce un puntatore a una copia del buffer name
	p->songs = newList();
	return p;
}

void addSong(Playlist p, Song s){
	addHead(p->songs, s);
}

void removeSong(Playlist p, char *title){
	Song s = initSong(title, "", 0);
	removeListItem(p->songs, s);
}

void sortPlaylist(Playlist p){
	selectionSortList(p->songs);
}

void printPlaylist(Playlist p){
	printf("Playlist: %s", p->name);
	printList(p->songs);
}
