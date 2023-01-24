#include <stdio.h>
#define LLEN 50

void outputArray(int *a, int n);
void merge(int *a, int *b, int n1, int n2, int *c);
void mergeSort(int *a, int n);



int main(){
    int a[]={50, 4, 32, 8, 1, 16};

    mergeSort(a, sizeof(a)/sizeof(int));
    outputArray(a, sizeof(a)/sizeof(int));

    return 0;
}

void outputArray(int *a, int n){
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

void merge(int *a, int *b, int n1, int n2, int *c){
    int i, j, k=0;
    int z[n1+n2];

    for(i=0, j=0; i<n1 && j<n2; k++){
        if(a[i]<=b[j]){
            z[k]=a[i];
            i++;
        }else{
            z[k]=b[j];
            j++;
        }
    }

    for(; i<n1; i++, k++)
        z[k]=a[i];

    for(; j<n2; j++, k++)
        z[k]=b[j];

    for(k=0; k<n1+n2; k++)
        c[k]=z[k];

}

void mergeSort(int *a, int n){
    if(n>1){
        mergeSort(a, n/2);
        mergeSort(a+n/2, n-n/2);
        merge(a, a+n/2, n/2, n-n/2, a);
    }
	
	