#include <stdio.h>
#include "point.h"

int main(){
	
	float a,b,sx,sy,dist,c;
	Point p1,p2;
	int n;
	
	printf("Inserisci dimensione:\n");
	scanf("%d",&n);
	
	p1=createPoint(2.0,3.0,n);
	p2=createPoint(3.0,6.0,n);
	
   printf("Inserisci elemento per ascissa:\n");
   scanf("%f",&a);
   
   printf("Inserisci elemento per ordinata:\n");
   scanf("%f",&b);
   
   sx=spostamento(p1,a);
   sy=spostamento(p2,b);
   
   printf("Lo spostamento dei punti e':\n");
   printf("%.1f %.1f",sx,sy);
   
   dist=distanza(p1,p2);
   c=centroide(dist,n+n);
   printf("Il centroide e' : %.1f",c);
   return 0;
}