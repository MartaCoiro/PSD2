#include "esame.h"
#include "item.h"

typedef struct libretto *Libretto;

Libretto creaLibretto(char *nome, char *cognome, int matricola);
void addEsame(Libretto,Esame);
void sortLibretto(Libretto);
void printLibretto(Libretto);
Esame searchMateria(Libretto, Item item);