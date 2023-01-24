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
	int arr_input[N], arr_input2[N], arr_oracolo[N];
	int n_input, n_input2, n_oracolo, test, i;
	int sum_result=0; //variabile usata per il test della funzione1
    int pos;
	for(i=1; fgets(line, N, fp_input)!=NULL; i++){ //La funzione fgets() legge una linea dallo stream immagazzinandola nel buffer puntato da line.
        
        n_input=input_array_str (arr_input, line, &pos);   //input_array_str estrapola i dati dal buffer puntato da line
        output_array(arr_input, n_input);
        n_input2=input_array_str (arr_input2, line+pos, &pos);
        output_array(arr_input2, n_input2);
    
        fgets(line, N, fp_oracolo);
		n_oracolo=input_array_str(arr_oracolo, line, &pos);

		//qui avviene il testing della funzione2
        i_sum(arr_input, arr_input2, n_input, n_input2); //il risultato è salvato in arr_input

        test = compare_arrays(arr_input, arr_oracolo, n_input, n_oracolo);
            //confronta vettore in input.txt e oracolo.txt
        fprintf(fp_output, "Test case %d: %d\n", i, test);
            //scrive il risultato sul file di output
        }


	fclose(fp_input);
	fclose(fp_output);
	fclose(fp_oracolo);

	return 0;
}
