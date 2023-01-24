#include <stdio.h>
#define LLEN 50

void outputArray(int *a, int n);
int partition(int *a, int start, int end);
void quickSort(int *a, int n);
void qSort(int *a, int start, int end);
void swap(int *a, int *b);

int main(){
    int a[]={15, 13, 10, 7, 5, 3};

  //  int value=partition(a,0,(sizeof(a)/sizeof(int))-1);
    quickSort(a,sizeof(a)/sizeof(int));
    outputArray(a, sizeof(a)/sizeof(int));
  //  printf("\nvalue: %d", value);

    return 0;
}

void outputArray(int *a, int n){
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

int partition(int *a, int start, int end){
  int pivot=a[start];
  int i=start-1;
  int j=end+1;
  while(1){
    do{
      j--;
    }while(a[j]>pivot);

    do{
      i++;
    }while(a[i]<pivot);
	//Condizione di uscita 
    if(i>=j)
      return j; //Posizione di j, punto in cui l'array risulta spezzato

    swap(&a[i],&a[j]);
  }
}

void qSort(int *a, int start, int end){
  if(start<end ){
    int q = partition(a,start,end);
    qSort(a,start,q);
    qSort(a,q+1,end);
  }
}

void quickSort(int *a, int n){
  qSort(a,0,n-1);
}

void swap(int *a, int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
