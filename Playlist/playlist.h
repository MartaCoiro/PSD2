#include "song.h"
#include "item-song.h"

typedef struct playlist *Playlist;

Playlist creaPlaylist(char *nome);
void addCanzone(Playlist , Song );
void removeCanzone(Playlist , char *);
void sortPlaylist(Playlist );
void printPlaylist(Playlist );
Song searchCanzone(Playlist, Item );

