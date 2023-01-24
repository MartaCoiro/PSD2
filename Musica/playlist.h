#include "item.h"
#include "songs.h"

typedef struct playlist *Playlist;

Playlist creaPlaylist(char *nome);
void addSong(Playlist p, Song s);
void sortSong(Playlist p);
void printPlaylist(Playlist p);
