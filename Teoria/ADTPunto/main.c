#include <stdio.h>
#include "punto.h"

int main(void){
	Punto p1,p2;
	float x,y;
	
	printf("Inserisci ascissa e ordinata del primo punto\n");
	scanf("%f %f", &x, &y);
	p1 = creaPunto(x,y);
	
	printf("Inserisci ascissa e ordinata del secondo punto\n");
	scanf("%f %f", &x, &y);
	p2 = creaPunto(x,y);
	
	printf("La distanza tra i due punti vale: %.1f",distanza(p1,p2));
	
	
	
}
	
	
	
	
	
	
	
	
	