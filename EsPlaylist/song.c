#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "song.h"


struct song {
	char *title;
	char *artist;
	int duration;
};

Song creaSong(char *title, char *artist, int duration) {
	Song song = malloc(sizeof(struct song));
	song->title= strdup(title);
	song->artist = strdup(artist);
	song->duration = duration;
	
	return song;
	
}

char *title(Song s) {
	char *title = malloc(sizeof(char) *(1+strlen(s->title)));
	strcpy(title,s->title);
	return title;
	
}

char *artist(Song s) {
	char *artist = malloc(sizeof(char) *(1+strlen(s->artist)));
	strcpy(artist,s->artist);
	return artist;
	
}

int duration(Song s) {
	return s->duration;
	
}

	