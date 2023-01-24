#include "item.h"

void input_array(Item *a, int n);
void output_array(Item *a, int n);
void bubbleSort(Item *arr, int n);

//Andiamo a cambiare gli int in Item per rendere generico il codice, 
//quindi questo codice funziona sugli Item e non sugli interi