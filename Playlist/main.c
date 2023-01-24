#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "song.h"
#include "playlist.h"
#define MAX 100

int main() {
	int i, n=2;
	char *nomePlaylist = "Estate";
	char titolo[MAX];
	Song so;
	
	/*dichiarazione liste*/
	
	Playlist playlist = creaPlaylist(nomePlaylist);
	Song song;
	
	/*riempire lista canzoni*/
	
	for(i=0;i<n;i++){
		printf("\nInserisci canzone:");
		song = inputItem();	/*riempio*/
		addCanzone(playlist, song);	
	}
	
	/*riordinare le playlist in ordine alfabetico*/
		
	sortPlaylist(playlist);
	
	//printf("\nEcco la tua playlist--->");
	printPlaylist(playlist);
	
	//Inserisci nuova canzone da aggiungere alla lista
	printf("\nInserisci canzone:");
	song = inputItem();
	addCanzone(playlist, song);
	sortPlaylist(playlist);
	printf("\nEcco la tua playlist aggiornata --->");
	printPlaylist(playlist);
	
	//Elimina canzone dalla playlist 
	printf("\nInserisci canzone da eliminare:");
	scanf("%s", titolo);
	removeCanzone(playlist,titolo);
	sortPlaylist(playlist);
	printPlaylist(playlist);
	
	
	
	
	return 0;
}