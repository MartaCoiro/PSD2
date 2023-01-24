typedef struct song *Song;

Song creaSong(char *title, char *artist, int duration);
char *title(Song song);
char *artist(Song song);
int duration(Song song);
