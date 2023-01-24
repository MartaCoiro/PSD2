#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "songs.h"
#include "utils.h"
#include "item.h"
#include "list.h"
#define MAX 100

int main() {
	char *nome = "Estate";
	int n=2,i;

	Playlist playlist = creaPlaylist(nome);
	Song song;
	
	//Riempio la playlist
	for(i=0;i<n;i++) {
		printf("Inserisci canzone \n");
		song = inputItem();
		addSong(playlist,song);
	}
	
	sortSong(playlist);
	printPlaylist(playlist);
	
	
	return 0;
}