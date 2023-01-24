void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int conta_spazi(char *a) {
	int count=0, i;
	for(i=0; a[i]!='\0'; i++) {
		if(a[i]==' ')
			count++;
	}
	
	return count;
}