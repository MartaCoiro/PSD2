typedef struct song *Song;

Song nuovaCanzone(char *titolo, char *nome_cantante, int durata);
char *titolo(Song );
char *nome_cantante(Song );
int durata(Song );