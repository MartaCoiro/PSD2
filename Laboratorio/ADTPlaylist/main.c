#include <stdio.h>
#include "list.h"
#include "song.h"
#include "playlist.h"

#define MAX 100

int main(){
	int i, n = 5;
	char* name = "Rock";
	char title[MAX];
	Playlist list = createPlaylist(name);
	Song song;
	
	for(i=0; i<n; i++){
		printf("\nInsert song data:");
		song = inputItem();
		addSong(list, song);
	}
	
	printf("\nInsert title of song to remove:");
	scanf("%s", title);
	removeSong(list, title);

	sortPlaylist(list);
	printPlaylist(list);
}