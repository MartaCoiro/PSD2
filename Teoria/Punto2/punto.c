#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct punto {
	float x;
	float y;
};

Punto creaPunto(float x, float y) {
	Punto p = malloc(sizeof( struct punto)); //Struct perchè ci serve lo spazio della struttura
	p->x = x;  //Accediamo ai campi e inizializziamo ii valori dei campi
	p->y = y; //Utilizziamo la notazione freccia e non la notazione punto
	
	return p; //Ritorniamo il punto appena creato
	
}

float ascissa(Punto p) {
	return p->x;
}


float ordinata(Punto p){
	return p->y;
}


float distanza(Punto p1,Punto p2){
	float dx,dy;
	
	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	
	return sqrt(dx*dx + dy*dy);
	
}