#include "song.h"
#include "item.h"

typedef struct playlist *Playlist;

Playlist creaPlaylist(char *nome);
void sortSong(Playlist p);
void printPlaylist(Playlist p );
void addSong(Playlist p,Song s);