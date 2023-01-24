#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

int minimo(int x,int y);
void mergeSortIter(int *arr,int n);
void merge(int array[], int l,int m,int r );
void outputArray(int *a, int n);
void mergeSortRic(int *a,int l ,int n );
void inputArray(int *a,int n);

int main() {
	int a[N];
	inputArray(a,N);
	mergeSortIter(a,N);
	//mergeSortRic(a,0,N-1);
	outputArray(a,N);
}

void inputArray(int *a,int n){
	int i;
	for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
}

void outputArray(int *a, int n){
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

int minimo(int x,int y) {
	return (x<y) ? x:y;
}

void mergeSortIter(int *arr,int n) {
	int curr_size;
	int left_start;
	
	for(curr_size=1;curr_size<n-1;curr_size=2*curr_size) {
		for(left_start=0;left_start<n-1;left_start+=2*curr_size) { 
			int left_and = minimo(left_start+curr_size-1,n-1);
			int right_and = minimo(left_start+2*(curr_size-1),n-1);
			
			merge(arr,left_start,left_and,right_and);
		}
	}
}

void merge(int array[], int l,int m,int r ) {
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1],R[n2];
	
	for(i=0;i<n1;i++) 
		L[i]=array[l+i];
	
	for(j=0;j<n2;j++) 
		R[j]=array[m+1+j];
	
	i=0;
	j=0;
	k=l;
	
	while(i<n1 && j<n2) {
		if(L[i]<=R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1) {
		array[k]=L[i];
		i++;
		k++;
	}
	while(j<n2) {
		array[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortRic(int *a,int l ,int n ) {
	if(l<n) {
		int m = l+(n-l)/2;
		mergeSortRic(a,l,m);
		mergeSortRic(a,m+1,n);
		merge(a,l,m,n);
	}
}
	
	
	
	
