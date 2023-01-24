typedef struct libretto *Libretto;

Libretto creaLibretto(char *nome,char * cognome, int matricola);
void addEsame(Libretto l,Esame e);
void sortEsame(Libretto l);
void printLibretto(Libretto l);