typedef struct esame *Esame;

Esame creaEsame(char *materia, char * data, int voto);
char *materia(Esame);
char *data(Esame);
int voto(Esame);