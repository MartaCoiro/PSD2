typedef struct esame *Esame;

Esame creaEsame(char *nome,char *data,int voto);
char *nome(Esame e);
int voto(Esame e);
char *data(Esame e);
