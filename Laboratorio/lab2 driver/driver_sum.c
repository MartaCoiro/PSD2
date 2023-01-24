#include<stdio.h>
#include<stdlib.h>
#include "vettore.h"

#define N 50

int main (int argc, char * argv[]){
	FILE *fp_input, *fp_oracolo, *fp_output;

	if((fp_input=fopen(argv[1], "r"))==NULL){ //viene assegnato un puntatore al file indicato in argv[]
		fprintf(stderr, "Errore apertura file di INPUT %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((fp_oracolo=fopen(argv[2], "r"))==NULL){//viene assegnato un puntatore al file indicato in argv[]
		fprintf(stderr, "Errore apertura file di ORACLE %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	if((fp_output=fopen(argv[3], "w"))==NULL){//viene assegnato un puntatore al file indicato in argv[]
		printf("Errore apertura file di OUTPUT %s\n", argv[3]);
		exit(EXIT_FAILURE);
	}

	char line[N];
	int arr_input[N], arr_oracolo[N];
    //arr_input   -> contiene una linea del file ..input.xt
    //arr_oracolo -> contiene una linea del file ..oracle.xt
    
	int n_input, n_oracolo, test, i;
    //n_input -> la dimensione di ..input.xt
    //n_oracolo -> la dimensione di ..oracle.xt
    //test è usata per esprimere il risultato del testing può assumere due valori 0 -> fallimento 1- > successo
    
	int sum_result=0; //variabile usata per il test della funzione1
    int pos; //pos contiene il numero di caratteri letti in una stringa
    
	for(i=1; fgets(line, N, fp_input)!=NULL; i++){ //La funzione fgets() legge una linea dallo stream immagazzinandola nel buffer puntato da line.
		n_input=input_array_str (arr_input, line, &pos); //input_array_str estrapola i dati dal buffer puntato da line
        output_array(arr_input, n_input);
        
        fgets(line, N, fp_oracolo);
		n_oracolo=input_array_str(arr_oracolo, line, &pos);


		/**** qui avviene il testing della funzione1: tot_array(int a[], int n) ****/
		sum_result= tot_array(arr_input,n_input); //calcola la somma degli elementi dell'array
		test=0;
		if (sum_result== *arr_oracolo){
				test= 1;
		}

		fprintf(fp_output, "Test case %d: %d\n", i, test);

	}

	fclose(fp_input);
	fclose(fp_output);
	fclose(fp_oracolo);

	return 0;

}
